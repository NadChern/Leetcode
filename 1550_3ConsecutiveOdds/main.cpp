// Given an integer array arr, return true if there are three consecutive odd
// numbers in the array. Otherwise, return false.

#include <iostream>
#include <vector>

using namespace std;

bool threeConsecutiveOdds(vector<int> &arr);

int main() {
    vector<int> arr1 = {2, 6, 4, 1};
    vector<int> arr2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    bool result1 = threeConsecutiveOdds(arr1);
    bool result2 = threeConsecutiveOdds(arr2);
    cout << boolalpha << result1 << " " << result2; // false -> true
    return 0;
}

bool threeConsecutiveOdds(vector<int> &arr) {
    int count = 0;
    const int treshold = 3;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) { // with while loop we enter infinite loop with same value
            count++;
            if (count == treshold) {
                return true;
            }
        } else{
            count = 0;
        }
    }
    return false;
}



