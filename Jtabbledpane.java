import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

 class Swingldsjfld {
    public static void main(String[] args) {
        // Create a JFrame
        JFrame ob = new JFrame("Swing Example");
        ob.setLayout(new FlowLayout());
        ob.setSize(500, 500);
        ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a JFileChooser
        JTabbedPane tb=new JTabbedPane();
        JPanel tab1=new JPanel();
        JPanel tab2=new JPanel();
        tab1.setName("Tab1");
        tab2.setName("Tab2");
        Label l1=new Label("Thisis the label one for tab1");
        Label l2=new Label("This is the label two fro tab2");
        tab1.add(l1);
        tab2.add(l2);
        tb.add(tab1);
        tb.add(tab2);
        ob.add(tb);
        // Make the frame visible
        ob.setVisible(true);
    }
}
