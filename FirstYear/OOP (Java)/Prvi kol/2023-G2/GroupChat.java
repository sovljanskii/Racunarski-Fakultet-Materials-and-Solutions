import java.util.ArrayList;
import java.util.List;

public class GroupChat implements Chat {
    private List<String> poruke = new ArrayList<>();
    private List<Korisnik> grupa = new ArrayList<>();
    private List<Korisnik> posiljaoci = new ArrayList<>();
    public GroupChat() {
    }
    public void dodajUGrupu(Korisnik korisnik){
        if (!grupa.contains(korisnik)) grupa.add(korisnik);
    }
    public void ukloniIzGrupe(Korisnik korisnik){
        grupa.remove(korisnik);
    }
    @Override
    public boolean mozeNapisatiPoruku(Korisnik korisnik) {
        return grupa.contains(korisnik);
    }

    @Override
    public void dodajPoruku(Korisnik korisnik, String tekst) {
            if (!posiljaoci.contains(korisnik)) posiljaoci.add(korisnik);
            poruke.add(tekst);

    }

    public List<String> getPoruke() {
        return poruke;
    }

    public void setPoruke(List<String> poruke) {
        this.poruke = poruke;
    }

    public List<Korisnik> getGrupa() {
        return grupa;
    }

    public void setGrupa(List<Korisnik> grupa) {
        this.grupa = grupa;
    }

    public List<Korisnik> getPosiljaoci() {
        return posiljaoci;
    }

    public void setPosiljaoci(List<Korisnik> posiljaoci) {
        this.posiljaoci = posiljaoci;
    }
}
