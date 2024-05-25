package app.model;

public class Ucenik {
    private String ime,prezime,email;
    private float poeniMoodle,poeniUML;

    public Ucenik(String ime, String prezime, String email, float poeniMoodle, float poeniUML) {
        this.ime = ime;
        this.prezime = prezime;
        this.email = email;
        this.poeniMoodle = poeniMoodle;
        this.poeniUML = poeniUML;
    }

    public String getIme() {
        return ime;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public String getPrezime() {
        return prezime;
    }

    public void setPrezime(String prezime) {
        this.prezime = prezime;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public float getPoeniMoodle() {
        return poeniMoodle;
    }

    public void setPoeniMoodle(float poeniMoodle) {
        this.poeniMoodle = poeniMoodle;
    }

    public float getPoeniUML() {
        return poeniUML;
    }

    public void setPoeniUML(float poeniUML) {
        this.poeniUML = poeniUML;
    }

    @Override
    public String toString() {
        return
                "ime='" + ime + '\'' +
                ", prezime='" + prezime + '\'' +
                ", email='" + email + '\'' +
                ", poeni=" +(poeniMoodle + poeniUML);
    }
}
