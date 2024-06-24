package app;

import app.model.Database;
import app.view.MainView;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.File;

public class App extends Application {

    public static void main(String[] args) {
        Database.getInstance();
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {

        Stage stage1 = new Stage();
        Scene scene = new Scene(new MainView());
        stage1.setScene(scene);
        stage1.show();
    }
}
