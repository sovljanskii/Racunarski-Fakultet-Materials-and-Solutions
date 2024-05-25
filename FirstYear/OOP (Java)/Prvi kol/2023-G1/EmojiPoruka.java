public class EmojiPoruka extends Poruka {
    private Emoji emoji;

    public EmojiPoruka(String posiljalac, Emoji emoji) {
        super(posiljalac);
        this.emoji=emoji;
    }

    @Override
    protected String formirajSadrzinu() {
        return emoji.getSkracenica();
    }

    public Emoji getEmoji() {
        return emoji;
    }

    public void setEmoji(Emoji emoji) {
        this.emoji = emoji;
    }
}
