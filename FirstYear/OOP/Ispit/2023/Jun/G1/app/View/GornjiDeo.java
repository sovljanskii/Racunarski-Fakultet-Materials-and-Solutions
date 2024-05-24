package app.View;

import app.Model.Aktivnost;
import app.Model.Database;
import app.Model.Kurs;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;

import java.time.LocalDate;
import java.time.LocalTime;

public class GornjiDeo extends HBox {
    private Button btnDodajKurs;
    private ListView<Kurs> lvDostupniKursevi;
    private ListView<Kurs> lvMojiKursevi;
    private Button btnOdgledaj;
    private ComboBox<Integer> cbSati;
    private ComboBox<Integer> cbMinuti;
    private TextField tfTrajanje;
    private Label lblRaspolozivo;
    private Label lblTekstIspod;
    public GornjiDeo(Label lblRaspolozivo){
        this.setPadding(new Insets(20));
        this.setSpacing(20);
        ubaciElemente();
        dostupnikursevi();
        dodajEvente();
        this.lblRaspolozivo = lblRaspolozivo;
    }

    private void ubaciElemente(){
        VBox vbDostupniKursevi = new VBox(10);
        HBox hboxLabel1 = new HBox();
        hboxLabel1.setAlignment(Pos.CENTER);
        Label lblDostupniKursevi = new Label("Dostupni kursevi");
        hboxLabel1.getChildren().add(lblDostupniKursevi);

        lvDostupniKursevi = new ListView<Kurs>();

        vbDostupniKursevi.getChildren().addAll(hboxLabel1,lvDostupniKursevi);


        // dodaj kurs
        VBox vbDodajKursWrapper = new VBox();
        vbDodajKursWrapper.setAlignment(Pos.CENTER);
        btnDodajKurs = new Button("Dodaj kurs");

        vbDodajKursWrapper.getChildren().add(btnDodajKurs);

        // moji kursevi
        VBox vbMojiKursevi = new VBox(10);
        HBox hboxLabel2 = new HBox();
        hboxLabel2.setAlignment(Pos.CENTER);
        Label lblMojiKursevi = new Label("Moji kursevi");
        hboxLabel2.getChildren().addAll(lblMojiKursevi);

        lvMojiKursevi = new ListView<Kurs>();

        vbMojiKursevi.getChildren().addAll(hboxLabel2,lvMojiKursevi);

        // Pocetak aktivnosti
        VBox vbPocetakAktivnosti0 = new VBox();
        vbPocetakAktivnosti0.setAlignment(Pos.CENTER);
        VBox vbPocetakAktivnosti = new VBox(10);
        vbPocetakAktivnosti.setAlignment(Pos.CENTER);
        vbPocetakAktivnosti0.getChildren().add(vbPocetakAktivnosti);

        Label lblPocetakAktivnosti = new Label("Pocetak aktivnosti");

        HBox hbVreme = new HBox(10);
        Label lblSati = new Label("Sati:");
        cbSati = new ComboBox<>();

        for (int i=0;i<24;i++){
            cbSati.getItems().add((Integer)i);
        }


        Label lblMinuti = new Label("Minuti:");
        cbMinuti = new ComboBox<>();
        for (int i=0;i<60;i+=5){
            cbMinuti.getItems().add((Integer) i);
        }
        hbVreme.getChildren().addAll(lblSati,cbSati,lblMinuti,cbMinuti);

        // trajanje aktivnosti
        Label lblTrajanjeAktivnosti = new Label("Trajanje aktivnosti");

        HBox hbTrajanje = new HBox(20);
        tfTrajanje = new TextField();
        Label lblMaxTrajanje = new Label(" (max 120 min)");

        hbTrajanje.getChildren().addAll(tfTrajanje,lblMaxTrajanje);

        // ostalo
        btnOdgledaj = new Button("Odgledaj");

        lblTekstIspod = new Label();
        lblTekstIspod.setFont(Font.font(12));
        vbPocetakAktivnosti.getChildren().addAll(lblPocetakAktivnosti,hbVreme,lblTrajanjeAktivnosti,hbTrajanje,btnOdgledaj, lblTekstIspod);
        // ubaciti elemente
        this.getChildren().addAll(vbDostupniKursevi,vbDodajKursWrapper,vbMojiKursevi,vbPocetakAktivnosti0);
    }
    private void dostupnikursevi(){
        for (Kurs kurs : Database.getInstance().getDostupniKursevi()){
            lvDostupniKursevi.getItems().add(kurs);
        }
    }
    private void dodajEvente(){
        lvMojiKursevi.setItems(Database.getInstance().getMojiKursevi());
        btnDodajKurs.setOnAction((e)->{
            Database.getInstance().dodajUMojeKurseve(lvDostupniKursevi.getSelectionModel().getSelectedItem());
            lblRaspolozivo.setText("Raspolozivo : "+ Database.getInstance().getRaspolozivo());
        });
        btnOdgledaj.setOnAction((e)->{
            for (Aktivnost aktivnost : Database.getInstance().getAktivnosti()){
                if (aktivnost.getPocetakDatum().equals(LocalDate.now()) && (aktivnost.getPocetakVreme().equals(LocalTime.of(cbSati.getSelectionModel().getSelectedItem(),cbMinuti.getSelectionModel().getSelectedItem()))|| (aktivnost.getPocetakVreme().isBefore(LocalTime.of(cbSati.getSelectionModel().getSelectedItem(),cbMinuti.getSelectionModel().getSelectedItem()))&&aktivnost.getKrajVreme().isAfter(LocalTime.of(cbSati.getSelectionModel().getSelectedItem(),cbMinuti.getSelectionModel().getSelectedItem()))) ||aktivnost.getPocetakVreme().isAfter(LocalTime.of(cbSati.getSelectionModel().getSelectedItem(),cbMinuti.getSelectionModel().getSelectedItem())) && aktivnost.getKrajVreme().isBefore(LocalTime.of(cbSati.getSelectionModel().getSelectedItem(),cbMinuti.getSelectionModel().getSelectedItem())))){
                    lblTekstIspod.setText("U ovom periodu se vec gleda kurs " + aktivnost.getNaziv());
                    return;
                }
            }
            if (Integer.parseInt(tfTrajanje.getText())  <1 || Integer.parseInt(tfTrajanje.getText()) >120){
                Alert alert = new Alert(Alert.AlertType.ERROR,"Nije dobra uneta vrednost",ButtonType.OK);
                alert.show();

            }
            else {
                try {
                    Database.getInstance().dodajUAktivnosti(lvMojiKursevi.getSelectionModel().getSelectedItem(), Integer.parseInt(tfTrajanje.getText()),cbSati.getSelectionModel().getSelectedItem(),cbMinuti.getSelectionModel().getSelectedItem());
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
    }
}
