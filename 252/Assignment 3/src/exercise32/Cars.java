/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise32;

import exercise31.Car;
import exercise31.CarFactory;
import java.util.ArrayList;
import java.util.Comparator;

/**
 *
 * @author mitsos
 */
public class Cars {
    
    
        public static void main(String args[]) {
        CarFactory<Car> cf = Car::new;
        ArrayList<Car> list = new ArrayList<>();
        list.add(cf.create("918 Spyder", "Porche", "Germany", 340, 2.2, 2014));
        list.add(cf.create("Model S P100D", "Tesla", "USA", 250, 2.28, 2016));
        list.add(cf.create("Chiron", "Bugatti", "France", 420, 2.3, 2017));
        list.add(cf.create("LaFerrari", "Ferrari", "Italy", 349, 2.4, 2015));
        list.add(cf.create("Veyron", "Bugatti", "France", 407, 2.5, 2006));
        list.add(cf.create("991 Turbo S", "Porche", "Germany", 331, 2.5, 2016));
        list.add(cf.create("Huracan", "Lamborghini", "Italy", 341, 2.5, 2015));
        list.add(cf.create("R8 V10 Plus", "Audi", "Germany", 330, 2.6, 2016));
        
        
        
        Comparator<Car> byAcceleration = (c1,c2) -> Double.compare(c1.getAcceleration(),
                c2.getAcceleration());
        
        
        list.stream().sorted(byAcceleration).forEach(e->System.out.println(e));
        }
    
    
}
