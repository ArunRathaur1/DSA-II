class TicketBooking{
    int total_ticket=5;
    public synchronized void booked(String userName){
        if(total_ticket>0){
            total_ticket--;
            System.out.println("User with UserName "+userName+" booked one ticket");
            System.out.println("Total ticket left "+total_ticket);
        }
        else{
            System.out.println("User "+userName+" try to book no ticket left");
        }
    }
}
class thread extends Thread{
    TicketBooking t;
    String useString;
    thread(TicketBooking t, String useString){
        this.t=t;
        this.useString=useString;
    }
    public void run(){
        t.booked(useString);
    }
}
class running {
    public static void main(String[] args) {
        TicketBooking ob=new TicketBooking();
        for(int i=0;i<10;i++){
            thread ob1=new thread(ob, "usern"+i);
            ob1.start();
        }
    }
}
