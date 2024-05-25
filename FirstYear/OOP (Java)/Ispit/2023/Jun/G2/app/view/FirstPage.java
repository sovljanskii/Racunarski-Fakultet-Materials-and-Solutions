package app.view;

import app.model.Termin;
import app.model.Ucenik;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.LinkedList;

public class FirstPage extends VBox {
    private ComboBox<String> cbTermin;
    private Button btnPrikazi;
    private Button btnStatistika;
    private Button btnSnimiUkupno;
    private TableView<Ucenik> tableView;
    private TextField tfPoeni;
    private Button btnUnesi;
    private Termin termin1;
    private Termin termin2;
    public FirstPage(){
        try {
            termin1 = new Termin("/home/t0mi/Projects/OOP-JavaFX-prazan/OOP-JavaFX/src/main/java/app/OOP-Test-prvi termin.txt");
            termin2 = new Termin("/home/t0mi/Projects/OOP-JavaFX-prazan/OOP-JavaFX/src/main/java/app/OOP-Test-drugi termin.txt");
        }
        catch (Exception ex){
            ex.printStackTrace();
        }
        this.setAlignment(Pos.CENTER);
        this.setSpacing(20);
        init();
        add();
        addEvents();

    }
    private void init(){
        cbTermin = new ComboBox<>();
        cbTermin.getItems().addAll("termin1","termin2");
        btnPrikazi = new Button("Prikazi");
        btnStatistika = new Button("Statistika");
        btnSnimiUkupno = new Button("Snimi ukupno");

        tableView = new TableView<>();
        TableColumn<Ucenik,String> ime = new TableColumn<>("Ime");
        TableColumn<Ucenik,String> prezime = new TableColumn<>("Prezime");
        TableColumn<Ucenik,Float> poeniMoodle = new TableColumn<>("Poeni moodle");
        TableColumn<Ucenik,Float> poeniUML = new TableColumn<>("Poeni UML");

        ime.setCellValueFactory(new PropertyValueFactory<>("ime"));
        prezime.setCellValueFactory(new PropertyValueFactory<>("prezime"));
        poeniMoodle.setCellValueFactory(new PropertyValueFactory<>("poeniMoodle"));
        poeniUML.setCellValueFactory(new PropertyValueFactory<>("poeniUML"));
        tableView.getColumns().addAll(ime,prezime,poeniMoodle,poeniUML);

        tfPoeni = new TextField();
        btnUnesi = new Button("Unesi");
    }
    private void add(){
        HBox hbOdabir = new HBox(10);
        hbOdabir.setAlignment(Pos.CENTER);
        Label lblTermin = new Label("Termin");
        hbOdabir.getChildren().addAll(lblTermin,cbTermin, btnPrikazi,btnStatistika,btnSnimiUkupno);

        HBox hbPoeni = new HBox(10);
        hbPoeni.setAlignment(Pos.CENTER);
        Label lblPoeni = new Label("UML poeni");
        Label lblOpsegPoeni = new Label("(0-3)");
        hbPoeni.getChildren().addAll(lblPoeni,tfPoeni,lblOpsegPoeni,btnUnesi);

        ////
        this.getChildren().addAll(hbOdabir,tableView,hbPoeni);
    }
    private void addEvents(){
        btnPrikazi.setOnAction((e)->{
            if (cbTermin.getSelectionModel().getSelectedIndex()==0){
                tableView.setItems(termin1.getUcenici());
            }
            else if (cbTermin.getSelectionModel().getSelectedIndex()==1){
                tableView.setItems(termin2.getUcenici());
            }
            else{
                Alert alert = new Alert(Alert.AlertType.ERROR,"NISTE UNELI TERMIN",ButtonType.OK);
                alert.show();
            }
        });
        btnUnesi.setOnAction((e)->{
            try {
                float brojPoena = Float.parseFloat(tfPoeni.getText());
                if (brojPoena<0||brojPoena>3){
                    Alert alert = new Alert(Alert.AlertType.ERROR,"Pogresno unet broj poena",ButtonType.OK);
                    alert.show();
                }
                else {
                    tableView.getSelectionModel().getSelectedItem().setPoeniUML(brojPoena);
                    tableView.refresh();
                }
            }
            catch (Exception ex){
                ex.printStackTrace();
            }
        });
        btnStatistika.setOnAction((e)->{
            Stage stage;
            if (cbTermin.getSelectionModel().getSelectedIndex()==0){
                tableView.setItems(termin1.getUcenici());
                 stage = new StatistikaPage(termin1);
                stage.show();
            }
            else if (cbTermin.getSelectionModel().getSelectedIndex()==1){
                tableView.setItems(termin2.getUcenici());
                stage = new StatistikaPage(termin2);
                stage.show();
            }
            else{
                Alert alert = new Alert(Alert.AlertType.ERROR,"NISTE UNELI TERMIN",ButtonType.OK);
                alert.show();
            }

        });
        btnSnimiUkupno.setOnAction((e)->{
            try {
                LinkedList<Ucenik> uceniciSorted = new LinkedList<>();
                uceniciSorted.addAll(termin1.getUcenici());
                uceniciSorted.addAll(termin2.getUcenici());
                uceniciSorted.sort(new Comparator<Ucenik>() {
                    @Override
                    public int compare(Ucenik o1, Ucenik o2) {
                        return (int)((o2.getPoeniMoodle()+o2.getPoeniUML())*100 - (o1.getPoeniMoodle()+ o1.getPoeniUML())*100);
                    }
                });
                FileWriter fileWriter = new FileWriter("rezultat.txt");
                for (Ucenik ucenik : uceniciSorted){
                    fileWriter.write(ucenik.toString());
                    fileWriter.write("\n");
                }
                fileWriter.close();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });
    }
}
