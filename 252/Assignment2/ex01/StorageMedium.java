package ex01;

public class StorageMedium {

    private String name;
    private int capacity;
    public Type Type;

    public String getName() {
        return (name);
    }

    public int getCapacity() {
        return (capacity);
    }

    public StorageMedium(String name, int capacity) {
        this.Type = Type.HD;
        this.name = name;
        this.capacity = capacity;
    }

    @Override
    public String toString() {
        name = getName();
        capacity = getCapacity();

        return ("Αποθηκευτικό Μέσο: " + this.getName() + ", χωρητικότητα: " + this.getCapacity() + " bytes, Τύπος: " + this.Type);

    }

}
