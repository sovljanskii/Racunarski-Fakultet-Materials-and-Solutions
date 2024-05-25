public abstract class Pitanje implements ZaStampanje {
    private String tekstPitanja;
    private int redniBroj, brojPoena;

    public Pitanje(String tekstPitanja) {
        this.tekstPitanja = tekstPitanja;
    }
    public Pitanje(String tekstPitanja,int redniBroj) {
        this.tekstPitanja = tekstPitanja;
        this.redniBroj=redniBroj;
    }
    @Override
    public String vratiZaStampu(){
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(redniBroj).append(".(").append(brojPoena).append(")").append(tekstPitanja);
        return stringBuilder.toString();
    }

    @Override
    public boolean spremnoZaStampu() {
        return !this.tekstPitanja.isEmpty() && !this.tekstPitanja.isBlank();
    }

    public String getTekstPitanja() {
        return tekstPitanja;
    }

    public void setTekstPitanja(String tekstPitanja) {
        this.tekstPitanja = tekstPitanja;
    }

    public int getRedniBroj() {
        return redniBroj;
    }

    public void setRedniBroj(int redniBroj) {
        this.redniBroj = redniBroj;
    }

    public int getBrojPoena() {
        return brojPoena;
    }

    public void setBrojPoena(int brojPoena) {
        this.brojPoena = brojPoena;
    }

    @Override
    public String toString() {
        return "Pitanje{" +
                "tekstPitanja='" + tekstPitanja + '\'' +
                ", redniBroj=" + redniBroj +
                ", brojPoena=" + brojPoena +
                '}';
    }
}
