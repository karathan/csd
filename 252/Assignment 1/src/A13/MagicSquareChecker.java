package csd.uoc.gr.A13;

import java.util.Scanner;

public class MagicSquareChecker {

    private static int sumOfRow(int[][] s, int k) {

        int sum = 0;

        for (int i = 0; i < s.length; i++) {
            sum += s[k][i];
        }

        return sum;
    }

    ;
    
    private static int sumOfColumn(int[][] s, int k) {

        int sum = 0;

        for (int i = 0; i < s.length; i++) {
            sum += s[i][k];
        }

        return sum;

    }

    ;
    
    
    private static int sumOfDiagonal1(int[][] s) {

        int sum = 0;

        for (int i = 0; i < s.length; i++) {
            sum += s[i][i];
        }

        return sum;
    }

    ;
    
    
   private static int sumOfDiagonal2(int[][] s) {

        int sum = 0;
        int j = s.length;

        for (int i = 0; i < s.length; i++) {
            j--;
            sum += s[i][j];
        }

        return sum;

    }

    ;
   
   
   public static int getMagicNumber(int[][] s) {
        return MagicSquareChecker.sumOfDiagonal1(s);
    }

    ;
   
   
   private static boolean hasDuplicates(int[][] s) throws Exception {

        MySet checker = new MySet(s.length * s.length);

        for (int i = 0; i < s.length; i++) {
            for (int j = 0; j < s.length; j++) {

                if (checker.contains(s[i][j])) {
                    System.out.println(+s[i][j]+ "Found it more than once");
                    return true;
                } else {
                    checker.add(s[i][j]);
                }

            }
        }

        return false;
    }

    ;
    
   
    public static boolean checkIsMagic(int[][] s) {

        boolean flag = true;
        int[] Magic = new int[s.length * s.length];

        for (int i = 0; i < s.length; i++) {
            Magic[i] = MagicSquareChecker.sumOfRow(s, i);

            Magic[i + s.length] = MagicSquareChecker.sumOfColumn(s, i);
        }

        Magic[s.length * 2] = MagicSquareChecker.sumOfDiagonal1(s);

        Magic[(s.length * 2) + 1] = MagicSquareChecker.sumOfDiagonal2(s);

        for (int i = 1; i < ((s.length + s.length) + 2); i++) {
            if (Magic[0] != Magic[i]) {
                flag = false;
            }
        }
        return flag;
    }

    public static void main(String[] args) throws Exception {

        Scanner in = new Scanner(System.in);
        int n, m;
        boolean finalCheck = false;

        do {
            System.out.print("Please enter a number between 2-10: ");
            n = in.nextInt();

        } while (n < 2 || n > 10);

        int[][] array = new int[n][n];
        MySet set = new MySet(array.length * array.length);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Give me next number to fill the square: ");
                m = in.nextInt();
                if (!set.contains(m)) {
                    set.add(m);
                    array[i][j] = m;
                } else {
                    System.out.println("You gave " +m+ " two times, SORRY");
                    return;
                }
            }
        }

        finalCheck = checkIsMagic(array);

        if (finalCheck) {
            int MagicNumber = MagicSquareChecker.getMagicNumber(array);
            System.out.println("Square is Magic, MagicNumber = " + MagicNumber);
        } else {
            System.out.println("Square is NOT Magic, SORRY");
        }
    }

}
