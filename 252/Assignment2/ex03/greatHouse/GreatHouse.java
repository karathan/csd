package ex03.greatHouse;

import ex03.weaponCarrier.Soldier;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * Abstract class GreatHouse
 *
 * @author
 */
public abstract class GreatHouse {

    private final String name;
    private final String sigil;
    private final String words;
    private final String lord;
    private final ArrayList army = new ArrayList();

    public GreatHouse(String name, String sigil, String words, String lord) {

        if (name.length() == 0 || sigil.length() == 0 || words.length() == 0 || lord.length() == 0) {
            throw new RuntimeException("GreatHouse Constructor Illegal Argument");
        } else {
            this.name = name;
            this.sigil = sigil;
            this.words = words;
            this.lord = lord;
        }
    }

    public void addSoldier(Soldier soldier) {

        if (soldier != null) {
            army.add(soldier);
        } else {
            throw new RuntimeException("Null soldier");
        }
    }

    public Soldier getSoldier() {
        int size = army.size();
        for (int i = 0; i < size; i++) {
            Soldier a = (Soldier) army.get(i);
            if (a.getHealthCondition() > 0) {
                return a;
            }
        }
        throw new RuntimeException("getSoldier failed, Soldier/s dead");
    }

    //iterate array list and check for SoldiersHealth > 0
    public boolean isDefeated() {
        int size = army.size();
        for (int i = 0; i < size; i++) {
            Soldier a = (Soldier) army.get(i);
            if (a.getHealthCondition() > 0) {
                return false;
            }
        }
        return true;   
    }

    @Override
    public String toString() {
        return ("The GreatHouse of " + this.name + " has lord " + this.lord + ". Their sigil is a " + this.sigil + " and their words are " + this.words);
    }
}
