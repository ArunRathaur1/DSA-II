import javax.swing.*;
import java.awt.event.*;

class Buttons {
    public static void main(String[] args) {
        JFrame ob1 = new JFrame();
        ob1.setVisible(true);
        ob1.setSize(500, 500);
        ob1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ob1.setLayout(new java.awt.FlowLayout()); // Using FlowLayout for simplicity

        JButton first = new JButton("OK");
        first.setSize(100, 100);
        JButton second = new JButton("Cancel");
        second.setSize(100, 100);
        JLabel label = new JLabel("This is a test");

        ob1.add(first);
        ob1.add(second);
        ob1.add(label);

        ActionListener ob2 = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (e.getSource() == first) {
                    label.setText("OK Button is Pressed");
                } else if (e.getSource() == second) {
                    label.setText("Cancel Button is Pressed");
                }
            }
        };

        first.addActionListener(ob2);
        second.addActionListener(ob2);
    }
}
