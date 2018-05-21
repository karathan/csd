/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package csd.uoc.gr.A11;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class DrawZHtml {

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Give number: ");
        int value = scanner.nextInt();

        File file = new File("Z.html");

        try (Writer out = new OutputStreamWriter(new FileOutputStream(file))) {

            out.write("<!DOCTYPE html\n");
            out.write("<html>\n");
            out.write("<head>\n");
            out.write("<meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\" />\n");
            out.write("</head\n");
            out.write("<body>\n\n");
            out.write("<font size=\"");

            out.write(String.valueOf(value));

            out.write("\">Z</font>\n\n");
            out.write("</body\n");
            out.write("</html>");
            out.close();

        }

    }
}
