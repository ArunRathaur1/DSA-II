import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ToolBarExample {

    public static void main(String[] args) {
        // Create a new frame
        JFrame frame = new JFrame("JToolBar Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);

        // Create a toolbar
        JToolBar toolBar = new JToolBar("Toolbar", JToolBar.HORIZONTAL);
        toolBar.setRollover(false);  // Enable rollover effects

        // Add buttons to the toolbar
        JButton newButton = new JButton("New");
        JButton openButton = new JButton("Open");
        JButton saveButton = new JButton("Save");

        toolBar.add(newButton);
        toolBar.add(openButton);

        // Add a separator
        toolBar.addSeparator();

        toolBar.add(saveButton);

        // Add another separator with a custom size
        toolBar.addSeparator(new java.awt.Dimension(20, 0));

        JButton cutButton = new JButton("Cut");
        JButton copyButton = new JButton("Copy");
        JButton pasteButton = new JButton("Paste");

        toolBar.add(cutButton);
        toolBar.add(copyButton);
        toolBar.add(pasteButton);

        // Add action listeners to buttons
        newButton.addActionListener(e -> System.out.println("New Button Clicked"));
        openButton.addActionListener(e -> System.out.println("Open Button Clicked"));
        saveButton.addActionListener(e -> System.out.println("Save Button Clicked"));
        cutButton.addActionListener(e -> System.out.println("Cut Button Clicked"));
        copyButton.addActionListener(e -> System.out.println("Copy Button Clicked"));
        pasteButton.addActionListener(e -> System.out.println("Paste Button Clicked"));

        // Add the toolbar to the frame
        frame.add(toolBar, "North");

        // Make the frame visible
        frame.setVisible(true);
    }
}
