#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000

typedef struct{
    int key;
    bool present;
}HashTable;

int HashFunction(int index)
{
    return index % TABLE_SIZE;
}

int findDuplicate( int arr[], int size)
{
    int index;
    HashTable dupe[TABLE_SIZE];

    for(int i=0;i<size;i++)
    {
        index = HashFunction(arr[i]);
        if(dupe[index].present != true)
        {
            dupe[index].present = true;
            dupe[index].key = arr[i];
        }
        else
        {
            return dupe[index].key;
        }
        
    }
    return -1; // Didn't find duplicate
    
}
int main()
{
    int arr1[] =   {1,5,9,8,8,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int duplicate1 = findDuplicate(arr1, size1);
    if(duplicate1 == -1)
        printf("No duplicates\r\n");
    else
        printf("Duplicate in arr1: %d\r\n", duplicate1);
}