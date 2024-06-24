package app.model;

public class Vanzemaljac {
    private int id;
    private String drzava;
    private String kontinent;
    private boolean pronadjen;
    public Vanzemaljac(int id, String drzava, String kontinent) {
        this.id = id;
        this.drzava = drzava;
        this.kontinent = kontinent;
        pronadjen = true;
    }

    public Vanzemaljac(int id,String kontinent) {
        this.kontinent = kontinent;
        this.id = id;
        drzava="";
        pronadjen = false;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDrzava() {
        return drzava;
    }

    public void setDrzava(String drzava) {
        this.drzava = drzava;
    }

    public String getKontinent() {
        return kontinent;
    }

    public void setKontinent(String kontinent) {
        this.kontinent = kontinent;
    }

    public boolean isPronadjen() {
        return pronadjen;
    }

    public void setPronadjen(boolean pronadjen) {
        this.pronadjen = pronadjen;
    }

    @Override
    public String toString() {
        return "Vanzemaljac{" +
                "id=" + id +
                ", drzava='" + drzava + '\'' +
                ", kontinent='" + kontinent + '\'' +
                ", pronadjen=" + pronadjen +
                '}';
    }
}
