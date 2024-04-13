import java.util.ArrayList;
import java.util.List;

public class RegistracijaPrijava {
    private List<Korisnik> korisnikList = new ArrayList<>();
    public void dodajKorisnika(String user, String name, String password){
        Korisnik k = new Korisnik(name,user,password);
        korisnikList.add(k);
    }

    public List<Korisnik> getKorisnikList() {
        return korisnikList;
    }

    public void setKorisnikList(List<Korisnik> korisnikList) {
        this.korisnikList = korisnikList;
    }
    public boolean registrujKorisnika(String prikazanoIme,String korisnickoIme, String lozinka1, String lozinka2){
        if (!lozinka1.equals(lozinka2) || lozinka1.equals(lozinka1.toLowerCase()) || lozinka1.equals(lozinka1.toUpperCase())
        || lozinka1.equals(lozinka1.replaceAll("[0-9]","")) || lozinka1.length()<8) return false;
        for (Korisnik korisnik : korisnikList){
            if (korisnik.getKorisnickoIme().equals(korisnickoIme)){
                return false;
            }
        }
        System.out.println("Registrovan korisnik " + korisnickoIme);
        dodajKorisnika(korisnickoIme,prikazanoIme,lozinka1);
        return true;
    }
    public boolean prijaviKorisnika(String korisnickoIme,String lozinka){
        for (Korisnik k : korisnikList){
            if (k.getKorisnickoIme().equals(korisnickoIme)){
                System.out.println("Prijavljen korisnik " + korisnickoIme);
                return k.getLozinka().equals(lozinka);
            }
        }
        return false;
    }
}
