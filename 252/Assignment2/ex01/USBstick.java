package ex01;

public class USBstick extends StorageMedium {

    public USBstick(String name, int capacity) {
        super(name, capacity);
        this.Type = Type.FlashDrive;
    }
    
    @Override
    public String toString(){
        String str = super.toString();
        return ("USB Stick" + str);
        
    }

}
