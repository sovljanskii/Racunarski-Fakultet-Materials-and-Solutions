import java.util.Random;

public class Main{
    public static void main(String[] args) {
        Student s1 = new Student("Ime","Prezime","RI55/2023",TipStudenta.PREPISIVAC);
        Student s2 = new Student("Ime","Prezime","RI23/2023",TipStudenta.NIJE_PREPISIVAC);
        Student s3 = new Student("Ime","Prezime","RI45/2023",TipStudenta.NIJE_PREPISIVAC);
        Student s4 = new Student("Ime","Prezime","RI32/2023",TipStudenta.PREPISIVAC);
        Grupa g1 = new Grupa("Grupa");
        g1.dodajStudenta(s1);
        g1.dodajStudenta(s2);
        g1.dodajStudenta(s3);
        g1.dodajStudenta(s4);
        g1.odrziIspit();
        System.out.println("broj studenata koji su prepisivali:" + g1.brojStudenataKojiSuPrepisivali());
        System.out.println("prosek poena: " + g1.prosekPoenaNaIspitu());
        g1.ispisiStudente();
    }
}