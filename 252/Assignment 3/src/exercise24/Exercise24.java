/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise24;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author mitsos
 */
public class Exercise24 {

    public static void main(String[] a) {
        ArrayList<Integer> items = new ArrayList<>();
        System.out.print("Initial list: ");
        for (int i = 0; i < 10; i++) {
            items.add(new Random().nextInt(10));
            System.out.print(items.get(i) + " ");
        }
        System.out.print("\n");

        System.out.print("Numbers bigger than 5: ");
        items.stream().filter(s -> s > 5).forEach(s -> System.out.print(s + ","));

        System.out.print("\n");
        System.out.print("Numbers smaller than 5: ");
        items.stream().filter(s -> s < 5).forEach(s -> System.out.print(s + ","));
        System.out.print("\n");

        System.out.print("Numbers between 3 and 7 or equal to 1: ");

        items.stream().filter(s -> ((s > 3 && s < 7) || s == 1)).forEach(s -> System.out.print(s + ","));
        System.out.print("\n");
        
        
//        System.out.print("Numbers bigger than 5: ");
//        for (int i = 0; i < 10; i++) {
//            if (items.get(i) > 5) {
//                System.out.print(items.get(i) + " ");
//            }
//        }
//        System.out.print("\n");
//        System.out.print("Numbers smaller than 5: ");
//        for (int i = 0; i < 10; i++) {
//            if (items.get(i) < 5) {
//                System.out.print(items.get(i) + " ");
//            }
//        }
//        System.out.print("\n");
//        System.out.print("Numbers between 3 and 7 or equal to 1: ");
//        for (int i = 0; i < 10; i++) {
//            if ((items.get(i) > 3 && items.get(i) < 7) || items.get(i) == 1) {
//                System.out.print(items.get(i) + " ");
//            }
//        }
//        System.out.print("\n");
    }
}
