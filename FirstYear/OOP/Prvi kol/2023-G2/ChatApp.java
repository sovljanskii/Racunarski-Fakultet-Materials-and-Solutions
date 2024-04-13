public class ChatApp {
    public static void main(String[] args) {
        RegistracijaPrijava registracijaPrijava = new RegistracijaPrijava();
        registracijaPrijava.registrujKorisnika("Dimitrije","t0mi","Adsddsadasd1","Adsddsadasd1");
        registracijaPrijava.registrujKorisnika("Mile","m1k1","Adsddsadasd1","Adsddsadasd1");
        registracijaPrijava.registrujKorisnika("Misa","m1sa","Adsddsadasd1","Adsddsadasd1");
        registracijaPrijava.registrujKorisnika("Jovan","Jovan","Adsddsadasd1","Adsddsadasd1");
        registracijaPrijava.registrujKorisnika("Pera","pera66","Adsddsadasd1","Adsddsadasd1");
        registracijaPrijava.prijaviKorisnika("t0mi","Adsddsadasd1");
        registracijaPrijava.prijaviKorisnika("m1k1","Adsddsadasd1");
        registracijaPrijava.prijaviKorisnika("m1sa","Adsddsadasd1");
        registracijaPrijava.prijaviKorisnika("Jovan","Adsddsadasd1");
        registracijaPrijava.prijaviKorisnika("pera66","Adsddsadasd1");
        GroupChat groupChat1 = new GroupChat();
        GroupChat groupChat2 = new GroupChat();
        PrivateChat privateChat1 = new PrivateChat(registracijaPrijava.getKorisnikList().get(0), registracijaPrijava.getKorisnikList().get(1));
        PrivateChat privateChat2 = new PrivateChat(registracijaPrijava.getKorisnikList().get(2),registracijaPrijava.getKorisnikList().get(3));
        PublicChat publicChat1 = new PublicChat();
        PublicChat publicChat2 = new PublicChat();
        JustMeChat justMeChat1 = new JustMeChat(registracijaPrijava.getKorisnikList().get(0));
        JustMeChat justMeChat2 = new JustMeChat(registracijaPrijava.getKorisnikList().get(1));

        groupChat1.dodajUGrupu(registracijaPrijava.getKorisnikList().get(0));
        groupChat1.dodajUGrupu(registracijaPrijava.getKorisnikList().get(1));
        registracijaPrijava.getKorisnikList().get(0).napisiPoruku(groupChat1,"hello");
        registracijaPrijava.getKorisnikList().get(1).napisiPoruku(groupChat1,"hello");
        System.out.println(groupChat1.getPoruke());

        groupChat2.dodajUGrupu(registracijaPrijava.getKorisnikList().get(4));
        registracijaPrijava.getKorisnikList().get(4).napisiPoruku(groupChat2,"groupchat");
        System.out.println(groupChat2.getPoruke());

        registracijaPrijava.getKorisnikList().get(0).napisiPoruku(privateChat1,"hii");
        registracijaPrijava.getKorisnikList().get(0).napisiPoruku(privateChat1,"heyy");

        System.out.println(privateChat1.getPoruke());
        registracijaPrijava.getKorisnikList().get(2).napisiPoruku(privateChat2,"hii");
        registracijaPrijava.getKorisnikList().get(3).napisiPoruku(privateChat2,"heyy");

        System.out.println(privateChat2.getPoruke());
        registracijaPrijava.getKorisnikList().get(0).napisiPoruku(justMeChat1,"onlyme1");
        registracijaPrijava.getKorisnikList().get(1).napisiPoruku(justMeChat2,"onlyme2");
        System.out.println(justMeChat1.getPoruke());
        System.out.println(justMeChat2.getPoruke());

        registracijaPrijava.getKorisnikList().get(0).napisiPoruku(publicChat1,"testpublik");
        registracijaPrijava.getKorisnikList().get(0).napisiPoruku(publicChat2,"testpublik2");
        System.out.println(publicChat1.getPoruke());
        System.out.println(publicChat2.getPoruke());

    }
}
