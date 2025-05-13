#include <stdio.h>
#include <stdlib.h>

void reverseArray (int arr[], int size)
{
    int temp;
    int i;
    for(i=0;i<(size/2);i++)
    {
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

int main()
{
    int nums[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(nums)/sizeof(int);

    reverseArray(nums, size);
    for(int i =0;i<size;i++)
        printf("%d", nums[i]);

    return 0;
}