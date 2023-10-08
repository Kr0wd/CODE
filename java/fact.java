import java.util.Scanner;

public class fact {
    public static void main(String a[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number :");
        int num = sc.nextInt();
        int fact = 1;
        int i= 1;
        while (i<=num) {
            fact = fact * i;
            i++;
        }
        System.out.println("The factorial of " + num + " is " + fact);
        sc.close();
    }
}
