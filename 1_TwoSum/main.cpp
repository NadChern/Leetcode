#include <iostream>
#include <vector>

using namespace std;
// Recap
// Vector - dynamic arrays (part of STL) with automatic size, resize, allocation
// and deallocation. Consume more memory compare to arrays (allocate extra
// storage to accommodate for possible growth).
// Use vectors when number of elements is unknown, need a container that can
// grow and shrink dynamically + memory is not critical (otherwise use arrays).

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j <nums.size(); j++) {
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
    int target = 9;
    vector<int> result = sol.twoSum(num, target);
    for (int index: result) {
        cout << index << " ";
    }

    return 0;
}