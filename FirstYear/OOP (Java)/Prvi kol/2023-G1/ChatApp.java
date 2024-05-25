import java.io.File;
import java.io.FileWriter;

public class ChatApp {
    public static void main(String[] args) {
        Emojis emojis = Emojis.getEmojis();
        emojis.dodajEmoji("osmeh",":)");
        emojis.dodajEmoji("tuga",":(");
        emojis.dodajEmoji("plac",":(");
        emojis.dodajEmoji("namig",";)");
        emojis.dodajEmoji("poljubac",":*");

        try {
            File file = new File("test.txt");
            FileWriter fw = new FileWriter(file);
            StringBuilder stringBuilder = new StringBuilder();
            for (Emoji e : emojis.getEmojies()){
                stringBuilder.append(e.getNaziv()).append(" ").append(e.getSkracenica()).append("\n");
            }
            fw.write(stringBuilder.toString());
            fw.close();
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }

        TekstualnaPoruka tekstualnaPoruka1 = new TekstualnaPoruka("Tommy","Hello!");
        TekstualnaPoruka tekstualnaPoruka2 = new TekstualnaPoruka("Anya","Hey!");

        EmojiPoruka emojiPoruka1 = new EmojiPoruka("Mike",emojis.getEmojies().get(0));
        EmojiPoruka emojiPoruka2 = new EmojiPoruka("Josh",emojis.getEmojies().get(1));

        KombinovanaPoruka kombinovanaPoruka1 = new KombinovanaPoruka("Tommy");
        kombinovanaPoruka1.dodajUSadrzinu(tekstualnaPoruka1);
        KombinovanaPoruka kombinovanaPoruka2 = new KombinovanaPoruka("Jim");
        Poruka jimPoruka = new EmojiPoruka("Jim",emojis.getEmojies().get(2));
        kombinovanaPoruka2.dodajUSadrzinu(jimPoruka);

        KombinovaniEmoji kombinovaniEmoji1 = new KombinovaniEmoji("Nick");
        Emoji nickPoruka = emojis.getEmojies().get(3);
        kombinovaniEmoji1.dodajEmoji(nickPoruka);
        KombinovaniEmoji kombinovaniEmoji2 = new KombinovaniEmoji("Rocky");
        Emoji rockyPoruka = emojis.getEmojies().get(0);
        kombinovaniEmoji2.dodajEmoji(rockyPoruka);

        Chat history = new Chat();
        history.sacuvajPoruku(tekstualnaPoruka1);
        history.sacuvajPoruku(tekstualnaPoruka2);
        history.sacuvajPoruku(emojiPoruka1);
        history.sacuvajPoruku(emojiPoruka2);
        history.sacuvajPoruku(kombinovanaPoruka1);
        history.sacuvajPoruku(kombinovanaPoruka2);
        history.sacuvajPoruku(kombinovaniEmoji1);
        history.sacuvajPoruku(kombinovaniEmoji2);
        history.ispisiIstoriju();
    }
}
