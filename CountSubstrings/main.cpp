// Count number of substrings that start with A and end with B.
// Example CABAAXBYA
// Explanation:
// https://www.geeksforgeeks.org/count-substrings-that-starts-with-character-x-and-ends-with-character-y/


#include <iostream>
#include <string>

using namespace std;

// to pass reference as param without any modification
// ! helps to avoid unnecessary copying of the string
int countSubstrings(const string &s);

int main() {
    string s = "CABAAXBYA";
    int result = countSubstrings(s);
    cout << result << endl;
}

int countSubstrings(const string &s) {
    int countA = 0;
    int countSubstring = 0;
    for (char letter: s) {
        if (letter == 'A') {
            countA++;
        } else if (letter == 'B') {
            countSubstring += countA;
        }
    }
    return countSubstring;
}