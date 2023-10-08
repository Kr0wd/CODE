import java.util.Scanner;
public class largest {
    public static void main (String a[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter 3 numbers :");
        double n1 = sc.nextDouble();
        double n2 = sc.nextDouble();
        double n3 = sc.nextDouble();
        double largest = large(n1,n2,n3);
        System.out.println("largest number is " +largest);
        sc.close();
    }
    public static double large(double n1,double n2,double n3){
        if(n1>n2 && n1>n3){
            return n1;
        }else if(n2>n1 && n2>n3){
            return n2;
        }else{
            return n3;
        }
    }

}