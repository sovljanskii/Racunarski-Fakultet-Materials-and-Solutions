import java.util.ArrayList;
import java.util.List;

public class Chat {
    private List<Poruka> poruke = new ArrayList<>();
    private List<String> posiljaoci = new ArrayList<>();
    public void sacuvajPoruku(Poruka poruka){
        poruke.add(poruka);
        if (!posiljaoci.contains(poruka.getPosiljalac())){
            posiljaoci.add(poruka.getPosiljalac());
        }
    }
    public void sacuvajPosiljaoca(String posiljalac){
        if (!posiljaoci.contains(posiljalac)){
            posiljaoci.add(posiljalac);
        }
    }
    public void ispisiIstoriju(){
        for (Poruka p : poruke){
            System.out.println(p.formirajIspis());
        }
    }
    public List<Poruka> getPoruke() {
        return poruke;
    }

    public void setPoruke(List<Poruka> poruke) {
        this.poruke = poruke;
    }

    public List<String> getPosiljaoci() {
        return posiljaoci;
    }

    public void setPosiljaoci(List<String> posiljaoci) {
        this.posiljaoci = posiljaoci;
    }
}
