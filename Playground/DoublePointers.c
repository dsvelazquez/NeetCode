#include <stdio.h>
#include <stdlib.h>

void change_value(int *ptr) {
    *ptr = 100;  // This changes the VALUE at the address
}

void change_pointer(int **ptr) {
    int *new_location = (int*)malloc(sizeof(int));
    *new_location = 200;
    *ptr = new_location;  // This changes WHERE the pointer points
}

int main() {
    int x = 50;
    int *my_ptr = &x;
    
    printf("Before change_value: *my_ptr = %d\n", *my_ptr);
    change_value(my_ptr);
    printf("After change_value: *my_ptr = %d\n", *my_ptr);
    
    printf("Before change_pointer: *my_ptr = %d\n", *my_ptr);
    change_pointer(&my_ptr);  // Pass ADDRESS of the pointer
    printf("After change_pointer: *my_ptr = %d\n", *my_ptr);
    
    free(my_ptr);
    return 0;
}