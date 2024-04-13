import java.util.ArrayList;
import java.util.List;

public class Test implements ZaStampanje {
    private String naslov;
    private List<Pitanje> pitanja = new ArrayList<>();
    public boolean dodajPitanje(Pitanje p){
        pitanja.add(p);
        return true;
    }
    @Override
    public String vratiZaStampu() {
        StringBuilder sb = new StringBuilder();
        int brPoena=0;
        for (Pitanje pitanje : pitanja){
            brPoena+=pitanje.getBrojPoena();
        }
        sb.append(naslov).append("\n").append(brPoena).append("\n");
        for (Pitanje pitanje : pitanja){
            if (pitanje.spremnoZaStampu()) {
                sb.append(pitanje.vratiZaStampu()).append("\n").append("\n");
            }
        }
        return sb.toString();
    }

    @Override
    public boolean spremnoZaStampu() {
        for (Pitanje p : pitanja){
            if (!p.spremnoZaStampu()) return false;
            if (p.getBrojPoena()==0) return false;

        }
        return true;
    }

    public String getNaslov() {
        return naslov;
    }

    public void setNaslov(String naslov) {
        this.naslov = naslov;
    }

    public List<Pitanje> getPitanja() {
        return pitanja;
    }

    public void setPitanja(List<Pitanje> pitanja) {
        this.pitanja = pitanja;
    }
}
