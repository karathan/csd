
package csd.uoc.gr.A13;


class MySet {
    private int MaxCapacity;
    private int[] elements;
    private int activeSize = 0;
    public int getCardinality() {return activeSize;}
    
    public void add(int x) throws Exception {
        if (!contains(x)) {
            if (activeSize <  MaxCapacity)
              elements[activeSize++]=x;
            else {
                throw new Exception("Sorry, but my memory is full.");
            }
        }
    }
    
    public boolean contains(int x) {
       boolean found = false;
       int i=0;
       while (i<activeSize) {
           if (elements[i]==x)
                found = true;
           i++;
       }
       return found;
    }
    
    MySet(int size) {
        MaxCapacity = size;
        elements = new int[MaxCapacity];
    }
}