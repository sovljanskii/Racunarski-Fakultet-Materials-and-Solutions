public abstract class Poruka {
    private String posiljalac;

    public Poruka(String posiljalac) {
        this.posiljalac = posiljalac;
    }
    abstract protected String formirajSadrzinu();
    public String formirajIspis(){

        StringBuilder sb = new StringBuilder();
        sb.append(this.posiljalac);
        sb.append("\n");
        String sadrzina = this.formirajSadrzinu();
        String[] split = sadrzina.split("\n");

        for(int i = 0; i < split.length; ++i) {
            sb.append("\t" + split[i]);
            sb.append("\n");
            if (i % 2 == 0 && i != 0) {
                sb.append("\n");
            }
        }



        return sb.toString();
    }

    public String getPosiljalac() {
        return posiljalac;
    }

    public void setPosiljalac(String posiljalac) {
        this.posiljalac = posiljalac;
    }


}
