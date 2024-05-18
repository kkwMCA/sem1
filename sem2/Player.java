
class Player{
    String name;
    int age;
    
    Player(String n,int a){
        name=n;
        age=a;
    }
}

class Cricket extends Player{
    int runs;
    
    Cricket(String n,int a,int r){
        super(n,a);
        runs=r;
    }
     void show(){
        System.out.println("name:"+name+" age:"+age+ " goals:"+runs);
    }
}

class Hockey extends Player{
    int medals;
    
    Hockey(String n,int a,int g){
        super(n,a);
        medals=g;
    }
    
     void show(){
        System.out.println("name:"+name+" age:"+age+ " goals:"+medals);
    }
}

class Football extends Player{
    int goals;
    
    Football(String n,int a,int r){
        super(n,a);
        goals=r;
    }
    
    void show(){
        System.out.println("name:"+name+" age:"+age+ " goals:"+goals);
    }
}

public class MainClass{
    
    public static void main(String[] args){
        Football f=new Football("sumedh",21,2);
        Hockey h=new Hockey("sumedh",21,14);
        Cricket c=new Cricket("sumedh",21,234);
        
        f.show();
        h.show();
        c.show();
        
    }
}
