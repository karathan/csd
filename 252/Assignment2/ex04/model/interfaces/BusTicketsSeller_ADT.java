package ex04.model.interfaces;

import ex04.model.classes.BusTicketSeller_State;
import ex04.model.classes.BusTicketsSeller;
import ex04.model.classes.Card;
import ex04.model.classes.Coin;
import ex04.model.classes.Ticket;
import java.util.ArrayList;

/**
 * Specification of an ADT for selling bus tickets Status: exceptions are
 * missing
 */
public interface BusTicketsSeller_ADT {

    /**
     *Inserts a coin in the machine
     * 
     * Precondition: c is a valid instance of Coin
     * Postcondition: Coin c is inserted properly
     * @param c
     */
    void insertCoin(Coin c);

    /**
     *Selects the ticket t
     * 
     * Precondition: t is a valid instance of Ticket
     * PostCondition: Ticket t is selected properly
     * @param t
     */
    void selectTicket(Ticket t);

    /**
     *Inserts a card in the machine
     * 
     * Precondition: cd is a valid instance of Card
     * Postcondition: Card cd is inserted properly
     * @param cd
     */
    void insertCard(Card cd);

    /**
     *Depending on the current state
     * calls methods and changes states
     * Precondition:
     * Postcondition: Change state and call methods properly
     */
    void finish();

    /**
     *Returning to default state
     * calling specific methods in between
     * Precondition:
     * Postcondition: Return to default state(Idle)
     */
    void cancel();

    /**
     *Prints proper message for changes
     * Precondition:
     * Postcondition:
     */
    void returnChange();

    /**
     *Prints proper message for delivery
     * Precondition:
     * Postcondition:
     */
    void deliverTicket();

    /**
     *Prints proper message for money return
     * Precondition:
     * Postcondition:
     */
    void returnMoney();

    /**
     *Withdraws money from card
     * 
     * Precondition:
     * Postcondition: Card balance is properly set
     */
    void withdrawCostFromCard();

    /**
     *Prints proper message for card removal
     * Precondition:
     * Postcondition:
     */
    void takeOutCard();
    
    /**
     *
     * *Prints proper message for returning coins
     * Precondition:
     * Postcondition:
     */
    void returnCoins();
    
    /**
     *
     * Prints proper messages letting us know
     * all the details of the current state, variables etc
     * 
     * Precondition:
     * Postcondition:
     */
    void updateDisplay();
    
    /**
     *
     * @return The current enum state that why are in
     */
    BusTicketSeller_State getFullState();
    
    /**
     *
     * @return state in String!!
     */
    String getFullStateNew();
    
    /**
     *
     * @return The current ticket
     */
    Ticket getTicket();
    
    /**
     *
     * @return The current ticket name
     */
    String getName();
    
    /**
     *Returns the sum of the coins inserted
     * 
     * Precondition: coinsList is a valid instance of ArrayList
     * Postcondition: returns the proper sum of the float ArrayList
     * @param coinsList
     * @return The sum (float) of coinsList
     */
    float totalCoinsInserted(ArrayList coinsList);
    
    /**
     *Helping function to access totalCoinsInserted function
     * 
     * 
     * @return The sum(float) of coinsList
     */
    float getPrice();

}
