package csd.uoc.gr.A14;

import csd.uoc.gr.A13.MagicSquareChecker;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.URL;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class MagicSquareCheckerFile {

    static int download(String address) {
        String content = "";

        try {
            URL url = new URL(address);
            BufferedReader in = new BufferedReader(new InputStreamReader(url.openStream(), "UTF-8"));
            int c = in.read();
            while (c != -1) {
                content += (char) c;
                //System.out.print((char) c);
                c = in.read();
            }
            PrintWriter bwr = new PrintWriter(new BufferedWriter(new FileWriter("magicFile.txt")));
            bwr.write(content);
            bwr.close();
        } catch (Exception e) {
            System.out.println(e);
            return -1;
        }
        return 0;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {

        int s, s1, r;
        int arrayLength = 0;

        int value = Integer.parseInt(JOptionPane.showInputDialog("Give 0 for localFile, 1 for URL", 0));
        File file = null;
        String filepath;
        if (value == 0) {
            JFileChooser fileChooser = new JFileChooser();
            fileChooser.setDialogTitle("Select a file");
            int userSelection = fileChooser.showSaveDialog(null);

            if (userSelection == JFileChooser.APPROVE_OPTION) {
                file = fileChooser.getSelectedFile();
                filepath = file.getAbsolutePath();
                System.out.println("The path of the selected file is: " + filepath);
            }
        } else {
            String toDownload = JOptionPane.showInputDialog("Δωστε την διευθυνση ", "");
            download(toDownload);
            file = new File("magicFile.txt");

        }
        BufferedReader in = new BufferedReader(new FileReader(file));

        s = in.read();
        while (s != 10) {
            if (s == 32) {
                s = in.read();
            } else {
                arrayLength++;
                s = in.read();
            }
        }
        int[][] input = new int[arrayLength][arrayLength];

        try (BufferedReader in1 = new BufferedReader(new FileReader(file))) {
            s1 = in1.read();

            for (int i = 0; i < arrayLength; i++) {
                for (int j = 0; j < arrayLength; j++) {
                    while (s1 != -1) {
                        if (s1 == 32 || s1 == 10) {
                            s1 = in1.read();
                        } else {
                            int c = Character.getNumericValue(s1);
                            input[i][j] = c;
                            s1 = in1.read();
                            break;
                        }

                    }

                }
            }

        }

        boolean flag = MagicSquareChecker.checkIsMagic(input);
        int MagicNumber = MagicSquareChecker.getMagicNumber(input);

        if (flag) {
            System.out.println("Square is Magic, MagicNumber = " + MagicNumber);
        } else {
            System.out.println("Square is NOT Magic, SORRY");
        }

        if (flag) { //edw mpainei otan einai magicBox kai thelw na kanw to erwtima γ

            JFileChooser chooserOutput = new JFileChooser();
            chooserOutput.setDialogTitle("ChooseDirectory");
            chooserOutput.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
            int userSelection1 = chooserOutput.showSaveDialog(null);
            if (userSelection1 == JFileChooser.APPROVE_OPTION) {
                File file1 = chooserOutput.getSelectedFile();
                String filepath1 = file1.getAbsolutePath();

                PrintWriter bwr = new PrintWriter(new BufferedWriter(new FileWriter(filepath1 + '/' + "MagicSquareSavedFile.txt")));

                BufferedReader f1 = new BufferedReader(new FileReader(file));

                r = f1.read();

                while (r != -1) {
                    bwr.write(r);
                    r = f1.read();
                }

                bwr.write('\n');
                bwr.write('\n');
                bwr.write("Μαγικό τετράγωνο με μαγικό αριθμό ");
                bwr.write(String.valueOf(MagicNumber));
                bwr.close();
            }
        }
    }

}
