package app.model;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.*;
import java.util.ArrayList;

import java.util.List;


public class Termin {
    private ObservableList<Ucenik> ucenici = FXCollections.observableArrayList();
    private static File file = null;
    private ObservableList<Zadatak> zadaci = FXCollections.observableArrayList();
    public Termin(String strFile) throws IOException {

        BufferedReader bufferedReader = new BufferedReader(new FileReader(strFile));
        String line;
        boolean pocetak=true;
        while ((line = bufferedReader.readLine())!=null){
            String[] splitten = line.split(",");
            if (pocetak){
                for (int i=3;i<splitten.length;i++){
                    String[] keyAndValue = splitten[i].split("/");
                    zadaci.add(new Zadatak(keyAndValue[0],Float.parseFloat(keyAndValue[1])));
                }
                pocetak=false;
                continue;
            }
            splitten = line.split(",");
            String prezime = splitten[0];
            String ime = splitten[1];
            String email = splitten[2];
            float brojPoena=0;
            int br=0;
            for (int i=3;i< splitten.length;i++,br++){
                try {
                    if (splitten[i].equals("-")){
                        zadaci.get(br).ubaciPoene(0);
                    }
                    else {
                        float poeni = Float.parseFloat(splitten[i]);
                        if (poeni == 0) {
                            zadaci.get(br).ubaciPoene(0);
                        } else {
                            float maksPoeni = zadaci.get(br).getMaksPoena();
                            float avg = poeni / maksPoeni*100;
                            if (poeni==maksPoeni) {
                                zadaci.get(br).addBrojLjudiMaks();
                            }

                            zadaci.get(br).ubaciPoene(poeni);
                            brojPoena += poeni;
                        }
                    }
                } catch (NumberFormatException e) {
                    System.err.println("Invalid float value: " + splitten[i]);
                }

            }
            ucenici.add(new Ucenik(ime,prezime,email,brojPoena,0));
        }
        System.out.println(zadaci);
    }

    public ObservableList<Ucenik> getUcenici() {
        return ucenici;
    }

    public void setUcenici(ObservableList<Ucenik> ucenici) {
        this.ucenici = ucenici;
    }

    public static File getFile() {
        return file;
    }

    public static void setFile(File file) {
        Termin.file = file;
    }

    public ObservableList<Zadatak> getZadaci() {
        return zadaci;
    }

    public void setZadaci(ObservableList<Zadatak> zadaci) {
        this.zadaci = zadaci;
    }
}
