import java.util.ArrayList;
import java.util.List;

public class PitanjePovezivanje extends Pitanje{
    private List<String> prvaKolona= new ArrayList<>();
    private List<String> drugaKolona = new ArrayList<>();
    private int brojPraznihMesta;
    public PitanjePovezivanje(String tekstPitanja) {
        super(tekstPitanja);
    }

    @Override
    public String vratiZaStampu() {
        StringBuilder stringBuilder = new StringBuilder();
        if (!prvaKolona.isEmpty() && !drugaKolona.isEmpty()) {

            stringBuilder.append(super.spremnoZaStampu()).append("\n");
            for (int i = 0; i < prvaKolona.size(); i++) {
                stringBuilder.append(prvaKolona.get(i)).append("     ").append(drugaKolona.get(i)).append("\n");
            }
        }
        return stringBuilder.toString();
    }

    @Override
    public boolean spremnoZaStampu() {
        return super.spremnoZaStampu() && !prvaKolona.isEmpty();
    }

    public List<String> getPrvaKolona() {
        return prvaKolona;
    }

    public void setPrvaKolona(List<String> prvaKolona) {
        if (this.drugaKolona.size()==prvaKolona.size() || drugaKolona.isEmpty())
            this.prvaKolona = prvaKolona;
    }

    public List<String> getDrugaKolona() {
        return drugaKolona;
    }

    public void setDrugaKolona(List<String> drugaKolona) {
        if (this.prvaKolona.size()==drugaKolona.size() || prvaKolona.isEmpty())
            this.drugaKolona = drugaKolona;
    }

    public int getBrojPraznihMesta() {
        return brojPraznihMesta;
    }

    public void setBrojPraznihMesta(int brojPraznihMesta) {
        this.brojPraznihMesta = brojPraznihMesta;
    }
}
