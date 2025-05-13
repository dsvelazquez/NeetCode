#include <stdio.h>
#include <stdlib.h>

int Sum_Range(int *arr, int size, int left, int right)
{
    int sum = 0;
    // check if array is valid
    if(size < 2)
        return 0;

    for(int i=0; i <= right-left; i++)
    {
        sum += arr[left+i];
    }

    return sum;
}
int main()
{
    int nums[] = {1,2,3,4,5,6,7,8,9};

    printf("Sum: %d\r\n", Sum_Range(nums, sizeof(nums)/sizeof(int), 1, 5));

    return 0;
}