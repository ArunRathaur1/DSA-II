public class DeadLock {
    static private String  a="hello";
    static private String b="World";
    class thread1 extends Thread{
        public void run(){
            synchronized(a){
                try{
                    System.out.println("Holding a and waign foor b");
                    Thread.sleep(1000);
                }
                catch(Exception e){}
            }
            synchronized(b){
                try{
                    System.out.println("Holding b and waign foor a");
                    Thread.sleep(1000);
                }
                catch(Exception e){}
            }
        }
    }
    class thread2 extends Thread{
        public void run(){
            synchronized(b){
                try{
                    System.out.println("Holding b and waign foor a");
                    Thread.sleep(1000);
                }
                catch(Exception e){}
            }
            synchronized(a){
                try{
                    System.out.println("Holding a and waign foor b");
                    Thread.sleep(1000);
                }
                catch(Exception e){}
            }
        }
    }
    public static void main(String[] args) {
        DeadLock ob=new DeadLock();
        thread1 ob1=ob.new thread1();
        thread2 ob2=ob.new thread2();
        ob1.start();
        ob2.start();
    }
}
