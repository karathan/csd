package ex02.c;

public class TrampalaClient {

    public static void main(String[] args) throws ItemNotInListException {
        
        Trampala a = new Trampala(30);
        Trampala b = new Trampala(30);
        Trampala c = new Trampala(30);
        Item item2 = new Item("kostas", 25);
        
        
        b.addLeft(b);       //add 25 to Trampala b (MaxLoad = 30) so its fine
        c.addRight(item2);      //add 25 to Trampala c (MaxLoad = 30) so its fine
        
        
        a.addRight(b);          //add b to the right side of Trampala a //its fine
        a.addLeft(c);           //add c to the left side of Trampala a  //its gonna break cause 25 + 25 > 30
        
    }
}
