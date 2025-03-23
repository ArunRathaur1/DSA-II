import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Swing {
    public static void main(String[] args) {
        // Create a JFrame
        JFrame ob = new JFrame("Swing Example");
        ob.setLayout(new FlowLayout());
        ob.setSize(500, 500);
        ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a JFileChooser
        JFileChooser root = new JFileChooser();

        // Create a JLabel to display the selected file path
        JLabel ll = new JLabel("Default Text");
        ob.add(root);
        ob.add(ll);

        // Add an ActionListener to the JFileChooser
        root.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if(e.getActionCommand().equals(JFileChooser.APPROVE_SELECTION)){
                    String s=root.getSelectedFile().getAbsolutePath();
                    ll.setText(s);
                }
            }
        });

        // Make the frame visible
        ob.setVisible(true);
    }
}
