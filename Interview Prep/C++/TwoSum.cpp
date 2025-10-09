#include <iostream>
#include <vector>
#include <unordered_map>

//#define BRUTE_FORCE
#define HASH_MAP

//Given an array of integers nums and a target integer target, 
//find the indices of the two numbers in the array that add up to the target.

// Time Complexity = O(N^2)
#ifdef BRUTE_FORCE
std::vector<int> twoSum(std::vector<int>& nums, int target){
    int n = nums.size();
    for(int i = 0; i < n-1;i++){
        for(int j = i+1; j< n; j++){
            // check sum of values at these indices
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return {}; // return empty vector
}
#endif

#ifdef HASH_MAP
std::vector<int> twoSum_optimal(std::vector<int>& nums, int target){
    // create the hash map to store (value, index)
    std::unordered_map<int, int> num_map;

    // Loop through the array once
    for(int i = 0; i< nums.size(); i++){
        int current_num = nums[i];

        // Calculate the complement
        int complement = target - current_num;

        // look for the complement in the map
        // map.count(key) returns 1 if the key exists, 0 otherwise.
        if(num_map.count(complement)){
            //if it exists, we found our pair
            // return {complement's index, current index}
            return {num_map[complement], i};
        }

        // if it doesn't exist, add the current number and its index to the map
        num_map[current_num] = i;
    }
    // if the loop finishes, no solution was found
    return {};
}
#endif


int main(){

    std::vector<int> my_nums = {2, 7, 11, 15};
    int target = 9;

    #ifdef BRUTE_FORCE
    std::vector<int> result = twoSum(my_nums, target);
    #endif

    #ifdef HASH_MAP
    std::vector<int> result = twoSum_optimal(my_nums, target);
    #endif

    if(!result.empty()){
        std::cout << "Indices found: " << result[0] << " & " << result[1] << std::endl;
    }else{
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}