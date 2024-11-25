import java.awt.*;
import java.awt.event.*;
public class Menu {
    public static void main(String[] args) {
        Frame ob=new Frame();
        ob.setVisible(true);
        ob.setSize(100,200);
        ob.setLayout(new FlowLayout());
        MenuBar mbar=new MenuBar();
        Menu mb=new Menu("Menu");
        Menu mb2=new Menu("SubMenu");
        MenuItem item1=new MenuItem("Item1");
        MenuItem item2=new MenuItem("Item2");
        MenuItem item3=new MenuItem("Item3");
        MenuItem item4=new MenuItem("Item4");
        MenuItem item5=new MenuItem("Item5");
        mb.add(item1);
        mb.add(item2);
        mb2.add(item3);
        mb2.add(item4);
        mb2.add(item5);
        mb.add(mb2);
       
    }
}
