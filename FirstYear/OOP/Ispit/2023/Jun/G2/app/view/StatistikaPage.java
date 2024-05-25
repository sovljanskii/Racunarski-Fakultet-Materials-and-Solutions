package app.view;

import app.model.Termin;
import app.model.Zadatak;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class StatistikaPage extends Stage {
    private TableView<Zadatak> tabela = new TableView<>();
    private Button povratak = new Button("Povratak");
    public StatistikaPage(Termin termin){
        VBox vBox =new VBox(20);
        vBox.setAlignment(Pos.CENTER);
        Scene scene = new Scene(vBox);
        vBox.getChildren().addAll(tabela,povratak);

        tabela.setItems(termin.getZadaci());

        TableColumn<Zadatak,String> oznakaPitanja = new TableColumn<>("Oznaka pitanja");
        TableColumn<Zadatak,Float> maksPoena = new TableColumn<>("MaksPoena");
        TableColumn<Zadatak,Float> prosek = new TableColumn<>("Prosek");
        TableColumn<Zadatak,Float> procenatMaks = new TableColumn<>("Procenat maks");

        oznakaPitanja.setCellValueFactory(new PropertyValueFactory<>("naziv"));
        maksPoena.setCellValueFactory(new PropertyValueFactory<>("maksPoena"));
        prosek.setCellValueFactory(new PropertyValueFactory<>("prosek"));
        procenatMaks.setCellValueFactory(new PropertyValueFactory<>("procenatMaks"));

        tabela.getColumns().addAll(oznakaPitanja,maksPoena,prosek,procenatMaks);

        this.setScene(scene);
        povratak.setOnAction((e)->{
            this.close();
        });
    }
}
