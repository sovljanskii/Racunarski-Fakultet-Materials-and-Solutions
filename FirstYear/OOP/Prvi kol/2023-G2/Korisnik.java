import java.io.File;
import java.io.FileWriter;
import java.util.Objects;

public class Korisnik {
    private String prikazanoIme,korisnickoIme,lozinka;

    public Korisnik(String prikazanoIme, String korisnickoIme, String lozinka) {
        this.prikazanoIme = prikazanoIme;
        this.korisnickoIme = korisnickoIme;
        this.lozinka = lozinka;
    }
    void napisiPoruku(Chat chat, String tekst){
        if (chat.mozeNapisatiPoruku(this)){
            chat.dodajPoruku(this,tekst);
        }
        else {
            File f1 = new File("neuspesno.txt");
            try{
                FileWriter fileWriter = new FileWriter(f1);
                fileWriter.write(korisnickoIme + ": "  + tekst + "\n");
                StringBuilder stringBuilder = new StringBuilder();
                if (chat instanceof GroupChat){
                    for (Korisnik k : (((GroupChat) chat).getGrupa())){
                        stringBuilder.append(k).append("\n");
                    }
                }
                else if (chat instanceof PrivateChat){
                    stringBuilder.append(((PrivateChat) chat).getK1()).append("\n").append(((PrivateChat) chat).getK2());
                }

                fileWriter.write(korisnickoIme);
                fileWriter.close();
            }
            catch (Exception exception){
                System.out.println(exception.getMessage());
            }
        }
    }

    public String getPrikazanoIme() {
        return prikazanoIme;
    }

    public void setPrikazanoIme(String prikazanoIme) {
        this.prikazanoIme = prikazanoIme;
    }

    public String getKorisnickoIme() {
        return korisnickoIme;
    }

    public void setKorisnickoIme(String korisnickoIme) {
        this.korisnickoIme = korisnickoIme;
    }

    public String getLozinka() {
        return lozinka;
    }

    public void setLozinka(String lozinka) {
        this.lozinka = lozinka;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Korisnik korisnik = (Korisnik) o;
        return Objects.equals(korisnickoIme, korisnik.korisnickoIme);
    }

    @Override
    public int hashCode() {
        return Objects.hash(korisnickoIme);
    }
}
