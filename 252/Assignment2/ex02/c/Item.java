package ex02.c;

public class Item implements WeightedThing {

    private String name;
    private int weight;
    
    
    @Override
    public int getVaros(){
        return getWeight();     
    }

    public void setName(String name) {
        if (name instanceof String) {
            this.name = name;
        } else {
            System.out.println("Name must be string");
            System.exit(-1);

        }
    }

    public String getName() {
        return name;
    }

    public void setWeight(int weight) {
        if (weight > 0) {
            this.weight = weight;
        } else {
            System.out.println("Negative or zero weight of Item");
            System.exit(-1);
        }
    }

    public int getWeight() {
        return weight;
    }

    public Item(String name, int weight) {
        setName(name);
        setWeight(weight);
    }

}
