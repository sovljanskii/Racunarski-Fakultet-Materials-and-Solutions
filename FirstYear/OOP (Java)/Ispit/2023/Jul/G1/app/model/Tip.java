package app.model;

import java.util.Objects;

public class Tip {
    private String naziv;
    private Float minCena,maxCena;
    public Tip(String naziv) {
        this.naziv=naziv;
    }

    public Tip(String naziv, Float minCena, Float maxCena) {
        this.naziv = naziv;
        this.minCena = minCena;
        this.maxCena = maxCena;
    }

    public String getNaziv() {
        return naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public Float getMinCena() {
        return minCena;
    }

    public void setMinCena(Float minCena) {
        this.minCena = minCena;
    }

    public Float getMaxCena() {
        return maxCena;
    }

    public void setMaxCena(Float maxCena) {
        this.maxCena = maxCena;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Tip tip = (Tip) o;
        return Objects.equals(naziv, tip.naziv);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(naziv);
    }

    @Override
    public String toString() {
        return naziv + " cena po danu $" + minCena + " - $" + maxCena;
    }
}
