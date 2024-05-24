package app;

import app.View.Pocetna;
import javafx.application.Application;

import javafx.scene.Scene;

import javafx.stage.Stage;

public class App extends Application {


    @Override
    public void start(Stage stage) throws Exception {
        Scene scene = new Scene(new Pocetna(),1000,500);
        stage.setScene(scene);
        stage.show();
    }

}
