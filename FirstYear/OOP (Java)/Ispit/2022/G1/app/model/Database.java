package app.model;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Database {
    private static Database instance=null;
    private Map<String, List<String>> kontinenti = new HashMap<>();
    private ObservableList<Vanzemaljac> vanzemaljci = FXCollections.observableArrayList();
    private Set<String> sveDrzave = new HashSet<>();
    private Database(){
        loadFile();
    }

    public static Database getInstance(){
        if(instance==null){
            instance=new Database();
        }
        return instance;
    }

    private void loadFile(){
        try {
            BufferedReader bf = new BufferedReader(new FileReader("/home/t0mi/Documents/Projects/OOP-JavaFX-prazan/OOP-JavaFX/src/main/java/app/model/vanzemaljci.txt"));
            String line;
            String kontinent="";
            while (!((line = bf.readLine()).equals("IZGUBLJENI"))){
                if (line.contains("Kontinent: ")){
                    String[] split = line.split(":");
                    kontinent = split[1].trim();
                    kontinenti.put(kontinent,new ArrayList<>());
                }
                else{
                    kontinenti.get(kontinent).add(line);
                    sveDrzave.add(line);
                }
            }
            System.out.println(kontinenti.entrySet());
            while (!((line = bf.readLine()).equals("PRONADJENI"))){
                String[] split = line.split(";");
                vanzemaljci.add(new Vanzemaljac(Integer.parseInt(split[0]),split[1]));
            }
            while ((line = bf.readLine()) != null){
                String[] split = line.split(";");
                int id = Integer.parseInt(split[0]);
                String drzava = split[1];
                String kontinent1 = "";
                boolean pronadjenKontinent=false;
                for (String kontinent2 : kontinenti.keySet()){
                    for (String drzava2 : kontinenti.get(kontinent2)){
                        if (drzava2.equals(drzava)){
                            kontinent1 = kontinent2;
                            pronadjenKontinent = true;
                            break;
                        }
                    }
                    if (pronadjenKontinent) break;
                }
                vanzemaljci.add(new Vanzemaljac(id,drzava,kontinent1));

            }
            vanzemaljci.sort(Comparator.comparingInt(Vanzemaljac::getId));
            System.out.println(vanzemaljci);
            bf.close();
        }
         catch (IOException e) {
           e.printStackTrace();
        }
    }

    public static void setInstance(Database instance) {
        Database.instance = instance;
    }

    public Map<String, List<String>> getKontinenti() {
        return kontinenti;
    }

    public void setKontinenti(Map<String, List<String>> kontinenti) {
        this.kontinenti = kontinenti;
    }

    public ObservableList<Vanzemaljac> getVanzemaljci() {
        return vanzemaljci;
    }

    public void setVanzemaljci(ObservableList<Vanzemaljac> vanzemaljci) {
        this.vanzemaljci = vanzemaljci;
    }

    public Set<String> getSveDrzave() {
        return sveDrzave;
    }

    public void setSveDrzave(Set<String> sveDrzave) {
        this.sveDrzave = sveDrzave;
    }
}
