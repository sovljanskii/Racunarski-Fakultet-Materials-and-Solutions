package app.model;

public class Zadatak {
    private String naziv;
    private float maksPoena,prosek,brojPoenaUkupno;
    private int brojLjudi;
    private int brojLjudiMaks;
    public Zadatak(String naziv, float maksPoena) {
        this.naziv = naziv;
        this.maksPoena = maksPoena;
        brojLjudi=0;
        brojPoenaUkupno=0;

        brojLjudiMaks=0;
    }
    public void ubaciPoene(float poeni){
        brojLjudi++;
        brojPoenaUkupno+=poeni;
        prosek=brojLjudi/brojPoenaUkupno;
    }
    public void addBrojLjudiMaks(){
        brojLjudiMaks++;
    }
    @Override
    public String toString() {
        return "Zadatak{" +
                "naziv='" + naziv + '\'' +
                ", maksPoena=" + maksPoena +
                ", prosek=" + prosek +
                '}';
    }

    public String getNaziv() {
        return naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public float getMaksPoena() {
        return maksPoena;
    }

    public void setMaksPoena(float maksPoena) {
        this.maksPoena = maksPoena;
    }

    public float getProsek() {
        return prosek;
    }

    public void setProsek(float prosek) {
        this.prosek = prosek;
    }

    public float getProcenatMaks() {
        return 1.0f*brojLjudiMaks/brojLjudi*100;

    }



    public float getBrojPoenaUkupno() {
        return brojPoenaUkupno;
    }

    public void setBrojPoenaUkupno(float brojPoenaUkupno) {
        this.brojPoenaUkupno = brojPoenaUkupno;
    }

    public int getBrojLjudi() {
        return brojLjudi;
    }

    public void setBrojLjudi(int brojLjudi) {
        this.brojLjudi = brojLjudi;
    }
}
