package app.model;

import java.time.LocalDate;

public class Rezervacija {
    private Automobil automobil;
    private LocalDate pocetak,kraj;

    public Rezervacija(Automobil automobil, LocalDate pocetak, LocalDate kraj) {
        this.automobil = automobil;
        this.pocetak = pocetak;
        this.kraj = kraj;
    }

    public Automobil getAutomobil() {
        return automobil;
    }

    public void setAutomobil(Automobil automobil) {
        this.automobil = automobil;
    }

    public LocalDate getPocetak() {
        return pocetak;
    }

    public void setPocetak(LocalDate pocetak) {
        this.pocetak = pocetak;
    }

    public LocalDate getKraj() {
        return kraj;
    }

    public void setKraj(LocalDate kraj) {
        this.kraj = kraj;
    }
}
