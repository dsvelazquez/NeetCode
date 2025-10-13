#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <string_view>
#include <cassert>
#include <algorithm>
#include <unordered_set>

//#define BRUTE_FORCE
//#define SORTING
#define HASHING

/*
Given an integer array nums, return true if any value appears at 
least twice in the array, and return false if every element is distinct.
*/
#ifdef BRUTE_FORCE
// TIME COMPLEXITY O(N^2)
bool containsDuplicate(std::vector<int>& nums) {
    int length = nums.size();    
    for(int i = 0; i < length - 1;i++){
        for(int j = i + 1; j < length; j++){
            if(nums[i] == nums[j])
                return true; // found duplicate
        }
    }
    return false; // no duplicate
}
#endif
#ifdef SORTING
// TIME COMPLEXITY O(NlogN) for sorting
bool containsDuplicate(std::vector<int>& nums) {
    // sort the array
    std::sort(nums.begin(), nums.end());
    
    // A number will be duplicate if its neighber is == to each other
    for(int i = 0; i < nums.size()-1;i++)
    {
        if(nums[i] == nums[i+1])
            return true;
    }
    return false;
}
#endif
#ifdef HASHING
bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> mySet;
    bool success = false;
    int index;
    for(auto i : nums){
       auto [index, success] = mySet.insert(i);
       if(!success)
            return true;    
    }
    /*
    for(auto i : nums){
        if(mySet.count(i)){ // .count() is a way to check for existence
            return true; // if count is 1, we have seen this number
        }

        mySet.insert(i);// if we haven't seen it, add it to the set for future checks
    }
    
    */
    return false;
}
#endif
int main()
{
    std::vector<int> nums { 2, 5, 7, 3, 8, 8, 6};
    
    std::cout << containsDuplicate(nums);

    return 0;
}