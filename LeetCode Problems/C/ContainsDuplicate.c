#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBERS 100

typedef struct HashMap{
    int value;
    bool present;
}HashMap;

int hashFunction(int index){
    return index%MAX_NUMBERS;
}

int isDuplicate(int *nums, int size){
    HashMap hashMap[MAX_NUMBERS] = {0};

    for(int i=0;i<size;i++){
        int key = nums[i];
        int value = hashFunction(key);

        if(key > MAX_NUMBERS || key < 0)
            continue; // skip numbers greater than MAX_NUMBERS

        if(hashMap[value].present != true){
            hashMap[value].present = true;
            hashMap[value].value = value;
        }
        else
            return value;    
    }
    return -1; // No duplicates
}
int countDuplicates(int *arr, int size){
    HashMap hashMap[MAX_NUMBERS];
    int count = 0;

    for(int i=0;i<size;i++){
        int key = arr[i];
        int value = hashFunction(key);

        if(hashMap[value].present != true){
            hashMap[value].present = true;
            hashMap[value].value = value;
        }
        else
            count++;
    }
    return count;
}
int main(){

    int nums[] = {1,2,5,7,4,6,500,6,-5};
    int result = countDuplicates(nums, sizeof(nums)/sizeof(nums[0]));
    if(result < 0)
        printf("No duplicates");
    else
        printf("Total # duplicate(s) %d\n", result);
    
    return 0;
}