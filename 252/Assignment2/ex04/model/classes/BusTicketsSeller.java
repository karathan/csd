package ex04.model.classes;

import ex04.model.interfaces.BusTicketsSeller_ADT;
import java.util.ArrayList;

/**
 * An implementation of the BusTicketsSeller_ADT specification.
 */
public class BusTicketsSeller implements BusTicketsSeller_ADT {

    private int Stock;
    public Ticket ticket = null;
    public Coin coins;
    public Card card;
    public BusTicketSeller_State state;
    ArrayList<Coin> coinsList = new ArrayList();
    
    Ticket ticket1 = ticket;
    
    public Ticket getTicket(){
        return ticket;
    }
    
    @Override
    public String getName() {
        return ticket.getName();
    }
    
    public float getPrice(){
        return totalCoinsInserted(coinsList);
        
    }
    
    public BusTicketsSeller(int Stock) {

        this.Stock = Stock;
        this.state = BusTicketSeller_State.Idle;
    }
    

    @Override
    public void insertCoin(Coin c) {
        coinsList.add(c);

        switch (state) {

            case Idle:
                state = BusTicketSeller_State.MoneyEntered;
                updateDisplay();
                break;

            case MoneyEntered:
                updateDisplay();
                break;

            case TicketSelected:
                state = BusTicketSeller_State.TicketAndMoneyEntered;
                updateDisplay();
                break;

            default:
        }
    }

    @Override
    public void selectTicket(Ticket t) {
        this.ticket = t;

        switch (state) {
            case Idle:
                state = BusTicketSeller_State.TicketSelected;
                updateDisplay();
                break;

            case TicketSelected:
                state = BusTicketSeller_State.TicketSelected;
                updateDisplay();
                break;

            case CardEntered:
                state = BusTicketSeller_State.TicketAndCardEntered;
                updateDisplay();
                break;

            case MoneyEntered:
                state = BusTicketSeller_State.TicketAndMoneyEntered;
                updateDisplay();
                break;

            default:
        }

    }

    @Override
    public void insertCard(Card cd) {

        this.card = cd;

        switch (state) {

            case Idle:
                state = BusTicketSeller_State.CardEntered;
                updateDisplay();
                break;

            case TicketSelected:
                state = BusTicketSeller_State.TicketAndCardEntered;
                updateDisplay();
                break;

            default:

        }

    }

    @Override
    public void finish() {

        switch (state) {

            case TicketAndMoneyEntered:
                state = BusTicketSeller_State.Idle;

                if (totalCoinsInserted(coinsList) >= ticket.getPrice() && Stock > 0) {
                    returnChange();
                    deliverTicket();
                    Stock--;
                } else if (totalCoinsInserted(coinsList) >= ticket.getPrice() || Stock > 0) {
                    returnMoney();
                }
                coinsList.clear();
                //ticket = null;
                ticket1 = null;
                updateDisplay();
                coinsList.clear();
                break;

            case TicketAndCardEntered:
                state = BusTicketSeller_State.Idle;

                if (card.getBalance() >= ticket.getPrice() && Stock > 0) {
                    withdrawCostFromCard();
                    takeOutCard();
                    deliverTicket();
                    Stock--;
                } else if (card.getBalance() >= ticket.getPrice() || Stock > 0) {
                    takeOutCard();
                }

                updateDisplay();
                break;

            default:
        }

    }

    @Override
    public void cancel() {

        switch (state) {
            case TicketAndMoneyEntered:
                state = BusTicketSeller_State.Idle;
                returnCoins();
                coinsList.clear();
                ticket = null;
                updateDisplay();
                break;

            case MoneyEntered:
                state = BusTicketSeller_State.Idle;
                returnCoins();
                coinsList.clear();
                updateDisplay();
                break;

            case TicketAndCardEntered:
                state = BusTicketSeller_State.Idle;
                takeOutCard();
                updateDisplay();
                break;

            case CardEntered:
                state = BusTicketSeller_State.Idle;
                takeOutCard();
                updateDisplay();
                break;

            default:

        }
    }

    @Override
    public void returnChange() {
        System.out.println((totalCoinsInserted(coinsList) - ticket.getPrice()) + " changes returned!");
    }

    @Override
    public void deliverTicket() {
        System.out.println(ticket.getName() + " delivered, THANK YOU!");

    }

    @Override
    public void returnMoney() {
        System.out.println(totalCoinsInserted(coinsList) + " money returned!");

    }

    @Override
    public void withdrawCostFromCard() {
        card.setBalance(card.getBalance() - ticket.getPrice());
    }

    @Override
    public void takeOutCard() {
        System.out.println("Card removed!");
    }

    @Override
    public void returnCoins() {
        System.out.println(totalCoinsInserted(coinsList) + " coins returned!");
    }

    @Override
    public void updateDisplay() {
        if (ticket1 != null) {
            System.out.println("State: " + getFullState().toString() + ", Ticket: " + ticket.getName() + " selected, Price: " + ticket.getPrice() + ", CoinsEntered: " + totalCoinsInserted(coinsList) + ", Changes: " + (totalCoinsInserted(coinsList) - ticket.getPrice()));
        } else {
            System.out.println("State: " + getFullState().toString() + ", Ticket not entered, CoinsEntered :" + totalCoinsInserted(coinsList) + ", Changes: " + totalCoinsInserted(coinsList));
        }
    }

    @Override
    public BusTicketSeller_State getFullState() {
        return state;
    }

    @Override
    public String getFullStateNew() {

        if (ticket != null) {
            return ("State: " + getFullState().toString() + ", Ticket: " + ticket.getName() + " selected, Price: " + ticket.getPrice() + ", CoinsEntered: " + totalCoinsInserted(coinsList) + ", Changes: " + (totalCoinsInserted(coinsList) - ticket.getPrice()));
        } else {
            return ("State: " + getFullState().toString() + ", Ticket not entered, CoinsEntered :" + totalCoinsInserted(coinsList) + ", Changes: " + totalCoinsInserted(coinsList));
        }
    }

    public float totalCoinsInserted(ArrayList coinsList) {
        float sum = 0f;

        for (int i = 0; i < coinsList.size(); i++) {
            Coin temp = (Coin) coinsList.get(i);
            sum += temp.getPrice();
        }
        
        return sum;
    }

    

}
