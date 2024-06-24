package app.view;

import app.model.Automobil;
import app.model.Database;
import app.model.Tip;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;

public class MainView extends VBox {
    private ListView<Tip> listView;
    private TextField tfOd;
    private TextField tfDo;
    private TableView<Automobil> tableView;
    private Button btnPretrazi;
    private Button btnRezervisi;
    private Button btnSveRezervacije;
    private Label lblCena;

    public MainView() {
        this.setSpacing(10);
        this.setPadding(new Insets(10, 10, 10, 10));
        this.setAlignment(Pos.CENTER);
        init();
        add();
        events();
    }
    private void init() {
        tfOd = new TextField();
        tfOd.setMaxWidth(150);
        tfDo = new TextField();
        tfDo.setMaxWidth(150);
        listView = new ListView<>();
        listView.setItems(Database.getInstance().getTipovi());

        tableView = new TableView<>();

        tableView.setItems(Database.getInstance().dostupnaVozila(tfOd.getText(),tfDo.getText()));
        TableColumn<Automobil, String> col1 = new TableColumn<>("Marka");
        TableColumn<Automobil, String> col2 = new TableColumn<>("Model");
        TableColumn<Automobil, Float> col3 = new TableColumn<>("Cena po danu");
        col1.setCellValueFactory(new PropertyValueFactory<>("marka"));
        col2.setCellValueFactory(new PropertyValueFactory<>("model"));
        col3.setCellValueFactory(new PropertyValueFactory<>("cena"));
        tableView.getColumns().addAll(col1, col2, col3);

        btnPretrazi = new Button("Pretrazi");
        btnRezervisi = new Button("Rezervisi");
        btnSveRezervacije = new Button("Sve rezervacije");
        lblCena = new Label();
    }
    private void add() {
        GridPane gpTipovi = new GridPane();
        gpTipovi.setHgap(10);
        gpTipovi.setVgap(10);
        gpTipovi.setPadding(new Insets(10, 10, 10, 10));
        VBox vb = new VBox(10);
        HBox hb = new HBox(10);
        hb.getChildren().addAll(tfOd,new Label(" - "),tfDo,btnPretrazi);
        gpTipovi.addColumn(0,new Label("Tipovi"),listView);
        vb.getChildren().addAll(new Label("Odaberite period rentiranja"),hb);
        vb.setAlignment(Pos.CENTER_LEFT);

        gpTipovi.add(vb,1,1);
        HBox hb2 = new HBox(10);
        hb2.getChildren().add(btnSveRezervacije);
        hb2.setAlignment(Pos.CENTER_RIGHT);
        gpTipovi.setAlignment(Pos.CENTER);
        this.getChildren().addAll(new Label("RENT-A-CAR"),gpTipovi,new Label("Dostupno za odredjeni model"),tableView,lblCena, btnRezervisi, hb2);
    }
    private void events(){
        btnPretrazi.setOnAction(e -> {
            System.out.println("test");
            tableView.setItems(Database.getInstance().dostupnaVozila(tfOd.getText(),tfDo.getText()));
            tableView.refresh();
        });
        tableView.setOnMouseClicked(e -> {
            try{
                LocalDate od = LocalDate.parse(tfOd.getText(), DateTimeFormatter.ofPattern("yyyy-MM-dd"));
                LocalDate doo = LocalDate.parse(tfDo.getText(), DateTimeFormatter.ofPattern("yyyy-MM-dd"));
                Float cena = tableView.getSelectionModel().getSelectedItem().getCena() * Period.between(od,doo).getDays();
                lblCena.setText("Cena za odabrani auto i period: $" + String.valueOf(cena));
            }
            catch(Exception ex){
                ex.printStackTrace();
            }
        });
        btnRezervisi.setOnAction(e -> {
            Database.getInstance().rezervisi(tableView.getSelectionModel().getSelectedItem(),tfOd.getText(),tfDo.getText());
        });
        btnSveRezervacije.setOnAction(e -> {
            Stage stage2 = new Stage();
            Scene scene2 = new Scene(new SecondView());
            stage2.setScene(scene2);
            stage2.show();
        });
    }
}
