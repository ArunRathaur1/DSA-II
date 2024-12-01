import java.awt.*;
import java.awt.event.*;
public class AWT extends Thread implements ItemListener  {
    public static void main(String[] args) {
        // Create a Frame
        Frame ob = new Frame();
        Choice list=new Choice();
        list.add("Red");
        list.add("Blue");
        list.add("Green");
        Label time=new Label("10");
        // Set size for the frame
        ob.setSize(500, 500);

        // Create a Label
        Label l = new Label("Hello World",Label.CENTER);
        TextField t1=new TextField();
        TextField t2=new TextField();
        l.setAlignment(Label.CENTER);
        ob.setLayout(new GridBagLayout());
        Insets i=new Insets(5, 5, 5, 5);
        GridBagConstraints g=new GridBagConstraints();
        g.insets=i;
        g.gridx=0;
        g.gridy=0;
        // Add label to the frame
        Button o=new Button("count");
        ob.add(l,g);
        // ActionListener ac=new ActionListener(){
        //     int x=1;
        //     public void actionPerformed(ActionEvent e){
        //       int x1=Integer.parseInt(t1.getText());
        //       int x2=Integer.parseInt(t2.getText());
        //       l.setText(""+(x1+x2));
        //        x++; 
        //     }
        // };
        // o.addActionListener(ac);
        ItemListener ic=new ItemListener() {
            public void itemStateChanged(ItemEvent e){
                String c=list.getSelectedItem();
                if(c.equals("Red")){
                  ob.setBackground(Color.RED);
                }
            }
        };
                Thread ob1=new Thread(){
                    int x=10;
                    public void run(){
                        try{
                            while(x!=0){
                                Thread.sleep(1000);
                                x=x-1;
                                time.setText(Integer.toString(x));
                            }
                            time.setText("Time's up");
                        }
                        catch(Exception e){

                        }
                    }
                };
            ob1.start();

        list.addItemListener(ic);
        l.setBounds(100, 100, 50, 50);
        o.setBounds(200,200,50,50);
        g.gridy=1;
        ob.add(t1,g);
        g.gridy=2;
        ob.add(t2,g);
        g.gridy=3;
        ob.add(o,g);
        g.gridy=4;
        ob.add(list,g);
        g.gridy=5;
        ob.add(time,g);
        // Make the frame visible
        ob.setVisible(true);
    }
}
