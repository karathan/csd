package ex03.weaponCarrier;

import ex03.weapon.Arc;
import ex03.weapon.Weapon;
import java.util.Random;

/**
 * Class Archer
 *
 * @author
 */
public class Archer extends Soldier {

    static Random rand = new Random();

    public Archer(String firstName, String lastName) {
        super(firstName, lastName, rand.nextInt(5 - 1 + 1) + 1, 2);
    }

    public Archer(String firstName, String lastName, int health) {
        super(firstName, lastName, health, 2);
    }

    @Override
    public void setWeapon(Weapon weapon) {
        if ((weapon != null) && (weapon instanceof Arc)) {
            this.weapon = weapon;
            Weapon.setHolder(this);
        } else {
            System.out.println("Cannot assign weapon to Archer!");
            System.exit(-1);
        }
    }

    @Override
    public String toString() {
        return ("The archer " + this.getCallSign() + " has power " + this.getPower() + " and health " + this.getHealthCondition() + ".");
    }

}
