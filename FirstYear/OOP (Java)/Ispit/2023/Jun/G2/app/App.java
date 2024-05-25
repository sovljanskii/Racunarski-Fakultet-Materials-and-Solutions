package app;

import app.view.FirstPage;
import javafx.application.Application;

import javafx.scene.Scene;

import javafx.stage.Stage;

public class App extends Application {


    @Override
    public void start(Stage stage) throws Exception {
        Scene scene = new Scene(new FirstPage(),800,600);
        stage.setScene(scene);
        stage.show();
    }

}
