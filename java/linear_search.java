import java.util.Scanner;
public class linear_search{
    public static void main(String a[]) {
        int element, size;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the array size : ");
        size = sc.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter the array elements :");
        for (int i = 0; i < size; i++)
            arr[i] = sc.nextInt();
        System.out.println("Enter the element to search : ");
        element = sc.nextInt();
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                System.out.printf("Found %d at index %d\n", element, i);
                System.exit(0);
            }
        }
        System.out.printf("The entered element %d was not found in the given array.\n");
        sc.close();
    }
}