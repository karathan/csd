package ex02.b;

import java.util.ArrayList;

class ItemNotInListException extends Exception {

    public ItemNotInListException() {
    }
}

///////////////////////TODO/////////////////
//FINISH THE PDF WITH EXCEPTIONS AND INVARIANTS
//CHECK IF EVERYTHING IS WORKING PROPERLY (PRINTS)
//DO C)
public class Trampala {

    private int K;
    private int lWeight = 0, rWeight = 0;
    private int totalWeight = 0;
    ArrayList leftArray = new ArrayList();
    ArrayList rightArray = new ArrayList();

    public void setMaxLoad(int K) {
        if (K >= 0) {
            this.K = K;
        } else {
            System.out.println("MaxLoad given below zero, ERROR");
            System.exit(-1);
        }
    }

    public int getMaxLoad() {
        return K;
    }

    public void addLeft(Item w) {
        boolean tempbool = isBalanced();
        int temp = totalWeight + w.getWeight();

        lWeight += w.getWeight();
        totalWeight += w.getWeight();
        leftArray.add(w);

        if (tempbool && temp > K) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);

        } else if (isBroken()) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);
        } else {
            System.out.println("Item " + w.getName() + " succesfully added");
        }

    }

    public void addRight(Item w) {
        boolean tempbool = isBalanced();
        int temp = totalWeight + w.getWeight();

        rWeight += w.getWeight();
        totalWeight += w.getWeight();
        rightArray.add(w);

        if (tempbool && temp > K) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);

        } else if (isBroken()) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);
        } else {
            System.out.println("Item " + w.getName() + " succesfully added");
        }

    }

    public void removeLeft(Item w) throws ItemNotInListException {
        try {
            if (!leftArray.contains(w)) {
                throw new ItemNotInListException();
            }
        } catch (ItemNotInListException e) {
            System.out.println("Item" + w.getName() + "doesnt exists and cannot be removed");
            System.exit(-1);
        }

        lWeight -= w.getWeight();
        totalWeight -= w.getWeight();
        int i = leftArray.indexOf(w);
        leftArray.remove(i);
        System.out.println("Item " + w.getName() + " succesfully removed");
    }

    public void removeRight(Item w) throws ItemNotInListException {
        try {
            if (!rightArray.contains(w)) {
                throw new ItemNotInListException();
            }
        } catch (ItemNotInListException e) {
            System.out.println("Item" + w.getName() + "doesnt exists and cannot be removed");
            System.exit(-1);
        }

        rWeight -= w.getWeight();
        totalWeight -= w.getWeight();
        int i = rightArray.indexOf(w);
        rightArray.remove(i);
        System.out.println("Item " + w.getName() + " succesfully removed");

    }

    public boolean contains(Item w) {
        if (leftArray.contains(w) || rightArray.contains(w)) {
            //System.out.println("Trampala contains " + w.getName());
            return true;
        } else {
            //System.out.println("Trampala doesn't contains " + w.getName());
            return false;
        }
    }

    public boolean isBalanced() {
        if (rWeight == lWeight) {
            //System.out.println("Trampala is balanced");
            return true;
        }

        //System.out.println("Trampala is not balanced");
        return false;

    }

    public boolean isBroken() {
        if (isBalanced() && totalWeight > K) {
          //  System.out.println("Trampala is broken!");
            return true;
        } else if (!isBalanced() && (rWeight <= K || lWeight <= K)) {
            //System.out.println("Trampala is not broken!");
            return false;
        } else if (!isBalanced() && (rWeight > K && lWeight > K)) {
           // System.out.println("Trampala is broken!");
            return true;
        } else {
            //System.out.println("Trampala is not broken!");
            return false;
        }
    }

    public int getTotalWeight() {
        return totalWeight;
    }

    public Trampala(int MaxLoad) throws IllegalArgumentException {
        if (MaxLoad > 0) {
            setMaxLoad(MaxLoad);
            this.totalWeight = 0;
            this.lWeight = 0;
            this.rWeight = 0;
        } else {
            throw new IllegalArgumentException("MaxLoad can only be positive!");
        }
    }
}
