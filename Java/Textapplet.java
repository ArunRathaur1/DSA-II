import java.awt.*;
import java.awt.Button;
import java.awt.Label;
import java.awt.event.*;
class FirstApplet implements ActionListener{
    public static void main(String[] args) {
       Button a=new Button("This is button");
       Frame ob=new Frame();
       Label l=new Label();
       ob.setSize(500,500);
       ob.add(a);
        ActionListener lister=new ActionListener() {
            public void actionPerformed(ActionEvent e){

            }
        }; 
        a.addActionListener(lister);
        ob.setVisible(true);
    }
}