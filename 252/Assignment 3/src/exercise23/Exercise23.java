/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise23;

import java.util.ArrayList;

/**
 *
 * @author mitsos
 */
public class Exercise23 {

    public static void main(String[] args) {
        ArrayList<Double> items = new ArrayList<>();
        items.add(9.56);
        items.add(-4.28);
        items.add(5.14);
        items.add(-1.75);

        double sum = items.stream().reduce(0d,(a,b)-> a+b); 
        System.out.println("Sum = "+ sum/4);
        
    }

}
