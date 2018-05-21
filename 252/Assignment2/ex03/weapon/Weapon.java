package ex03.weapon;

import ex03.weaponCarrier.WeaponCarrier;

/**
 * Abstract class Weapon
 *
 * @author
 */
public abstract class Weapon {

    private final int power;
    public static WeaponCarrier holder = null;

    Weapon(int power) {
        this.power = power;
    }

    public int getPower() {
        return power;
    }

    public static void setHolder(WeaponCarrier holder) {
        Weapon.holder = holder;
    }

    WeaponCarrier getHolder() {
        return holder;
    }

    @Override
    public abstract String toString();
    //return "WeaponHolder: " + getHolder() + "power: " + getPower();

    public static int checkPower(int power, String derivedClass) {
        if ("arc".equals(derivedClass)) {
            if (power == 1 || power == 2) {
                return power;
            }
            throw new RuntimeException("Illegal power for Arc");

        } else if ("sword".equals(derivedClass)) {
            if (power == 3 || power == 4) {
                return power;
            }

            throw new RuntimeException("Illegal power for Sword");

        }

        return -100;
    }
}
