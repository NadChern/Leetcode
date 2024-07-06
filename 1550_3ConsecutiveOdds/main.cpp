// Given an integer array arr, return true if there are three consecutive odd
// numbers in the array. Otherwise, return false.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool threeConsecutiveOdds(vector<int> &arr);
bool threeConsecutiveOdds2(vector<int> &arr);

int main() {
    vector<int> arr1 = {2, 6, 4, 1};
    vector<int> arr2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    bool result1 = threeConsecutiveOdds(arr1);
    bool result2 = threeConsecutiveOdds(arr2);
    cout << boolalpha << result1 << " " << result2; // false -> true

    // another solution
    bool result3 = threeConsecutiveOdds2(arr1);
    bool result4 = threeConsecutiveOdds2(arr2);
    cout << boolalpha << result3 << " " << result4; // false -> true
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

// with binary string solution
bool threeConsecutiveOdds2(vector<int> &arr) {
    string binary;

    for (int num: arr) {
        binary += (num % 2) ? '1': '0';
    }
    return binary.find("111") != string::npos; // find returns position of substring
    // if substring is not found, method returns string::npos
}

