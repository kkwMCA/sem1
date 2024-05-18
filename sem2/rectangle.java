class Rectangle {
    
    public double width,length,area;
    String color;
    
    Rectangle(double w,double l,String c){
        width=w;
        length=l;
        color=c;
    }
    
    Rectangle(){
        
    }
    
    public double get_length(){
        return length;
    }
    
    public double get_width(){
        return width;
    }
    
    public String get_color(){
        return color;
    }
    
    public double find_area(){
        area=length* width;
        return area;
    }
    
    public static void main(String[] args) {
        Rectangle r1=new Rectangle(2,2,"red");
        Rectangle r2=new Rectangle(2,2,"red");
        
        if(r1.find_area()==r2.find_area() && r1.get_color()==r2.get_color()){
            System.out.println("matched!");
        }else{
            System.out.println("no match");
        }
        
    }
}
