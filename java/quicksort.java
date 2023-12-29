import java.util.*;

class Sorter {
    void quickSort(String names[], int start, int end) {
        int i, j;
        String pivot, temp;
        if (start < end) {
            pivot = names[start];
            i = start;
            j = end;
            while (i < j) {
                while ((names[i].compareTo(pivot) <= 0) && i < end)
                    i++;
                while ((names[j].compareTo(pivot) >= 0) && j > start)
                    j--;
                if (i < j) {
                    temp = names[i];
                    names[i] = names[j];
                    names[j] = temp;
                }
            }
            temp = names[j];
            names[j] = names[start];
            names[start] = temp;
            this.quickSort(names, start, j - 1);
            this.quickSort(names, j + 1, end);
        }
    }
}

class quickSort {
    public static void main(String args[]) {
        int size, index;
        String names[] = new String[20];
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter array size:");
        size = sc.nextInt();

        System.out.println("Enter list of names:");
        for (index = 0; index < size; index++)
            names[index] = sc.next();
        System.out.print("\n");
        System.out.println("BEFORE SORTING:");
        for (index = 0; index < size; index++)
            System.out.println(names[index]);

        Sorter nameSorter = new Sorter();
        nameSorter.quickSort(names, 0, size - 1);

        System.out.println("\nAFTER SORTING:");
        for (index = 0; index < size; index++)
            System.out.println(names[index]);
    }
}