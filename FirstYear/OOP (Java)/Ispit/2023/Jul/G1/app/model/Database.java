package app.model;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.BufferedReader;
import java.io.FileReader;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class Database {
    private static Database instance = null;
    private List<Automobil> automobili = new ArrayList<>();
    private ObservableList<Tip> tipovi = FXCollections.observableArrayList();
    private ObservableList<Rezervacija> rezervacije = FXCollections.observableArrayList();
    private Database(){
        loadFile();
    }

    public static Database getInstance(){
        if (instance == null){
            instance = new Database();
        }
        return instance;
    }
    private void loadFile(){
        try{
            BufferedReader reader = new BufferedReader(new FileReader("src/vozila.txt"));
            reader.readLine();
            reader.readLine();
            String line;
            while ((line=reader.readLine())!=null){
                line = line.replaceAll(" +"," ");
                String[] split = line.split(" ");
                Automobil a = new Automobil(split[0],split[1],new Tip(split[2]),Integer.parseInt(split[3]),Float.parseFloat(split[4]));
                automobili.add(a);
                boolean postoji=false;
                for (Tip tip : tipovi){
                    if (tip.equals(a.getTip())){
                        if (a.getCena()>tip.getMaxCena()) tip.setMaxCena(a.getCena());
                        if (a.getCena()<tip.getMinCena()) tip.setMinCena(a.getCena());
                        postoji = true;
                    }
                }
                if (!postoji){
                    tipovi.add(new Tip(a.getTip().getNaziv(),a.getCena(),a.getCena()));
                }
            }

        }
        catch(Exception e){
            e.printStackTrace();
        }
    }

    public ObservableList<Automobil> dostupnaVozila(String periodOd, String periodDo){
        ObservableList<Automobil> vozila = FXCollections.observableArrayList();
        try {
            LocalDate od = LocalDate.parse(periodOd, DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            LocalDate doo = LocalDate.parse(periodDo, DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            for (Automobil a : automobili) {
                boolean dostupan = true;
                for (Rezervacija rez : rezervacije) {
                    if (rez.getAutomobil().equals(a)) {
                        if (rez.getPocetak().isBefore(od) && rez.getKraj().isAfter(od) || (rez.getKraj().isAfter(doo) && rez.getPocetak().isBefore(doo)))
                            dostupan = false;
                    }
                }
                if (dostupan) vozila.add(a);
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }
        return vozila;
    }
    public void rezervisi(Automobil a, String periodOd, String periodDo){
        try {
            LocalDate od = LocalDate.parse(periodOd, DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            LocalDate doo = LocalDate.parse(periodDo, DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            rezervacije.add(new Rezervacija(a,od,doo));
        }
        catch (Exception e){
            e.printStackTrace();
        }

    }

    public List<Automobil> getAutomobili() {
        return automobili;
    }

    public void setAutomobili(List<Automobil> automobili) {
        this.automobili = automobili;
    }

    public ObservableList<Tip> getTipovi() {
        return tipovi;
    }

    public void setTipovi(ObservableList<Tip> tipovi) {
        this.tipovi = tipovi;
    }

    public ObservableList<Rezervacija> getRezervacije() {
        return rezervacije;
    }

    public void setRezervacije(ObservableList<Rezervacija> rezervacije) {
        this.rezervacije = rezervacije;
    }
}
