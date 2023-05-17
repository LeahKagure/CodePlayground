//a program to reverse an array

#include<stdio.h>

//create a function that reverses an array
void reverse_arr(int arr[], int first, int last)
{
    int temp;
    while (first < last)
    {
        temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
        first++;
        last--;
    }
    
}
//create a function that prints the array
void print_arr(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//main function
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The original array is:\n");
    print_arr(arr, n);
    reverse_arr(arr, 0, n-1);
    printf("The reversed array is:\n");
    print_arr(arr, n);
    printf("\n");    
    return 0;
}