public class Robot {
    private String ime;
    private Boja boja;
    private int tezina;

    public Robot(String ime, Boja boja, int tezina) {
        this.ime = ime;
        this.boja = boja;
        this.tezina = tezina;
    }

    public String getIme() {
        return ime;
    }
    public Boja getBoja() {
        return boja;
    }
    public int getTezina() {
        return tezina;
    }
    public void setIme(String ime) {
        this.ime = ime;
    }

    public void setBoja(Boja boja) {
        this.boja = boja;
    }
    public void aboutMe(){
        System.out.println("Naziv: " + this.ime + ", tezina: " + this.tezina + " ");
    }

}
