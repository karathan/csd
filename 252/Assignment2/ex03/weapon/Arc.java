package ex03.weapon;

import java.util.Random;

/**
 * Class Arc
 *
 * @author
 */
public class Arc extends Weapon{
    
    static Random rand = new Random();
    
    public Arc(){
        super(rand.nextInt(2 - 1 + 1) + 1);
    }
    
    
    public Arc(int power){
        super(checkPower(power,"arc"));
        super.holder = null;
    }
    
     @Override
    public String toString(){
        return "The arc has power " +super.getPower()+ " and is owned by " +super.getHolder();        
    }

}
