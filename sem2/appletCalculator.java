import java.applet.*;
import java.awt.*;
import java.awt.event.*;

//appletviewer appletCalculator.java

public class appletCalculator extends Applet implements ActionListener {

    TextField t1,t2;
    Button add,sub,mul,divide;
    Label label;

    public void init(){
        GridLayout grid=new GridLayout(4,4);
        setLayout(grid);

        t1=new TextField();
        t2=new TextField();
        
        add=new Button("add");
        sub=new Button("sub");
        mul=new Button("multiple");
        divide=new Button("divide");

        label=new Label();

        add(t1);
        add(t2);
        add(add);
        add(sub);
        add(mul);
        add(divide);
        add(label);

        add.addActionListener(this);
        sub.addActionListener(this);
        mul.addActionListener(this);
        divide.addActionListener(this);
    }

    
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==add){
            Integer a=Integer.parseInt(t1.getText());
            Integer b=Integer.parseInt(t2.getText());

            label.setText(String.valueOf(a+b));
        }else if(e.getSource()==sub){
            Integer a=Integer.parseInt(t1.getText());
            Integer b=Integer.parseInt(t2.getText());

            label.setText(String.valueOf(a-b));
        }else if(e.getSource()==mul){
            Integer a=Integer.parseInt(t1.getText());
            Integer b=Integer.parseInt(t2.getText());

            label.setText(String.valueOf(a*b));
        }else{
            Integer a=Integer.parseInt(t1.getText());
            Integer b=Integer.parseInt(t2.getText());

            label.setText(String.valueOf(a/b));
        }
    }
    
}

/*
 <applet code="appletCalculator" width=500 height=500></applet>
 */
