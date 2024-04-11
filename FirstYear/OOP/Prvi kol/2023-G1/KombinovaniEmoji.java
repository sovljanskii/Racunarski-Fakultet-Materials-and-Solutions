import java.sql.Array;
import java.util.ArrayList;
import java.util.List;

public class KombinovaniEmoji extends Poruka{

    private List<Emoji> emojis= new ArrayList<>();

    public void dodajEmoji(Emoji e){
        emojis.add(e);
    }
    public void dodajEmoji(List<Emoji> e){
        emojis.addAll(e);
    }
    public KombinovaniEmoji(String posiljalac) {
        super(posiljalac);
    }

    @Override
    protected String formirajSadrzinu() {
        StringBuilder sb = new StringBuilder();
        for(Emoji e  :emojis){
            sb.append(e.getSkracenica()).append(" ");
        }
        return sb.toString();
    }

    public List<Emoji> getEmojis() {
        return emojis;
    }

    public void setEmojis(List<Emoji> emojis) {
        this.emojis = emojis;
    }
}
