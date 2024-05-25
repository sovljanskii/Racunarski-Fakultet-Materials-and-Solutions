import java.util.ArrayList;
import java.util.List;

public class PublicChat implements Chat {
    List<String> poruke = new ArrayList<>();

    public void PublicChat(){}
    @Override
    public boolean mozeNapisatiPoruku(Korisnik korisnik) {
        return true;
    }

    @Override
    public void dodajPoruku(Korisnik korisnik, String tekst) {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("[").append(korisnik.getPrikazanoIme()).append("] ==> [").append(tekst).append("]");
        poruke.add(stringBuilder.toString());
    }

    public List<String> getPoruke() {
        return poruke;
    }

    public void setPoruke(List<String> poruke) {
        this.poruke = poruke;
    }
}
