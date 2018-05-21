/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise21;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;

/**
 *
 * @author mitsos
 */
public class Exercise21 {

    private static double randomNumber() {
        return Math.random();
    }

    public static void main(String[] args) {
        JButton showDialogButton = new JButton();
        JFrame frame = new JFrame();
        showDialogButton.addActionListener((ActionEvent e) -> {
            JDialog dialog = new JDialog(frame, "Hello Java 8!", true);
            dialog.setLocationRelativeTo(frame);
            dialog.setVisible(true);
        });

        final double num = randomNumber();
        JButton button = new JButton();

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ((JButton) (e.getSource())).setText((new Double(num)).toString());
            }
        });
    }
}
