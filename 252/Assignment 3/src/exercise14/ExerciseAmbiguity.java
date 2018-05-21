/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise14;

import java.util.function.Predicate;

/**
 *
 * @author mitsos
 */
public class ExerciseAmbiguity {
    
    private static void method(Predicate<Double> p){
        System.out.print("Predicate");
    }
    
    private static void method(DoublePredicate p){
        System.out.print("FloatPredicate");
    }
    
//    public static void main(String args[]){
//        method((x)->true);
//    }
    
    
    
    
    
}
