import java.util.*;

public class User {
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        

        try{
            System.out.println("Give age:");
            int age=sc.nextInt();
            if(18 > age || age > 55){
                throw new Exception("age should be between 18 and 55");
            }
            System.out.println("Give income:");
            int income=sc.nextInt();
            if(50000 > income || income > 100000){
                throw new Exception("50k - 100k");
            }
            
            System.out.println("Give city:");
            String city=sc.next();
            if(!city.equals("pune") && !city.equals("mumbai") && !city.equals("chennai") && !city.equals("bangolore")){
                throw new Exception("not in aspected city");
            }

            

            System.out.println("Give vehicle:");
            String vehicle=sc.next();
            if(!vehicle.equals("4-wheeler")){
                throw new Exception("should be a 4-wheeler");
            }
        }catch(Exception ex){
            System.out.println(ex);
        }
    }
}
