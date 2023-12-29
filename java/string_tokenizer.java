import java.util.Scanner;
import java.util.StringTokenizer;

public class string_tokenizer {
    public static void main(String[] args) {
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter some numbers separated with spaces: ");
        String input = sc.nextLine();
        StringTokenizer st = new StringTokenizer(input, " ");
        while (st.hasMoreTokens()) {
            int temp = Integer.parseInt(st.nextToken());
            System.out.println(temp);
            sum += temp;
        }
        System.out.println("Sum is: " + sum);
    }
}
