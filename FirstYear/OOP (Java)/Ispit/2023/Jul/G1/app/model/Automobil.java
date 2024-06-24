package app.model;

public class Automobil {
    private String marka,model;
    private Tip tip;
    private int brojVozila;
    private float cena;

    public Automobil(String marka, String model, Tip tip, int brojVozila, float cena) {
        this.marka = marka;
        this.model = model;
        this.tip = tip;
        this.brojVozila = brojVozila;
        this.cena = cena;
    }

    public String getMarka() {
        return marka;
    }

    public void setMarka(String marka) {
        this.marka = marka;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public Tip getTip() {
        return tip;
    }

    public void setTip(Tip tip) {
        this.tip = tip;
    }

    public int getBrojVozila() {
        return brojVozila;
    }

    public void setBrojVozila(int brojVozila) {
        this.brojVozila = brojVozila;
    }

    public float getCena() {
        return cena;
    }

    public void setCena(float cena) {
        this.cena = cena;
    }

}
