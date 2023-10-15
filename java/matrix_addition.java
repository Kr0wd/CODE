import java.util.Scanner;

public class matrix_addition {
    public static void main(String[] args) {
        int rows, cols;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows and columns of matrix:");
        rows = sc.nextInt();
        cols = sc.nextInt();
        int[][] mat1 = new int[rows][cols];
        int[][] mat2 = new int[rows][cols];
        int[][] mat3 = new int[rows][cols];
        System.out.println("Enter the elements of 1st matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                mat1[i][j] = sc.nextInt();
        }
        System.out.println("Enter the elements of 2nd matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                mat2[i][j] = sc.nextInt();
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                System.out.printf("%d ", mat3[i][j]);
            System.out.println();
        }
    sc.close();
    }
}