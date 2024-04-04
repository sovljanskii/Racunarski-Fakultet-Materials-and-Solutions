import java.util.Random;

public class Snesko {
    private String naziv;
    private int snaga;
    private int brojZivota;

    public Snesko(String naziv, int snaga, int brojZivota) {
        this.naziv = naziv;
        this.snaga = snaga;
        this.brojZivota = brojZivota;
    }
    public boolean pobedjen(){
        return brojZivota <= 0;
    }
    public void ukloniZivote(int x){
        this.brojZivota-=x;
    }
    public void pogodi(Snesko snesko){
        Random random = new Random();
        boolean pogodio = random.nextBoolean();
        if (pogodio) {
            snesko.ukloniZivote(this.snaga);
            System.out.println(this.naziv + " je pogodio " + snesko.naziv);
            if (snesko.brojZivota<0) snesko.brojZivota=0;
            System.out.println(snesko);
        }
        else {
            System.out.println(this.naziv + " je omasio " + snesko.naziv);

        }
    }

    @Override
    public String toString() {
        return "Snesko " + naziv +
                " snaga=" + snaga +
                ", brojZivota=" + brojZivota;
    }

    public String getNaziv() {
        return naziv;
    }
}
