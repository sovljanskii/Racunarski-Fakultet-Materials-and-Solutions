package app.Model;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Aktivnost extends Kurs{
    private LocalDate pocetakDatum;
    private LocalDate krajDatum;
    private LocalTime pocetakVreme;
    private LocalTime krajVreme;
    private double kompletiranost;
    public Aktivnost(String naziv, String kategorija, int cena, int duzina, LocalDate pocetakDatum, LocalTime pocetakVreme, LocalDate krajDatum, LocalTime krajVreme, double kompletiranost) {

        super(naziv, kategorija, cena, duzina);

        this.pocetakDatum= pocetakDatum;
        this.pocetakVreme= LocalTime.parse(pocetakVreme.format(DateTimeFormatter.ofPattern("hh:mm")));
        this.krajDatum=krajDatum;
        this.krajVreme=LocalTime.parse(krajVreme.format(DateTimeFormatter.ofPattern("hh:mm")));
        this.kompletiranost=kompletiranost;
    }

    public LocalDate getPocetakDatum() {
        return pocetakDatum;
    }

    public void setPocetakDatum(LocalDate pocetakDatum) {
        this.pocetakDatum = pocetakDatum;
    }

    public LocalDate getKrajDatum() {
        return krajDatum;
    }

    public void setKrajDatum(LocalDate krajDatum) {
        this.krajDatum = krajDatum;
    }

    public LocalTime getPocetakVreme() {
        return pocetakVreme;
    }

    public void setPocetakVreme(LocalTime pocetakVreme) {
        this.pocetakVreme = pocetakVreme;
    }

    public LocalTime getKrajVreme() {
        return krajVreme;
    }

    public void setKrajVreme(LocalTime krajVreme) {
        this.krajVreme = krajVreme;
    }

    public double getKompletiranost() {
        return kompletiranost;
    }

    public void setKompletiranost(double kompletiranost) {
        this.kompletiranost = kompletiranost;
    }

    @Override
    public String toString() {
        return "Aktivnost{" +
                "pocetakDatum=" + pocetakDatum +
                ", krajDatum=" + krajDatum +
                ", pocetakVreme=" + pocetakVreme +
                ", krajVreme=" + krajVreme +
                ", kompletiranost=" + kompletiranost +
                '}';
    }
}
