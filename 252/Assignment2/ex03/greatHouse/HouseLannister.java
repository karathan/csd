package ex03.greatHouse;

/**
 * Singlenton class HouseLannister
 *
 * @author
 */
public class HouseLannister extends GreatHouse {

    private static String name = "Lannister";
    private static String sigil = "A golden lion rampant on a crimson field";
    private static String words = "A Lannister Always Pays His Debts";
    private static String lord = "Tywin Lannister";

    private static HouseLannister instance = null;

    private HouseLannister(String name, String sigil, String words, String lord) {
        super(name, sigil, words, lord);
    }

    public static HouseLannister getInstance() {
        if (instance == null) {
            instance = new HouseLannister(name, sigil, words, lord);
        }
        return instance;
    }

}
