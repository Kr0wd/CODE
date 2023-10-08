import java.util.Scanner;
public class sort{
    static void print(int[] arr, int size) {
        for (int i = 0; i < size; i++)
            System.out.println(arr[i]);
    }
    public static void main(String a[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements:");
        int lim = sc.nextInt();
        System.out.println("Enter array elements:");
        int arr[] = new int[lim + 1];
        for (int i = 0; i < lim; i++)
            arr[i] = sc.nextInt();
        System.out.println("entered array is:");
        print(arr, lim);
        for (int i = 0; i < lim - 1; i++){
            for (int j = 0; j < lim - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        System.out.println("The sorted array is :");
        print(arr, lim);
        sc.close();
    }
}