// Given a binary string s, return the number of non-empty substrings that
// have the same number of 0's and 1's, and all the 0's and all the 1's in these
// substrings are grouped consecutively.
// Substrings that occur multiple times are counted the number of times
// they occur.
//

// Same number => equal length of subgroups
// Count consecutive chars

// 000111 => min {3,3} => 3 [000111, 01, 0011]
// 00110011 => {2,2,2,2} => 2 + 2 + 2 = 6
// 10101 => {1,1,1,1,1} => 1+1+1+1 = 4
// 0001111 => {3,4} => 3  0011 01 000111

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int countSubstrings1(string s);

int countSubstrings2(string s);

int main() {

    string str = "00110011";
    int result1 = countSubstrings1(str);
    cout << result1 << endl;
    int result2 = countSubstrings2(str);
    cout << result2 << endl;

    return 0;
}

int countSubstrings1(string str) {
    int previousGroupLength = 0; // length of previous group of chars
    int currentGroupLength = 1; // start counting from second char
    int countSubstrings = 0; // total count of valid substrings

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            currentGroupLength++;
        } else {
            countSubstrings += min(currentGroupLength, previousGroupLength);
            previousGroupLength = currentGroupLength;
            currentGroupLength = 1; // reset to count new group
        }
    }
    countSubstrings += min(currentGroupLength, previousGroupLength);

    return countSubstrings;
}

int countSubstrings2(string str) {
    vector<int> groups;
    int count = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            groups.push_back(count);
            count = 1;
        }
    }
    groups.push_back(count);

    int totalSubstrings = 0;
    for (int i = 1; i < groups.size(); i++) {
        totalSubstrings += min(groups[i], groups[i - 1]);
    }

    return totalSubstrings;
}