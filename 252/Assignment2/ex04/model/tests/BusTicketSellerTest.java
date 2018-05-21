package ex04.model.tests;

import ex04.model.classes.BusTicketsSeller;
import ex04.model.classes.Coin;
import ex04.model.classes.Ticket;
import ex04.model.interfaces.BusTicketsSeller_ADT;

public class BusTicketSellerTest {

    public static void main(String[] args) {
        int StockTickets = 4;
        BusTicketsSeller_ADT bts = new BusTicketsSeller(StockTickets);
        System.out.println(bts.getFullState());
        Coin mitsos = new Coin("2Euro", 2.0F);
        Ticket kostas = new Ticket("Olokliro", 2.0F);
        bts.insertCoin(mitsos);
        
        bts.selectTicket(kostas);
        
        System.out.println(bts.getFullState());
        bts.finish();

    }

}
