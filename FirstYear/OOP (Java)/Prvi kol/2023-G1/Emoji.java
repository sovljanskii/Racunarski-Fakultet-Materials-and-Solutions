public class Emoji {
    private String naziv,skracenica;
    Emoji(String naziv, String skracenica){
        this.naziv=naziv;
        this.skracenica=skracenica;
    }

    public String getNaziv() {
        return naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public String getSkracenica() {
        return skracenica;
    }

    public void setSkracenica(String skracenica) {
        this.skracenica = skracenica;
    }
}
