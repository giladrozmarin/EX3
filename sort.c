#include "sort.h"
#include <stdio.h>

void shift_element(int *arr, int i)
{
    for (int j = i; j > 0; j--)
    {
        *(arr + j) = *(arr + j - 1);
    }
}

//based on GeeksforGeeks Insertion Sort https://www.geeksforgeeks.org/insertion-sort/

void insertion_sort(int *arr, int len)
{
    int j, key;
    for (int i = 1; i < len; i++)
    {
        key = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > key)
        {
            shift_element(arr + j, 1);
            *(arr + j) = key;
            j--;
        }
    }
}
void insert50Element()
{
    int array[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter number: ");
        scanf("%d", (array + i));
    }
    insertion_sort(array, size);
    
    for (int i = 0; i < size; i++)
    {
        printf("%d,", *(array + i));
    }
    printf("\n");
}