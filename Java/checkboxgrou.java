import java.awt.event.*;
import java.awt.*;
public class checkboxgrou implements ItemListener {
    public static void main(String[] args) {
        CheckboxGroup group=new CheckboxGroup();
        Checkbox ob=new Checkbox("Option 1",group,false);
        Checkbox ob1=new Checkbox("Option 1",group,false);
        Checkbox ob2=new Checkbox("Option 1",group,false);
        Checkbox ob3=new Checkbox("Option 1",group,false);
        Checkbox ob4=new Checkbox("Option 1",group,false);
        Frame f=new Frame();
        f.add(ob);
        f.add(ob1);
        f.add(ob2);
        f.add(ob3);
        f.add(ob4);
        f.setVisible(true);
        f.setLayout(new FlowLayout());
        f.setSize(500,500);
        ItemListener action=new ItemListener() {
            public void itemStateChanged(ItemEvent e){
                String text=group.getSelectedCheckbox().getLabel();
                System.out.println(text);
            }
        };
        ob.addItemListener(action);
        ob1.addItemListener(action);
        ob2.addItemListener(action);
        ob3.addItemListener(action);
        ob4.addItemListener(action);

    }
}
