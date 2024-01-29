// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.
// Example 1:
//
//Input: nums = [1,2,3,1]
//Output: true
//Example 2:
//
//Input: nums = [1,2,3,4]
//Output: false
//Example 3:
//
//Input: nums = [1,1,1,3,3,4,3,2,4,2]
//Output: true


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> & nums) {
        unordered_map<int,int> map; // maps each number to its index
        for(int i=0; i < nums.size(); i++) {
            if(map.find(nums[i]) != map.end()){
                return true; // duplicate found
            }
            map[nums[i]] = i; // the key in the map is a value 1:0, 2:1, 3:2...
        }
        return false; // no duplicates
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5,1};
    bool answer = sol.containsDuplicate(nums);
    cout << "Duplicates? " << (answer ? "Yes" : "No") << endl; // NICE SYNTAX
}