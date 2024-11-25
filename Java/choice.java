import java.awt.*;
import java.awt.event.*;
public class choice {
    public static void main(String args[]){
        Frame ob=new Frame();
        ob.setSize(500,100);
        ob.setVisible(true);
        ob.setLayout(new java.awt.FlowLayout());
        Label label=new Label("this is defautl text");
        Choice ch=new Choice();
        ch.add("First");
        ch.add("Second");
        ch.add("Third");
        ItemListener listen=new ItemListener(){
            public void itemStateChanged(ItemEvent e){
                String l=ch.getSelectedItem();
                label.setText(l);
            }
        };
        ob.add(ch);
        ob.add(label);
    }
}
