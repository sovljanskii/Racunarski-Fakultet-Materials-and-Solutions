import java.util.ArrayList;
import java.util.List;

public class Emojis {
    private List<Emoji> emojis = new ArrayList<>();
    private Emojis(){};
    private static Emojis instance;
    public static Emojis getEmojis(){
        if (instance==null) instance = new Emojis();
        return instance;
    }
    public boolean dodajEmoji(String naziv, String skracenica){
        for (Emoji e : emojis){
            if (e.getNaziv().equals(naziv) || e.getSkracenica().equals(skracenica)) return false;
        }
        Emoji e = new Emoji(naziv,skracenica);
        emojis.add(e);
        return false;
    }

    public void setEmojis(List<Emoji> emojis) {
        this.emojis = emojis;
    }
    public List<Emoji> getEmojies(){
        return this.emojis;
    }

}
