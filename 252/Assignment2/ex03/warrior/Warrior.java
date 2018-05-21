package ex03.warrior;


import ex03.exceptions.DeadWarriorException;
import ex03.exceptions.WarriorAttackHisselfException;

/**
 * Interface Warrior
 *
 * @author
 */
public interface Warrior {

    void attack(Warrior adversary) throws DeadWarriorException, WarriorAttackHisselfException;

    boolean isDefeated();

    int getHealthCondition();

    void setHealthCondition(int condition);

    int getPower();

    String getCallSign();

}
