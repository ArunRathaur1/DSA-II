import java.applet.*;
import java.awt.*;
public class Grid {
  public static void main(String args[]){
    Frame ob=new    Frame();
    Button a=new     Button("A");
    Button b=new     Button("B");
    Button c=new     Button("c");
    Button d=new     Button("d");
    Button e=new     Button("e");
    Button f=new     Button("f");
    Button g1=new     Button("g");
    Button h=new     Button("h");
    ob.setLayout(new GridBagLayout());
    GridBagConstraints g=new GridBagConstraints();
    Insets i=new Insets(3, 3, 3, 3);
    g.insets=i;
    g.gridx=0;
    g.gridy=0;
    ob.add(a,g);
    g.gridx=1;
    ob.add(b,g);
    g.gridx=2;
    ob.add(c,g);
    g.gridx=0;
    g.gridy=1;
    ob.add(d,g);
    g.gridx=1;
    ob.add(e,g);
    g.gridx=2;
    ob.add(f,g);
    g.gridx=3;
    g.gridy=0;
    g.gridheight=3;
    g.fill=GridBagConstraints.VERTICAL;
    ob.add(h,g);
    ob.setVisible(true);
    ob.setSize(500,500);
  }  
}
