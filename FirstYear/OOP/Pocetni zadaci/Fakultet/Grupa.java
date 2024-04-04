import java.util.ArrayList;

public class Grupa {
    private String naziv;
    private ArrayList<Student> studenti;

    public Grupa(String naziv) {
        this.naziv = naziv;
        studenti = new ArrayList<>();
    }
    public void odrziIspit(){
        for (Student s : studenti){
            s.radiIspit();
        }
    }
    public void ispisiStudente(){
        studenti.clear();
    }
    public void dodajStudenta(Student s){
        studenti.add(s);
    }
    public double prosekPoenaNaIspitu(){
        double sum = 0;
        for(Student s : studenti){
            sum += s.getBrojPoenaNaIspitu();
        }
        return sum / studenti.size();
    }
    public int brojStudenataKojiSuPrepisivali(){
        int count = 0;
        for (Student s : studenti){
            if (s.isPrepisivao()) count++;
        }
        return count;
    }
}
