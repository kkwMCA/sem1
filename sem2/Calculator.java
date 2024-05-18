import java.util.*;

class Calculator {
    
    double num1 , num2;
    
    Calculator(double n1,double n2){
        num1=n1;
        num2=n2;
    }

    double add(){
        return num1+num2;
    }
    
   double mul(){
        return num1*num2;
    }
    
    double div(){
        return num1/num2;
    }
    
    double sub(){
        return num1-num2;
    }
    
    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        System.out.println("Initialize the values:");
        System.out.println("number 1:");
        double num1=sc.nextDouble();
        System.out.println("number 2:");
        double num2=sc.nextDouble();
    
        Calculator cal=new Calculator(num1,num2);
        
        while(true){
            System.out.println("===MENU===");
            System.out.println("1)add\n2)sub\n3)mul\n4)divide\n5)exit");
            System.out.println("enter choice:");
            int ch=sc.nextInt();
            
            switch(ch){
                case 1:{
                    System.out.println(cal.add());
                    break;
                }
                case 2:{
                    System.out.println(cal.sub());
                    break;
                }
                case 3:{
                    System.out.println(cal.mul());
                    break;
                }
                case 4:{
                    System.out.println(cal.div());
                    break;
                }
                case 5:{
                    System.exit(0);
                    break;
                }
                default:{
                    System.out.println("wrong choice");
                }
            }
        }
    }
}
