"""
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true
Example 2:

Input: s = "jar", t = "jam"

Output: false
Constraints:

s and t consist of lowercase English letters.
"""
s = "a"
t = "ab"
def isAnagram(s: str, t: str) -> bool:
        hashMapS = {}
        for c in s:
            if c not in hashMapS:
                hashMapS[c] = 1
            else:
                hashMapS[c] += 1
                
        hashMapT = {}
        for c in t:
            if c not in hashMapT:
                hashMapT[c] = 1
            else:
                hashMapT[c] += 1

        if len(hashMapT) != len(hashMapS):
             return False
        
        for key in hashMapS:
            print(key)
            if key not in hashMapT or hashMapS[key] != hashMapT[key]: # check if key in hashmap S is in hashmap T.
                 return False
            
        print(hashMapS)
        print(hashMapT)
        return True

print(isAnagram(s,t))