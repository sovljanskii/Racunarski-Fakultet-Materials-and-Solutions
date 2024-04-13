import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class Stamparija {
    private List<ZaStampanje> zaStampanje= new ArrayList<>();
    public void dodajZaStampanje(ZaStampanje zs){
        zaStampanje.add(zs);
    }
    public void odstampajOdDo(int a, int b){
        for (int i=a;i<=b;i++){
            ZaStampanje zs = zaStampanje.get(i);
            if (zs.spremnoZaStampu()) System.out.println(zs.vratiZaStampu());
            else System.out.println("NIJE SPREMNO");
        }
    }
    public void stampajUStandardniIzlaz(){
        StringBuilder sb = new StringBuilder();
        for (ZaStampanje zs : zaStampanje){
            if (zs.spremnoZaStampu()) System.out.println(zs.vratiZaStampu());
            else System.out.println("NIJE SPREMNO");
        }
    }
    public void stampajUFajl(File f1){
        try{
            FileWriter fileWriter = new FileWriter(f1);
            StringBuilder sb = new StringBuilder();
            for (ZaStampanje zs : zaStampanje){
                if (zs.spremnoZaStampu()) sb.append(zs.vratiZaStampu()).append("\n");
                else sb.append("NIJE SPREMNO").append("\n");
            }
            fileWriter.write(sb.toString());
            fileWriter.close();
        }
        catch (Exception ex){
            System.out.println(ex.getMessage());
        }
    }
    public List<ZaStampanje> getZaStampanje() {
        return zaStampanje;
    }

    public void setZaStampanje(List<ZaStampanje> zaStampanje) {
        this.zaStampanje = zaStampanje;
    }
}
