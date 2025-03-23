class bookticket{
    int total=5;
    public  synchronized void book(String name){
        if(total>0){
            total--;
            System.out.println(name+" has booked the ticket");
            System.out.println("Ticket Remaning "+total);
        }
        else{
            System.out.println("No Ticket is Left");
        }
    }
}
public class TicketBooking  extends Thread{
    bookticket t;
    String name;
    TicketBooking(bookticket t,String name){
        this.name=name;
        this.t=t;
    }
    public void run(){
        t.book(name);
    }
    public static void main(String[] args) {
        bookticket ob=new bookticket();
        TicketBooking thread1=new TicketBooking(ob, "user 1");
        TicketBooking thread2=new TicketBooking(ob, "user 2");
        TicketBooking thread3=new TicketBooking(ob, "user 3");
        TicketBooking thread4=new TicketBooking(ob, "user 4");
        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();
    }
}
