import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class KombinovanaPoruka extends Poruka{
    private List<Poruka> sadrzina = new ArrayList<>();
    public KombinovanaPoruka(String posiljalac) {
        super(posiljalac);
    }
    public void dodajUSadrzinu(Poruka p){
        if (this.getPosiljalac().equals(p.getPosiljalac()))return;
        if (p instanceof KombinovanaPoruka){
            this.sadrzina.addAll((((KombinovanaPoruka) p).getSadrzina()));
        }
        else if (p instanceof KombinovaniEmoji) {
            KombinovaniEmoji ke = (KombinovaniEmoji)p;
            List<Emoji> emojis = ke.getEmojis();
            Iterator var6 = emojis.iterator();

            while(var6.hasNext()) {
                Emoji e = (Emoji)var6.next();
                EmojiPoruka emojiPoruka = new EmojiPoruka(p.getPosiljalac(), e);
                this.sadrzina.add(emojiPoruka);
            }
        }
        else sadrzina.add(p);
    }
    @Override
    protected String formirajSadrzinu() {
        StringBuilder sb = new StringBuilder();
        for (Poruka p : sadrzina){
            sb.append(p).append(" ");
        }
        return sb.toString();
    }

    public List<Poruka> getSadrzina() {
        return sadrzina;
    }

    public void setSadrzina(List<Poruka> sadrzina) {
        this.sadrzina = sadrzina;
    }
}
