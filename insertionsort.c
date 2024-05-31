#include <stdio.h>

insertion_sort(int n, int arr[])
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    print_arr(n, arr);
}
print_arr(int n, int arr[])
{
    printf("Sorted array using Insertion Sort is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertion_sort(n, arr);

      int a;
    printf("\nEnter new element to be insereted:");
    scanf("%d", &a);

    int index = n;
    while (index >= 0 && arr[index-1] > a)
    {
        arr[index] = arr[index-1];
        index--;
    }
    arr[index] = a;

    printf("Array after inserting new element:");
    for (int i = 0; i < n+1; i++)
    {
        printf("%d ", arr[i]);
    }
}


