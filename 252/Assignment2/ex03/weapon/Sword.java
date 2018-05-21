package ex03.weapon;

import ex03.weaponCarrier.Swordman;
import java.util.Random;

/**
 * Class Sword
 *
 * @author
 */
public class Sword extends Weapon{
    
    static Random rand = new Random();
    
    public Sword(){
        super(rand.nextInt(4 - 3 + 1) + 3);
    }
    
    public Sword(int power){
        super(checkPower(power,"sword"));
    }
    
    @Override
    public String toString(){
        return "The sword has power " +super.getPower()+ " and is owned by " + super.getHolder();        
    }
    
    

}
