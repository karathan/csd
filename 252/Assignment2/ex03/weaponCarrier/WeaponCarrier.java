package ex03.weaponCarrier;

import ex03.weapon.Weapon;

/**
 * Abstract class WeaponCarrier
 *
 * @author
 */
public abstract class WeaponCarrier {

    Weapon weapon;

    public WeaponCarrier() {
        weapon = null;
    }

    public Weapon getWeapon() {
        return weapon;
    }

    public abstract void setWeapon(Weapon weapon);

    public boolean hasWeapon() {
        return weapon != null;

    }

}
