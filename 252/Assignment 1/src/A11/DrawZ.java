/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package csd.uoc.gr.A11;

import java.util.Scanner;

public class DrawZ {

    public static void main(String[] args) {

        
        int value = Integer.parseInt(args[0]);
        Scanner scanner = new Scanner(System.in);
        int i, j;
        while (value >= 4 && value <= 30) {
                
            for (i = 0; i < value; i++) {
                System.out.print('*');
            }
            System.out.println();

            for (i = 1; i <= value - 2; i++) {
                for (j = 0; j < value - 1 - i; j++) {
                    System.out.print(' ');
                }
                System.out.println('*');
            }

            for (i = 0; i < value; i++) {
                System.out.print('*');
            }

            System.out.println();
            System.out.print("Give number: ");
            value = scanner.nextInt();
        }

    }
}
