package ex04.model.classes;

public class Coin {

    private String name;
    private float price;

    public Coin(String name, float price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public float getPrice() {
        return price;
    }
}
