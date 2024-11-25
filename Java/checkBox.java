import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
public class checkBox {
    public static void main(String[] args) {
        JFrame ob=new JFrame();
        ob.setVisible(true);
        ob.setSize(500,500);
        ob.setLayout(new java.awt.FlowLayout());
        ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JCheckBox box1=new JCheckBox("Box1");
        JCheckBox box2=new JCheckBox("Box2");
        ButtonGroup group=new ButtonGroup();
        group.add(box1);
        group.add(box2);

        JLabel label=new JLabel("This is Default");
        ItemListener listen=new ItemListener() {
           public void itemStateChanged(ItemEvent e){
                if(e.getItem()==box1){
                    label.setText("Box 1 is pressed");
                }
                if(e.getItem()==box2){
                    label.setText("Box 2 is pressed");
                }
           } 
        };
        box1.addItemListener(listen);
        box2.addItemListener(listen);
        ob.add(label);
        ob.add(box1);
        ob.add(box2);
    }
}
