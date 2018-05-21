package ex02.c;

import java.util.ArrayList;

class ItemNotInListException extends Exception {

    public ItemNotInListException() {
    }
}

public class Trampala implements WeightedThing {

    private int K;
    private int lWeight = 0, rWeight = 0;
    private int totalWeight = 0;
    ArrayList leftArray = new ArrayList();
    ArrayList rightArray = new ArrayList();

    @Override
    public int getVaros() {
        return getTotalWeight();
    }

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

    public void addLeft(WeightedThing w) {
        if(w.equals(this)){
            throw new RuntimeException("Trampala loaded to itself");
        }
        boolean tempbool = isBalanced();
        int temp = totalWeight + w.getVaros();

        lWeight += w.getVaros();
        totalWeight += w.getVaros();
        leftArray.add(w);

        if (tempbool && temp > K) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);

        } else if (isBroken()) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);
        } else {
            System.out.println("WeightedThing succesfully added");
        }

    }

    public void addRight(WeightedThing w) {
        if(w.equals(this)){
            throw new RuntimeException("Trampala loaded to itself");
        }
        boolean tempbool = isBalanced();
        int temp = totalWeight + w.getVaros();

        rWeight += w.getVaros();
        totalWeight += w.getVaros();
        rightArray.add(w);

        if (tempbool && temp > K) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);

        } else if (isBroken()) {
            System.out.println("Trampala just broke! SORRY");
            System.exit(-1);
        } else {
            System.out.println("WeightedThing succesfully added");
        }

    }

    public void removeLeft(WeightedThing w) throws ItemNotInListException {
        try {
            if (!leftArray.contains(w)) {
                throw new ItemNotInListException();
            }
        } catch (ItemNotInListException e) {
            System.out.println("WeightedThing doesnt exists and cannot be removed");
            System.exit(-1);
        }

        lWeight -= w.getVaros();
        totalWeight -= w.getVaros();
        int i = leftArray.indexOf(w);
        leftArray.remove(i);
        System.out.println("WeightedThing succesfully removed");
    }

    public void removeRight(WeightedThing w) throws ItemNotInListException {
        try {
            if (!rightArray.contains(w)) {
                throw new ItemNotInListException();
            }
        } catch (ItemNotInListException e) {
            System.out.println("WeightedThing doesnt exists and cannot be removed");
            System.exit(-1);
        }

        rWeight -= w.getVaros();
        totalWeight -= w.getVaros();
        int i = rightArray.indexOf(w);
        rightArray.remove(i);
        System.out.println("WeightedThing succesfully removed");

    }

    public boolean contains(WeightedThing w) {
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
            //System.out.println("Trampala is broken!");
            return true;
        } else if (!isBalanced() && (rWeight <= K || lWeight <= K)) {
            //System.out.println("Trampala is not broken!");
            return false;
        } else if (!isBalanced() && (rWeight > K && lWeight > K)) {
            //System.out.println("Trampala is broken!");
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
