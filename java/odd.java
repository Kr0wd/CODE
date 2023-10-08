import java.util.Scanner;
public class odd {
    public static void main (String a[]){
        int num;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the number :");
        num=sc.nextInt();
        if (num % 2 == 0) {
            System.out.println(num + " is even.");
        } 
        else {
            System.out.println(num + " is odd.");
        }
        sc.close();
    }
}