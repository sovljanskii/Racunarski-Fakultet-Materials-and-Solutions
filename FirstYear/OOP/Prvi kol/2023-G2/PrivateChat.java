import java.util.ArrayList;
import java.util.List;

public class PrivateChat implements Chat{
    private List<String> poruke = new ArrayList<>();
    private Korisnik k1,k2,prethodniPosiljalac;

    public PrivateChat(Korisnik k1, Korisnik k2) {
        this.k1 = k1;
        this.k2 = k2;
        this.prethodniPosiljalac = k2;
    }

    @Override
    public boolean mozeNapisatiPoruku(Korisnik korisnik) {
        if (!prethodniPosiljalac.equals(korisnik)) {
            if (prethodniPosiljalac.equals(k1)) prethodniPosiljalac=k2;
            else prethodniPosiljalac=k2;
            return true;
        }

       return false;
    }

    @Override
    public void dodajPoruku(Korisnik korisnik, String tekst) {
        poruke.add(tekst);
    }

    public List<String> getPoruke() {
        return poruke;
    }

    public void setPoruke(List<String> poruke) {
        this.poruke = poruke;
    }

    public Korisnik getK1() {
        return k1;
    }

    public void setK1(Korisnik k1) {
        this.k1 = k1;
    }

    public Korisnik getK2() {
        return k2;
    }

    public void setK2(Korisnik k2) {
        this.k2 = k2;
    }

    public Korisnik getPrethodniPosiljalac() {
        return prethodniPosiljalac;
    }

    public void setPrethodniPosiljalac(Korisnik prethodniPosiljalac) {
        this.prethodniPosiljalac = prethodniPosiljalac;
    }
}
