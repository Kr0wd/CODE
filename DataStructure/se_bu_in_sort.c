#include <stdio.h>

void bubbleSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

void selectionSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
            {
                int temp = a[j];
                a[j] = a[min];
                a[min] = temp;
            }
        }
    }
}

void insertionSort(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = a[i];
        int index = i;
        while (index > 0 && a[index - 1] > temp)
        {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = temp;
    }
}

void print(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

int main()
{
    int size, choice;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
    printf("Unsorted array:\n");
    print(a, size);
    printf("Select operation:\n"
           "1. Selection sort\n2. Bubble Sort\n"
           "3. Insertion sort\n4. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        selectionSort(a, size);
        printf("Sorted array:\n");
        print(a, size);
        break;
    case 2:
        bubbleSort(a, size);
        printf("Sorted array:\n");
        print(a, size);
        break;
    case 3:
        insertionSort(a, size);
        printf("Sorted array:\n");
        print(a, size);
        break;
    case 4:
        return 0;
    default:
        printf("Invalid operation!\n");
    }
}