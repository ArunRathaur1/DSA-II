import javax.swing.*;
import java.awt.event.*;

public class JTextFieldExample {
    public static void main(String[] args) {
        JFrame ob = new JFrame();
        JTextField ob1 = new JTextField(20); // Set columns instead of size
        ob.setLayout(new java.awt.FlowLayout());
        JLabel ob2 = new JLabel("This is the default text");
        ob.add(ob2);
        ob.add(ob1);
        ob.setSize(300, 200); // Adjusted size for better layout
        ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ob.setVisible(true);

        KeyListener listener = new KeyListener() {
            public void keyPressed(KeyEvent e) {
                // Use getKeyChar to get the character typed
                char p = e.getKeyChar();
                ob2.setText(Integer.toString(ob1.getText().length()));
            }

            public void keyReleased(KeyEvent e) {
                // Optional: Add logic if needed
            }

            public void keyTyped(KeyEvent e) {
                // Optional: Add logic if needed
            }
        };

        ob1.addKeyListener(listener); // Add the KeyListener to the JTextField
    }
}
