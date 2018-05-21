package ex01;

import java.util.Random;

public class CloudStorage {

    StorageMedium[] components = new StorageMedium[100];

    public void init() {

        int Low = 1000;
        int High = 100001;

        for (int i = 1; i <= 50; i++) {

            String name = "SM" + i;
            Random r = new Random();

            int capacity = r.nextInt(High - Low) + Low;
            StorageMedium a = new USBstick(name, capacity);
            components[i - 1] = a;
        }

        for (int i = 51; i <= 100; i++) {
            String name = "SM" + i;
            Random r = new Random();

            int capacity = r.nextInt(High - Low) + Low;
            StorageMedium a = new StorageMedium(name, capacity);
            components[i - 1] = a;

        }

        for (int i = 0; i < 100; i++) {
            String printable = components[i].toString();
            System.out.println(printable);
        }
    }

    public int getCapacity() {
        int capacity = 0;

        for (int i = 0; i < 100; i++) {
            capacity += components[i].getCapacity();
        }
        return capacity;
    }

}
