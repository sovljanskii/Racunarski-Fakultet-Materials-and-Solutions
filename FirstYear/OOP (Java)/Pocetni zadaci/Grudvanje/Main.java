import java.util.Random;

public class Main{
    public static void main(String[] args) {
        Random random = new Random();
        Snesko s1 = new Snesko("Snesko 1", random.nextInt(1,10),random.nextInt(10,30));
        Snesko s2 = new Snesko("Snesko 2", random.nextInt(1,10),random.nextInt(10,30));
        System.out.println(s1);
        System.out.println(s2);
        while (!s1.pobedjen()&&!s2.pobedjen()){
            s1.pogodi(s2);
            if (!s2.pobedjen())
                s2.pogodi(s1);
        }
        if (s1.pobedjen()) System.out.println("Pobednik " + s2.getNaziv());
        else System.out.println("Pobednik " + s1.getNaziv());
    }
}