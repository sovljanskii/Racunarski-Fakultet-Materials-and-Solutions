package app.Model;

public class Kurs {
    private String naziv,kategorija;
    private int cena,duzina;

    public Kurs(String naziv, String kategorija, int cena, int duzina) {
        this.naziv = naziv;
        this.kategorija = kategorija;
        this.cena = cena;
        this.duzina = duzina;
    }

    public String getNaziv() {
        return naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public String getKategorija() {
        return kategorija;
    }

    public void setKategorija(String kategorija) {
        this.kategorija = kategorija;
    }

    public int getCena() {
        return cena;
    }

    public void setCena(int cena) {
        this.cena = cena;
    }

    public int getDuzina() {
        return duzina;
    }

    public void setDuzina(int duzina) {
        this.duzina = duzina;
    }

    @Override
    public String toString() {
        return kategorija + ", " + naziv + ", Trajanje: " + duzina + " min, $" + cena;
    }
}
