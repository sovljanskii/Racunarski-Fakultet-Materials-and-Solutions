import java.util.ArrayList;
import java.util.List;

public class JustMeChat implements Chat {
    private Korisnik glavniKorisnik;
    private List<String> poruke = new ArrayList<>();

    public JustMeChat(Korisnik glavniKorisnik) {
        this.glavniKorisnik = glavniKorisnik;
    }

    @Override
    public boolean mozeNapisatiPoruku(Korisnik korisnik) {
        return korisnik.equals(glavniKorisnik);
    }

    @Override
    public void dodajPoruku(Korisnik korisnik, String tekst) {
        poruke.add(tekst);
    }

    public Korisnik getGlavniKorisnik() {
        return glavniKorisnik;
    }

    public void setGlavniKorisnik(Korisnik glavniKorisnik) {
        this.glavniKorisnik = glavniKorisnik;
    }

    public List<String> getPoruke() {
        return poruke;
    }

    public void setPoruke(List<String> poruke) {
        this.poruke = poruke;
    }
}
