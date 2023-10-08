import java.util.Scanner;
public class matrix_multiply{
    public static void main(String ag[]) {
        int ar, ac, br, bc;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of columns and rows of first matrix:");
        ar = sc.nextInt();
        ac = sc.nextInt();
        System.out.println("Enter the number of columns and rows of second matrix:");
        br = sc.nextInt();
        bc = sc.nextInt();
        if (ac == br) {
            int[][] a = new int[ar][ac];
            int[][] b = new int[br][bc];
            int[][] c = new int[ar][bc];
            System.out.println("Enter the elements of first matrix:");
            for (int i = 0; i < ar; i++) {
                for (int j = 0; j < ac; j++)
                    a[i][j] = sc.nextInt();
            }
            System.out.println("Enter the elements of second matrix:");
            for (int i = 0; i < br; i++) {
                for (int j = 0; j < bc; j++)
                    b[i][j] = sc.nextInt();
            }
            for (int i = 0; i < ar; i++) {
                for (int j = 0; j < bc; j++) {
                    int sum = 0;
                    for (int k = 0; k < ac; k++) {
                        sum += a[i][k] * b[k][j];
                    }
                    c[i][j] = sum;
                }
            }
            System.out.println("Resultant matrix after multiplication:");
            for (int i = 0; i < ar; i++) {
                for (int j = 0; j < bc; j++){
                        System.out.print(c[i][j] + " ");
                }
                System.out.println();
            }
        }
        else {
            System.out.println("Multiplication not possible");
        }
        sc.close();
    
    }
}