package ex03.greatHouse;

/**
 * Singlenton class HouseStark
 *
 * @author
 */
public class HouseStark extends GreatHouse {

    private static String name = "Stark";
    private static String sigil = "A grey direwolf on a white field";
    private static String words = "Winter Is Coming";
    private static String lord = "Eddard Stark";

    private static HouseStark instance = null;

    private HouseStark(String name, String sigil, String words, String lord) {
        super(name, sigil, words, lord);
    }

    public static HouseStark getInstance() {
        if (instance == null) {
            instance = new HouseStark(name, sigil, words, lord);
        }
        return instance;
    }

}
