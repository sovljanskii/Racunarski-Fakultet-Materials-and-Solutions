public class TekstualnaPoruka extends Poruka{
    private String tekst;
    public TekstualnaPoruka(String posiljalac, String tekst) {
        super(posiljalac); this.tekst=tekst;
    }

    @Override
    protected String formirajSadrzinu() {
        return tekst;
    }

}
