#include <stdio.h>

#define OFFSET 1

void max_heap(int a[], int index, int size)
{
    int parent = a[index];
    int child_index = 2 * index;
    while (child_index <= size)
    {
        if (child_index < size && a[child_index + 1] > a[child_index])
            child_index++;

        if (parent <= a[child_index])
        {
            a[child_index / 2] = a[child_index];
            child_index *= 2;
        }
        else
            break;
    }
    a[child_index / 2] = parent;
}

void heapsort(int a[], int size)
{
    for (int i = size; i >= 2; i--)
    {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heap(a, 1, i - 1);
    }
}

void build_maxheap(int a[], int size)
{
    for (int i = size / 2; i >= 1; i--)
        max_heap(a, i, size);
}

void print_array(int a[], int size)
{
    for (int i = 1; i <= size; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

int main()
{
    int size;
    printf("Enter number of elements in the array: ");
    scanf("%d", &size);
    int a[size + OFFSET];
    printf("Enter the array elements:\n");
    for (int i = 1; i <= size; i++)
        scanf("%d", &a[i]);
    printf("Unsorted array:\n");
    print_array(a, size);
    build_maxheap(a, size);
    heapsort(a, size);
    printf("Sorted array:\n");
    print_array(a, size);
    return 0;
}