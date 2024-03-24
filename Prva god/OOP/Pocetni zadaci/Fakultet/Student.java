import java.util.Random;

public class Student {
    private String ime,prezime,index;
    private TipStudenta tipStudenta;
    private int brojPoenaNaIspitu;
    private boolean prepisivao;

    public Student(String ime, String prezime, String index, TipStudenta tipStudenta) {
        this.ime = ime;
        this.prezime = prezime;
        this.index = index;
        this.tipStudenta = tipStudenta;
    }

    public void radiIspit(){
        Random random = new Random();
        if (this.tipStudenta ==TipStudenta.PREPISIVAC) {
            boolean uhvacen = random.nextBoolean();
            this.prepisivao=true;
            if (uhvacen){
                this.brojPoenaNaIspitu=0;
            }
            else {
                this.brojPoenaNaIspitu=100;
            }
        }
        else {
            prepisivao=false;
            this.brojPoenaNaIspitu= random.nextInt(101);
        }
    }

    public int getBrojPoenaNaIspitu() {
        return brojPoenaNaIspitu;
    }

    public boolean isPrepisivao() {
        return prepisivao;
    }
}
