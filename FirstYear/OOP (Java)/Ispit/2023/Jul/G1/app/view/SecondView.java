package app.view;

import app.model.Database;
import app.model.Rezervacija;
import app.model.Tip;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

import java.time.LocalDate;


public class SecondView extends VBox {
    ComboBox<Tip> cbTip;
    TextField tfOd;
    TextField tfDo;
    Button btnPretrazi;
    TableView<Rezervacija> tableView;
    Button btnSnimi;
    public SecondView() {
        super(10);
        this.setPadding(new Insets(10, 10, 10, 10));
        this.setAlignment(Pos.CENTER);

        init();
        add();
    }
    private void init() {
        cbTip = new ComboBox<>();
        cbTip.setItems(Database.getInstance().getTipovi());
        cbTip.getItems().add(new Tip("Sve"));
        tfOd = new TextField();
        tfDo = new TextField();
        btnPretrazi = new Button("Pretrazi");
        btnSnimi = new Button("Snimi");
        tableView = new TableView<>();

        tableView.setItems(Database.getInstance().getRezervacije());
        TableColumn<Rezervacija,String> c1 = new TableColumn<>("Tip");
        TableColumn<Rezervacija,String> c2 = new TableColumn<>("Marka");
        TableColumn<Rezervacija,String> c3 = new TableColumn<>("Model");
        TableColumn<Rezervacija,Float> c4 = new TableColumn<>("Cena po danu");
        TableColumn<Rezervacija, LocalDate> c5 = new TableColumn<>("Od");
        TableColumn<Rezervacija, LocalDate> c6 = new TableColumn<>("Do");
        TableColumn<Rezervacija, Float> c7 = new TableColumn<>("Ukupna cena");


    }
    private void add(){
        HBox hb = new HBox(10);
        hb.getChildren().addAll(cbTip,tfOd,new Label(" - "),tfDo);
        this.getChildren().addAll(hb,btnPretrazi,tableView,btnSnimi);
    }
}
