import java.util.Scanner;
public class transpose_matrix{
    public static void main(String ag[]) {
        int r, c;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows and columns of matrix:");
        r = sc.nextInt();
        c = sc.nextInt();
        int mat[][] = new int[r][c];
        int trans[][] = new int[c][r];
        System.out.println("Enter the elements of matrix:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                mat[i][j] = sc.nextInt();
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                trans[j][i] = mat[i][j];
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++)
                System.out.printf("%d ", trans[i][j]);
            System.out.println();
        }
    sc.close();
    }
}