package app.view;

import app.model.Database;
import app.model.Vanzemaljac;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class MainView extends HBox {
    ComboBox<String> cbKontinenti;
    CheckBox cbPronadjen;
    CheckBox cbIzgubljen;
    Button btnFiltriraj;

    TableView<Vanzemaljac> tvTabela;
    Button btnSacuvaj;

    ComboBox<String> cbDrzave;
    Button btnUpisi;
    Label lblGreska;
    public MainView(){
        super(10);
        this.setPadding(new Insets(10));
        init();
        add();
        actions();
    }
    private void init(){
        cbKontinenti = new ComboBox<>();
        cbKontinenti.getItems().add("Svi kontinenti");
        cbKontinenti.setValue("Svi kontinenti");
        cbKontinenti.getItems().addAll(Database.getInstance().getKontinenti().keySet());
        cbPronadjen = new CheckBox();
        cbIzgubljen = new CheckBox();
        btnFiltriraj = new Button("Filtriraj");

        tvTabela = new TableView<>();
        tvTabela.setItems(Database.getInstance().getVanzemaljci());
        TableColumn<Vanzemaljac,Integer> col1 = new TableColumn<>("ID");
        TableColumn<Vanzemaljac,String> col2 = new TableColumn<>("Kontinent");
        TableColumn<Vanzemaljac,String> col3 = new TableColumn<>("Drzava");

        col1.setCellValueFactory(new PropertyValueFactory<>("id"));
        col2.setCellValueFactory(new PropertyValueFactory<>("kontinent"));
        col3.setCellValueFactory(new PropertyValueFactory<>("drzava"));

        tvTabela.getColumns().addAll(col1, col2, col3);

        btnSacuvaj = new Button("Sacuvaj");

        cbDrzave = new ComboBox<>();
        cbDrzave.getItems().addAll(Database.getInstance().getSveDrzave());
        btnUpisi = new Button("Upisi");
        lblGreska = new Label("Poruka");
    }
    private void add(){
        HBox hb1 = new HBox(10);
        hb1.getChildren().addAll(new Label("Kontinent"),cbKontinenti,cbPronadjen,new Label("Pronadjen"),cbIzgubljen,new Label("Izgubljen"),btnFiltriraj);

        VBox vb1 = new VBox(10);
        vb1.setAlignment(Pos.CENTER);
        vb1.getChildren().addAll(hb1,tvTabela,btnSacuvaj);

        VBox vb2 = new VBox(10);
        vb2.setAlignment(Pos.CENTER);
        vb2.getChildren().addAll(new Label("Pronadjen:"),cbDrzave,btnUpisi,lblGreska);

        this.getChildren().addAll(vb1,vb2);
    }

    private void actions(){
        btnFiltriraj.setOnAction(e -> {
            ObservableList<Vanzemaljac> filterVanzemaljci = FXCollections.observableArrayList();
            if (cbKontinenti.getSelectionModel().isEmpty() || cbKontinenti.getSelectionModel().getSelectedItem().equals("Svi kontinenti")){
                filterVanzemaljci.addAll(Database.getInstance().getVanzemaljci());
            }
            else {
                for (Vanzemaljac v : Database.getInstance().getVanzemaljci()) {
                    if (!cbKontinenti.getSelectionModel().isEmpty() && cbKontinenti.getSelectionModel().getSelectedItem().equals(v.getKontinent())) {
                        if (cbPronadjen.selectedProperty().getValue()) {
                            if (v.isPronadjen()) filterVanzemaljci.add(v);
                        } else if (cbIzgubljen.selectedProperty().getValue()) {
                            if (!v.isPronadjen()) filterVanzemaljci.add(v);
                        } else {
                            filterVanzemaljci.add(v);
                        }
                    }
                }
            }
            tvTabela.refresh();
            tvTabela.setItems(filterVanzemaljci);

        });

        btnUpisi.setOnAction(e -> {
            Vanzemaljac selectedVanzemaljac = tvTabela.getSelectionModel().getSelectedItem();


            if (selectedVanzemaljac != null) {
                if (selectedVanzemaljac.isPronadjen()) {
                    lblGreska.setText("Vanzemaljac sa ID-jem " + selectedVanzemaljac.getId() + " je vec pronadjen");
                }
                else if(Database.getInstance().getKontinenti().get(selectedVanzemaljac.getKontinent()).contains(cbDrzave.getSelectionModel().getSelectedItem())){
                    selectedVanzemaljac.setPronadjen(true);
                    selectedVanzemaljac.setDrzava(cbDrzave.getSelectionModel().getSelectedItem());
                    tvTabela.refresh();
                    lblGreska.setText("Uspesno izvrsavanje");
                }
                else{
                    lblGreska.setText("Drzava " + cbDrzave.getSelectionModel().getSelectedItem() + " ne pripada kontinentu " + selectedVanzemaljac.getKontinent());
                }
            }
            else {
                lblGreska.setText("Nije izabran vanzemaljac");
            }
        });
        btnSacuvaj.setOnAction(e -> {
            try {
                FileWriter fileWriter = new FileWriter("regije.txt");
                Map<String,Integer> poKontinentu = new TreeMap<>(String::compareTo);
                Map<String,Integer> poDrzavi = new HashMap<>();
                for (Vanzemaljac v : Database.getInstance().getVanzemaljci()) {
                    if (v.isPronadjen()) {
                        if (poKontinentu.containsKey(v.getKontinent())) {
                            poKontinentu.put(v.getKontinent(), poKontinentu.get(v.getKontinent()) + 1);
                        }
                        else{
                            poKontinentu.put(v.getKontinent(), 1);
                        }
                        if (poDrzavi.containsKey(v.getDrzava())) {
                            poDrzavi.put(v.getDrzava(), poDrzavi.get(v.getDrzava()) + 1);
                        }
                        else{
                            poDrzavi.put(v.getDrzava(), 1);
                        }
                    }
                }
                Map<String, Integer> sortedPoDrzavi = poDrzavi.entrySet()
                        .stream()
                        .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                        .collect(Collectors.toMap(
                                Map.Entry::getKey,
                                Map.Entry::getValue,
                                (e1, e2) -> e1,
                                LinkedHashMap::new
                        ));


                for (Map.Entry<String,Integer> mp: poKontinentu.entrySet()){
                    fileWriter.write(mp.getKey() + " " + mp.getValue() + "\n");
                }
                for (Map.Entry<String,Integer> mp : sortedPoDrzavi.entrySet()){
                    fileWriter.write(mp.getKey() + " " + mp.getValue() + "\n");
                }
                fileWriter.close();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }

        });
    }
}
