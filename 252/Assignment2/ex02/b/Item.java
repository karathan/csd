package ex02.b;

public class Item {

    private String name;
    private int weight;

    public void setName(String name) {
        if(name instanceof String)
        this.name = name;
        else{
            System.out.println("Name must be string");
            System.exit(-1);
            
        }
    }

    public String getName() {
        return name;
    }

    public void setWeight(int weight) {
        if(weight>0)
        this.weight = weight;
        else{
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
