 class oddNumber extends Exception{
     oddNumber(String message){
        super(message);
    }
}
class EvenNumber {
    public void checkeven(int i)throws oddNumber{
        if(i%2==0){
            oddNumber ob=new oddNumber("NUmber is even");
            throw ob;
        }
    }
    public static void main(String[] args) throws oddNumber {
        EvenNumber ob=new EvenNumber();
        for(int i=0;i<5;i++){
            if(i<=3){
                System.out.println(i);
            }
            else{
                oddNumber ob1=new oddNumber("Number is grater than 3");
                throw ob1;
            }
        }
    }
}
