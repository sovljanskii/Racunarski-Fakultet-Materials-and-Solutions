import java.util.ArrayList;
import java.util.List;

public class PitanjePonudjeniOdgovori extends Pitanje{
    private List<String> ponudjeniOdgovori = new ArrayList<>();
    public PitanjePonudjeniOdgovori(String tekstPitanja) {
        super(tekstPitanja);
    }

    @Override
    public String vratiZaStampu() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(super.spremnoZaStampu()).append("\n");
        for (String str : ponudjeniOdgovori){
            stringBuilder.append(str).append("\n");
        }
        return stringBuilder.toString();
    }
    public void dodajOdgovor(){

    }

    @Override
    public boolean spremnoZaStampu() {
        return super.spremnoZaStampu() && ponudjeniOdgovori.size()>1;
    }

    public List<String> getPonudjeniOdgovori() {
        return ponudjeniOdgovori;
    }

    public void setPonudjeniOdgovori(List<String> ponudjeniOdgovori) {
        this.ponudjeniOdgovori = ponudjeniOdgovori;
    }

}
