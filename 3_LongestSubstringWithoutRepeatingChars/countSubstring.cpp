// Given a string s, find the length of the longest substring
// without repeating characters.
//
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:
//
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
//
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int countLongestSubstring(const string &s);

int main() {
    string s1 = "abcabcbb";
    int result1 = countLongestSubstring(s1);
    cout << result1 << endl;

    string s2 = "bbbbb";
    int result2 = countLongestSubstring(s2);
    cout << result2 << endl;

    string s3 = "pwwkew";
    int result3 = countLongestSubstring(s3);
    cout << result3 << endl;

    return 0;
}

int countLongestSubstring(const string &s) {
    if (s.empty()) return 0; // edge case if string is empty
    if (s.length() == 1) return 1; // if one char

    int maxLength = 0;
    int start = 0;
    int end = 0;

    unordered_set<char> unique; // set to store unique characters in
    // the current window
    while (start < s.length()) {
        if (unique.find(s[start]) == unique.end()) {
            unique.insert(s[start]);
            if (start - end + 1 > maxLength) {
                maxLength = start - end + 1;
            }
            start++;
        } else { // if char is not unique
            unique.erase(s[end]);
            end++;
        }
    }
    return maxLength;
}


