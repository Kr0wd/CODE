#include <stdio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (a[i] < pivot)
                i++;
            while (a[j] > pivot)
                j--;
            if (i < j)
                swap(&a[i], &a[j]);
        }
        swap(&a[j], &pivot);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

void merge(int a[], int size, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[size];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int size, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, size, low, mid);
        mergeSort(a, size, mid + 1, high);
        merge(a, size, low, mid, high);
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
           "1. Quick sort\n2. Merge Sort\n"
           "3. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        quickSort(a, 0, size - 1);
        printf("Sorted array:\n");
        print(a, size);
        break;
    case 2:
        mergeSort(a, size, 0, size - 1);
        printf("Sorted array:\n");
        print(a, size);
        break;
    case 3:
        return 0;
    default:
        printf("Invalid operation!\n");
    }
}