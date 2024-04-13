public class PitanjeSlobodanOdgovor extends Pitanje{
    private int brojLinija;
    public PitanjeSlobodanOdgovor(String tekstPitanja) {
        super(tekstPitanja);
    }

    @Override
    public String vratiZaStampu() {
        StringBuilder stringBuilder = new StringBuilder();


        stringBuilder.append(super.spremnoZaStampu()).append("\n");
        stringBuilder.append("_".repeat(Math.max(0, brojLinija)));

        return stringBuilder.toString();
    }

    @Override
    public boolean spremnoZaStampu() {
        return super.spremnoZaStampu() && brojLinija>0;
    }

    public int getBrojLinija() {
        return brojLinija;
    }

    public void setBrojLinija(int brojLinija) {
        this.brojLinija = brojLinija;
    }
}
