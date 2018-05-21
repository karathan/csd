/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package csd.uoc.gr.A11;

import javax.swing.JOptionPane;

public class DrawZwin {

    public static void main(String[] args) {

        StringBuffer a = new StringBuffer("");
        int value = Integer.parseInt(JOptionPane.showInputDialog("Give me a number", 4));

        int i, j;
        while (value >= 4 && value <= 30) {
            for (i = 0; i < value; i++) {
                a.append("*");
            }
            a.append("\n"); 
            for (i = 1; i <= value - 2; i++) {
                for (j = 0; j < value - i; j++) {
                    a.append(" "); 
                }
                a.append("*\n");  
            }

            for (i = 0; i < value; i++) {
                a.append("*"); 
            }

            a.append("\n");

            JOptionPane.showMessageDialog(null, a, "Παράθυρο Εξόδου ", JOptionPane.INFORMATION_MESSAGE);
            
            int x = a.length();
            a.delete(0, x);
            value = Integer.parseInt(JOptionPane.showInputDialog("Give me a number", 4));
        }

        JOptionPane.showMessageDialog(null, "Λειτουργώ μόνο για τιμές απο 4 έως 30", "DrawZwin", JOptionPane.ERROR_MESSAGE);

    }

}
