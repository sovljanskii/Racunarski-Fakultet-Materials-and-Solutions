package app.View;

import app.Model.Database;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

public class Pocetna extends VBox {
    HBox hbGore;
    VBox vbDole;
    Label lblRaf;
    Label lblRaspolozivo;
    public Pocetna(){
        this.setAlignment(Pos.CENTER);
        this.setPadding(new Insets(20));
        this.setSpacing(20);
        kreirajElemente();
        ubaciElemente();
    }

    private void kreirajElemente(){
        lblRaspolozivo = new Label("Raspolozivo:" + Database.getInstance().getRaspolozivo());
        hbGore = new GornjiDeo(lblRaspolozivo);
        vbDole = new DonjiDeo();
        lblRaf = new Label("Raf Coursera");
    }
    private void ubaciElemente(){
        this.getChildren().addAll(lblRaf,lblRaspolozivo,hbGore,vbDole);
    }
}
