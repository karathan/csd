package ex03.weaponCarrier;

import ex03.weapon.Sword;
import ex03.weapon.Weapon;
import java.util.Random;

/**
 * Class Swordman
 *
 * @author
 */
public class Swordman extends Soldier {

    static Random rand = new Random();

    public Swordman(String firstName, String lastName) {
        super(firstName, lastName, rand.nextInt(10 - 5 + 1) + 5, 4);
    }

    public Swordman(String firstName, String lastName, int health) {
        super(firstName, lastName, health, 4);
    }

    @Override
    public String toString() {
        return ("The swordman " + this.getCallSign() + " has power " + this.getPower() + " and health " + this.getHealthCondition() + ".");
    }

    @Override
    public void setWeapon(Weapon weapon) {
        if ((weapon != null) && (weapon instanceof Sword)) {
            this.weapon = weapon;
            Weapon.setHolder(this);

        } else {
            System.out.println("Cannot assign weapon to Swordman!");
            System.exit(-1);
        }
    }

}
