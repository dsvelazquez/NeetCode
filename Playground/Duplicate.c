#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000

typedef struct{
    int key;
    bool present;
}HASH_TABLE;

int HASH_FUNCTION(int index)
{
    return index % TABLE_SIZE;
}

int findDuplicate(int *arr, int size)
{
    HASH_TABLE table[TABLE_SIZE];
    int num;
    for(int i=0;i<size;i++)
    {
        num = HASH_FUNCTION(arr[i]);
        if(table[num].present != true)
        {
            table[num].key = num;
            table[num].present = true;
        }
        else // found duplicate
            return num;
            
    }
    return -1; // no duplicate found
}
int main()
{
    int arr1[] =   {1,5,9,7,8,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int duplicate1 = findDuplicate(arr1, size1);
    if(duplicate1 == -1)
        printf("No duplicates\r\n");
    else
        printf("Duplicate in arr1: %d\r\n", duplicate1);
}