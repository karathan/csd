package ex04.guiClient;

import static ex04.model.classes.BusTicketSeller_State.Idle;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.ImageIcon;

import ex04.model.classes.BusTicketsSeller;
import ex04.model.classes.Coin;
import ex04.model.classes.Ticket;
import ex04.model.interfaces.BusTicketsSeller_ADT;

/*
 * The class APPLICATION simulates (through a GUI) the physical part of a bus ticket selling machine.
 * It sends and receives messages to the Model part of the application. 
 * (the model part of the application does not depend on the gui).
 */
// CoinButton can hold a reference to a Coin
// We define it as a class for creating buttons for several coins
class CoinButton extends JButton implements ActionListener {

    Coin c;

    @Override
    public void actionPerformed(java.awt.event.ActionEvent e) { // called on click
        System.out.println(c);
        APPLICATION.bts.insertCoin(c); // calls the corresponding method of the model
        APPLICATION.updateDisplay();   // updates the display
    }

    CoinButton(Coin c, String image) {
        super(c.getName());
        this.c = c;
        this.addActionListener(this);	// for managing itself the clicks

        //Add the image to the button
        Image newimg = new ImageIcon(image).getImage().getScaledInstance(
                30, 30, java.awt.Image.SCALE_SMOOTH);
        this.setIcon(new ImageIcon(newimg));
    }
}

//TicketButton can hold a reference to a Ticket
//We define it as a class for creating buttons for several kinds of tickets
class TicketButton extends JButton implements ActionListener {

    Ticket t;

    public void actionPerformed(java.awt.event.ActionEvent e) {
        System.out.println(t);
        APPLICATION.bts.selectTicket(t);  // calls the corresponding method of the model
        APPLICATION.updateDisplay();
    }

    TicketButton(Ticket t, String image) {
        super(t.getName());
        this.t = t;
        this.addActionListener(this);

        Image newimg = new ImageIcon(image).getImage().getScaledInstance(
                30, 30, java.awt.Image.SCALE_SMOOTH);
        this.setIcon(new ImageIcon(newimg));

    }
}

// This the class with the main that starts the application
public class APPLICATION extends JFrame {

    static final String appName = "BUS TICKET SELLER v0.1 Application";

    static BusTicketsSeller_ADT bts;   // only one instance is needed   

    static CoinButton coin5cents, coin10cents, coin20cents, coin50cents, coin1Euro, coin2Euro;   // coin buttons
    static TicketButton ticketStudent, ticketOlokliro, ticketPolytekniko; // ticketStudent
    static JLabel displayArea, displayAreaNew;  // for displaying the status
    static JButton cancelButton; // the cancel button
    static JButton finishButton; // the finish button

    // it creates all coin buttons
    void createCoinButtons() {

        coin5cents = new CoinButton(new Coin("5 cents", 0.05F), "./resources/images/Five_cent.jpg");
        add(coin5cents);
        coin10cents = new CoinButton(new Coin("10 cents", 0.1F), "./resources/images/Ten_cent.jpg");
        add(coin10cents);
        coin20cents = new CoinButton(new Coin("20 cents", 0.2F), "./resources/images/Twenty_cent.jpg");
        add(coin20cents);
        coin50cents = new CoinButton(new Coin("50 cents", 0.5F), "./resources/images/Fifty_cent.jpg");
        add(coin50cents);
        coin1Euro = new CoinButton(new Coin("1 Euro", 1F), "./resources/images/One_euro.jpg");
        add(coin1Euro);
        coin2Euro = new CoinButton(new Coin("2 Euro", 2F), "./resources/images/Two_euro.jpg");
        add(coin2Euro);
        // students could complete this with the rest coins
    }

    // it creates all ticket buttons
    void createTicketButtons() {

        ticketOlokliro = new TicketButton(new Ticket("Olokliro", 2F), "./resources/images/Olokliro.jpg");
        add(ticketOlokliro);
        ticketStudent = new TicketButton(new Ticket("Foititiko", 1.5F), "./resources/images/Foititiko.jpg");
        add(ticketStudent);
        ticketPolytekniko = new TicketButton(new Ticket("Polytekniko", 1F), "./resources/images/Politekniko.jpg");
        add(ticketPolytekniko);
        // students should complete this with the rest types of tickets

    }

    // creates the rest buttons (cancel, finish, display area)
    void createOtherButtons() {
        // cancelButton = new JButton("Cancel") {
        cancelButton = new JButton("Cancel");
        cancelButton.setBackground(Color.RED);
        cancelButton.setOpaque(true);
        cancelButton.addActionListener(new ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                System.out.println("Cancel");
                APPLICATION.bts.cancel();  // calls the corresponding method of the model
                APPLICATION.updateDisplay();
            }
        });
        add(cancelButton);

        finishButton = new JButton("Finish");
        finishButton.setBackground(Color.GREEN);
        finishButton.setOpaque(true);
        finishButton.addActionListener(new ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                System.out.println("Finish");
                APPLICATION.bts.finish();  // calls the corresponding method of the model
                APPLICATION.updateDisplay();
            }
        });
        add(finishButton);

        displayArea = new JLabel("Anoixame kai sas perimenoyme!!!");
        add(displayArea);

        displayAreaNew = new JLabel("<html>TicketNotEntered, CoinsNotEntered<br></html>");
        add(displayAreaNew);
        //displayAreaNew.setText(bts.getFullStateNew());

    }

    static void updateDisplay() {

        displayArea.setText("Katastasi: " + bts.getFullState());
        if (bts.getTicket() == null && bts.getPrice() == 0.f) {
            displayAreaNew.setText("<html>TicketNotEntered, CoinsNotEntered<br></html>");
        } else if (bts.getTicket() != null && bts.getPrice() != 0.f) {
            displayAreaNew.setText("<html>Ticket:" + bts.getName() + ", Coins:" + bts.getPrice() + "<br></html>");
        } else if (bts.getFullState() == Idle && bts.getTicket() != null) {
            displayAreaNew.setText("<html>Ticket:" + bts.getName() + " delivered!<br>Changes: " + bts.getPrice() + "</html>");
        } else if (bts.getTicket() == null && bts.getPrice() != 0.f) {
            displayAreaNew.setText("<html>TicketNotEntered, Coins: "+bts.getPrice()+"<br></html>");

        }
    }

        APPLICATION() {
            // CORE PART
            bts = new BusTicketsSeller(10);  // 10 =  stock of tickets

            // GUI PART: size, layout, title
            setBounds(100, 100, 900, 200);  //x,  y,  width,  height)
            setLayout(new GridLayout(6, 15)); // rows, columns
            setVisible(true);
            setTitle(appName);

            // GUI PART:  calling the methods that create buttons
            createCoinButtons();
            createTicketButtons();
            createOtherButtons();
            setVisible(true);
            // that's all
        }

    

    public static void main(String[] args) {
        System.out.println(appName);
        APPLICATION app = new APPLICATION();
    }
}
