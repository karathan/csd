package ex04.model.classes;

/**
 * Internal comment: It could be an internal class to the ADT however we haven't
 * yet covered that topic in the lectures. This is why it is placed in separate
 * file.
 */
public enum BusTicketSeller_State {

    Idle,
    MoneyEntered,
    TicketSelected,
    CardEntered,
    TicketAndMoneyEntered,
    TicketAndCardEntered;

}
