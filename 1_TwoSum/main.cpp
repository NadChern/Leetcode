// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//
//Example 1:
//
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
//Example 2:
//
//Input: nums = [3,2,4], target = 6
//Output: [1,2]
//Example 3:
//
//Input: nums = [3,3], target = 6
//Output: [0,1]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// Recap
// Vector - dynamic arrays (part of STL) with automatic size, resize, allocation
// and deallocation. Consume more memory compare to arrays (allocate extra
// storage to accommodate for possible growth).
// Use vectors when number of elements is unknown, need a container that can
// grow and shrink dynamically + memory is not critical (otherwise use arrays).

class Solution {
public:
    vector<int> twoSumHASH(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i]; // x = target - currentNum
            // Check of x is already in map
            if (map.find(x) != map.end()) {
                result.push_back(map[x]);
                result.push_back(i);
                return result;
            }
            // If not found, add the current number as a key and index
            // as value to the map
            map[nums[i]] = i;
        }
        return {}; // return empty vector for no solution found
    }


    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices; // return immediately one pair is found
                }
            }
        }
        return indices;
    }

};


int main() {
    Solution sol; // in C++ don't use new to create instance of object
    vector<int> num = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result = sol.twoSum(num, target1);
    for (int index: result) {
        cout << index << " ";
    }

    Solution sol2;
    vector<int> nums = {4, 5, 6, 4};
    int target2 = 8;
    vector<int> result2 = sol2.twoSumHASH(nums, target2);
    for (int index: result2) {
        cout << index << " ";
    }
    return 0;
}