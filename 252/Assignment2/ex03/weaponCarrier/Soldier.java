package ex03.weaponCarrier;

import ex03.exceptions.DeadWarriorException;
import ex03.exceptions.WarriorAttackHisselfException;
import ex03.warrior.Warrior;

/**
 * Abstract class Soldier
 *
 * @author
 */
public abstract class Soldier extends WeaponCarrier implements Warrior {

    final String firstName;
    final String lastName;
    int health;
    final int power;

    public Soldier(String firstName, String lastName, int health, int power) {

        if (firstName.length() == 0 || lastName.length() == 0) {
            System.out.println("Empty first or last Name forbidden");
            System.exit(-1);
        }
        this.health = health;
        this.firstName = firstName;
        this.lastName = lastName;
        this.power = power;

    }

    @Override
    public void setHealthCondition(int condition) {
        this.health = condition;
    }

    @Override
    public int getHealthCondition() {
        return health;
    }

    @Override
    public boolean isDefeated() {
        return health <= 0;
    }

    @Override
    public String getCallSign() {
        return this.firstName + this.lastName;
    }

    @Override
    public int getPower() {
        return power;
    }

    @Override
    public abstract String toString();

    @Override
    public void attack(Warrior adversary) throws DeadWarriorException, WarriorAttackHisselfException {
        try {
            if ((this.health) > 0) {

                int damage = getPower();
                if (this.hasWeapon()) {
                    damage += super.getWeapon().getPower();
                }

                adversary.setHealthCondition(adversary.getHealthCondition() - damage);

                System.out.println("Warrior " + this.getCallSign() + " attacked " + adversary.getCallSign() + ". New health= " + adversary.getHealthCondition());

            } else if(adversary.equals(this)){
                throw new WarriorAttackHisselfException("WarriorAttackHisselfException");
                
            }else{
                throw new DeadWarriorException("DeadWarriorException");
            }
        } catch (DeadWarriorException e) {
            System.out.println(e);

        }
    }
}
