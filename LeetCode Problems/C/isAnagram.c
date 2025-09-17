#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Given two strings s and t, return true if the two strings are anagrams of each other, 
otherwise return false.

An anagram is a string that contains the exact same characters as another string, 
but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true
Example 2:

Input: s = "jar", t = "jam"

Output: false
Constraints:

s and t consist of lowercase English letters.

Hint:
Use two hash maps to keep track of the frequency of each letter
*/
#define NUM_ABCs 26

typedef struct HashMap{
    int count;
    char character;
}HashMap;

// a = 0x61, b = 0x62, c = 0x63 ... z = 0x7A
// Fills a pre-allocated hashMap with character frequencies from a string.
// Note: This function now takes the map as an argument to avoid returning
// a pointer to a local variable, which causes undefined behavior.
void charFrequency(char *string, HashMap hashMap[NUM_ABCs]){
    // Initialize the map
    for(int i=0; i<NUM_ABCs;i++){
        hashMap[i].count = 0;
        hashMap[i].character = 'a' + i;
    }

    // Count. Use '\0' to determine when the end of the string
    for(int i=0; string[i] != '\0'; i++){
        int index = string[i] - 'a';
        hashMap[index].character = string[i];
        hashMap[index].count++;
    }
}

bool isAnagram(char * s, char * t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    HashMap s_map[NUM_ABCs];
    HashMap t_map[NUM_ABCs];

    charFrequency(s, s_map);
    charFrequency(t, t_map);

    for (int i = 0; i < NUM_ABCs; i++) {
        if (s_map[i].count != t_map[i].count) {
            return false;
        }
    }

    return true;
}

int main(){
    printf("Input: s = \"racecar\", t = \"carrace\"\nOutput: %s\n\n", isAnagram("racecar", "carrace") ? "true" : "false");
    printf("Input: s = \"jar\", t = \"jam\"\nOutput: %s\n", isAnagram("jar", "jam") ? "true" : "false");
    return 0;
}