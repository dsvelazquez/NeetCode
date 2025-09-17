#include <stdio.h>
#include <stdint.h> // For uint8_t
#include <stddef.h> // For size_t

// Our structure that holds information about a list of bytes
typedef struct data_block {
    const uint8_t * const start_address; // This member expects a pointer to a uint8_t
    size_t length;
} data_block;

// Scenario 1: A simple array of uint8_t
static const uint8_t item_list_A[] = { 0x10, 0x20, 0x30, 0x40, 0x50 }; // An array of 5 bytes

// Scenario 2: Another simple array of uint8_t
static const uint8_t item_list_B[] = { 0xAA, 0xBB, 0xCC }; // An array of 3 bytes

int main() {

    printf("--- Understanding Array Decay ---\n");

    // Get the address of the array (as a pointer to the entire array type)
    printf("Address of 'item_list_A' (as array ptr): %p\n", (void*)&item_list_A);
    // Get the address of the first element (what array decay gives you)
    printf("Address of 'item_list_A'[0] (as element ptr): %p\n\n", (void*)item_list_A);
    // Notice these addresses are the same! The difference is how the compiler *views* their types.


    printf("--- Example 1: No Cast Needed (Like your TW8846RegInit_data_31 case) ---\n");
    // When you use 'item_list_A' in an expression (like assignment),
    // it 'decays' into a pointer to its first element (a const uint8_t *).
    // This perfectly matches the 'start_address' member's type.
    data_block block_A = {
        .start_address = item_list_A, // No cast needed, item_list_A decays to const uint8_t*
        .length = sizeof(item_list_A)
    };

    printf("Block A start address: %p (from item_list_A, no cast)\n", (void*)block_A.start_address);
    printf("First byte of Block A: 0x%02X\n", block_A.start_address[0]);
    printf("\n");


    printf("--- Example 2: Explicit Cast Used (Like your eval_board_por_page0 case) ---\n");
    // Here, we explicitly cast 'item_list_B' to (const uint8_t *).
    // Even though 'item_list_B' would decay correctly on its own,
    // some developers or coding standards might add the cast for:
    // 1. Explicit clarity.
    // 2. To silence certain compiler warnings (though less common for perfect matches).
    // 3. Consistency if other pointer assignments in the code *do* require casts.
    data_block block_B = {
        .start_address = (const uint8_t *)item_list_B, // Explicit cast, technically redundant
        .length = sizeof(item_list_B)
    };

    printf("Block B start address: %p (from item_list_B, with cast)\n", (void*)block_B.start_address);
    printf("First byte of Block B: 0x%02X\n", block_B.start_address[0]);
    printf("\n");

    return 0;
}