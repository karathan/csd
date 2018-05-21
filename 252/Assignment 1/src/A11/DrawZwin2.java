/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package csd.uoc.gr.A11;

import javax.swing.JOptionPane;

public class DrawZwin2 {

    public static void main(String[] args) {

        StringBuffer a = new StringBuffer("");
        int value = Integer.parseInt(JOptionPane.showInputDialog("Give me a number", 4));

        int i, j;
        while (value >= 4 && value <= 30) {
            j=1;
            for (i = 1; i <= value; i++) {
                a.append(j);
            }
            a.append("\n");
            for (i = 1; i <= value - 2; i++) {
                for (j = 0; j < value - i; j++) {
                    a.append("_");
                }
                a.append(i + 1);
                
                a.append("\n");
            }
            j = value;
            for (i = 0; i < value; i++) {
                a.append(j);
            }

            a.append("\n");

            JOptionPane.showMessageDialog(null, a, "Παράθυρο Εξόδου ", JOptionPane.INFORMATION_MESSAGE);

            int x = a.length();
            a.delete(0, x);
            value = Integer.parseInt(JOptionPane.showInputDialog("Give me a number", 4));
        }

        JOptionPane.showMessageDialog(null, "Λειτουργώ μόνο για τιμές απο 4 έως 30", "DrawZwin2", JOptionPane.ERROR_MESSAGE);

    }

}
