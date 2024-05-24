package app.View;

import app.Model.Database;
import app.Model.Aktivnost;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class DonjiDeo extends VBox {
    private Button btnSnimiAktivnosti;
    private TableView<Aktivnost> tableView;
    public DonjiDeo(){
        ubaciElemente();
        ubaciEvente();
    }
    private void ubaciElemente(){
        tableView = new TableView<>();

        btnSnimiAktivnosti = new Button("Snimi aktivnosti");
        HBox hbDugmeWrapper = new HBox();
        hbDugmeWrapper.setAlignment(Pos.CENTER);
        hbDugmeWrapper.getChildren().add(btnSnimiAktivnosti);

        this.getChildren().addAll(tableView,hbDugmeWrapper);
        tableView.setItems(Database.getInstance().getAktivnosti());

        TableColumn<Aktivnost,String> kurs = new TableColumn<>("Kurs");
        TableColumn<Aktivnost,String> kategorija = new TableColumn<>("Kategorija");
        TableColumn<Aktivnost, LocalDate> pocetakDatum = new TableColumn<>("Pocetak (Datum)");
        TableColumn<Aktivnost, LocalTime> pocetakVreme = new TableColumn<>("Pocetak (Vreme)");
        TableColumn<Aktivnost, LocalDate> krajDatum = new TableColumn<>("Kraj (Datum)");
        TableColumn<Aktivnost, LocalTime> krajVreme = new TableColumn<>("Kraj (Vreme)");
        TableColumn<Aktivnost, Double> kompletiranost = new TableColumn<>("Kompletiranost");



        kurs.setCellValueFactory(new PropertyValueFactory<>("naziv"));
        kategorija.setCellValueFactory(new PropertyValueFactory<>("kategorija"));
        pocetakDatum.setCellValueFactory(new PropertyValueFactory<>("pocetakDatum"));
        pocetakVreme.setCellValueFactory(new PropertyValueFactory<>("pocetakVreme"));
        krajDatum.setCellValueFactory(new PropertyValueFactory<>("krajDatum"));
        krajVreme.setCellValueFactory(new PropertyValueFactory<>("krajVreme"));
        kompletiranost.setCellValueFactory(new PropertyValueFactory<>("kompletiranost"));
        tableView.getColumns().addAll(kurs,kategorija,pocetakDatum,pocetakVreme,krajDatum,krajVreme,kompletiranost);
    }
    private void ubaciEvente(){
        btnSnimiAktivnosti.setOnAction((e)->{
            try {
                FileWriter fileWriter = new FileWriter("test.txt");
                List<Aktivnost> raspored = new LinkedList<>();
                raspored.addAll(Database.getInstance().getAktivnosti());
                raspored.sort(new Comparator<Aktivnost>() {
                    @Override
                    public int compare(Aktivnost o1, Aktivnost o2) {
                        if (o1.getKategorija().equals(o2.getKategorija())){
                            return o1.getNaziv().compareTo(o2.getNaziv());
                        }
                        return o1.getKategorija().compareTo(o2.getKategorija());
                    }
                });
                String kategorija = null;
                String naziv=null;
                int counter=0;
                double kompletirano=0;
                for (Aktivnost aktivnost : raspored){
                    if (!aktivnost.getKategorija().equals(kategorija) || !aktivnost.getNaziv().equals(naziv)){
                        if (naziv!=null) {
                            fileWriter.write("Ukupno kompletirano " + kompletirano);
                            fileWriter.write("\n");
                        }
                        if (!aktivnost.getKategorija().equals(kategorija)){
                            kategorija=aktivnost.getKategorija();
                            fileWriter.write("Kategorija : " + aktivnost.getKategorija());
                            fileWriter.write("\n");
                        }
                        if (!aktivnost.getNaziv().equals(naziv)){
                            naziv=aktivnost.getNaziv();
                            fileWriter.write("Naziv kursa " + aktivnost.getNaziv());
                            fileWriter.write("\n");
                        }
                        counter=0;
                        kompletirano=0;
                    }


                    fileWriter.write("Aktivnost " + counter + " " +  aktivnost.getPocetakVreme() + " " + aktivnost.getPocetakDatum() + " - " + aktivnost.getKrajVreme() + " " +aktivnost.getKrajDatum());
                    fileWriter.write("\n");
                    kompletirano+=aktivnost.getKompletiranost();
                    counter++;
                }
                fileWriter.write("Ukupno kompletirano " + kompletirano);
                fileWriter.write("\n");
                fileWriter.close();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });
    }
}
