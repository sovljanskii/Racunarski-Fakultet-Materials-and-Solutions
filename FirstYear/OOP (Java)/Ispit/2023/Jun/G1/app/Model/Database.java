package app.Model;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;

import java.io.BufferedReader;
import java.io.FileReader;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

public class Database {
    private static Database instance = null;
    private List<Kurs> dostupniKursevi = new ArrayList<>();
    private ObservableList<Kurs> mojiKursevi = FXCollections.observableArrayList();
    private ObservableList<Aktivnost> aktivnosti = FXCollections.observableArrayList();
    private int raspolozivo = 1000;
    private Database(){
        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader("/home/t0mi/Projects/OOP-JavaFX-prazan/OOP-JavaFX/src/main/java/app/RAF_Coursera.txt"));
            String line;
            while ((line=bufferedReader.readLine())!=null){
                String[] arr = line.split("[,:>]");
                String ime = arr[0];
                String kategorija = arr[1];
                int duzina = Integer.parseInt((arr[2].split(" "))[0]);
                int cena = Integer.parseInt((arr[3]).replace("$",""));
                dodajUKurseve(new Kurs(ime,kategorija,cena,duzina));
            }
            bufferedReader.close();

        }
        catch (Exception ex){
            ex.printStackTrace();
        }

    }

    public static Database getInstance() {
        if (instance==null){
            instance = new Database();
        }
        return instance;
    }

    private void oduzmiRaspolozivo(int suma){
        raspolozivo-=suma;
    }
    public void dodajUKurseve(Kurs kurs){
        dostupniKursevi.add(kurs);
    }
    public void dodajUMojeKurseve(Kurs noviKurs){
        if (mojiKursevi.contains(noviKurs)){
            Alert alert = new Alert(Alert.AlertType.ERROR,"Vec posedujete ovaj kurs", ButtonType.OK);
            alert.show();
            return;
        }
        if (noviKurs.getCena()>raspolozivo){
            Alert alert = new Alert(Alert.AlertType.ERROR,"NEMATE DOVOLJNO SREDSTAVA ZA OVAJ KURS", ButtonType.OK);
            alert.show();
            return;
        }
        oduzmiRaspolozivo(noviKurs.getCena());
        mojiKursevi.add(noviKurs);
    }

    public void dodajUAktivnosti(Kurs kurs,int trajanje, int sati, int minuti){

        aktivnosti.add(new Aktivnost(kurs.getNaziv(),kurs.getKategorija(),kurs.getCena(),kurs.getDuzina(), LocalDate.now(), LocalTime.of(sati,minuti),LocalDate.now().plusDays(trajanje/3600),LocalTime.of(sati,minuti).plusMinutes(trajanje),1.0*trajanje/kurs.getDuzina() *100));
    }

    public List<Kurs> getDostupniKursevi() {
        return dostupniKursevi;
    }

    public void setDostupniKursevi(List<Kurs> dostupniKursevi) {
        this.dostupniKursevi = dostupniKursevi;
    }

    public int getRaspolozivo() {
        return raspolozivo;
    }

    public void setRaspolozivo(int raspolozivo) {
        this.raspolozivo = raspolozivo;
    }

    public ObservableList<Kurs> getMojiKursevi() {
        return mojiKursevi;
    }

    public void setMojiKursevi(ObservableList<Kurs> mojiKursevi) {
        this.mojiKursevi = mojiKursevi;
    }

    public ObservableList<Aktivnost> getAktivnosti() {
        return aktivnosti;
    }

    public void setAktivnosti(ObservableList<Aktivnost> aktivnosti) {
        this.aktivnosti = aktivnosti;
    }
}
