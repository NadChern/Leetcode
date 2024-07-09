// Substring search Brute force
// This algorithm checks for the presence of a substring (pattern) within
// a larger string (text) by sliding the pattern over the text one character
// at a time and checking for matches at each position.

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int substringSearch(const string &a, const string &b) {
    if (b.length() > a.length())
        return -1; // length of substring is bigger than string
    for (int i = 0; i <= a.length() - b.length(); i++) {
        int j = 0;
        while (j < b.length() && a[i + j] == b[j]) { // check of length first
            // to ensure we don't access out of bounds indices
            j++;
        }
        if (j == b.length()) {
            return i;
        }
    }
    return -1;
}

// why a.length()-b.length() in for-loop
// ex. length of a = 11, length of b = 5. Then i <=6.  If i exceeds index  6,
// there wouldn't be enough chars left in "a" to match pattern "b"

bool substringSearchInArray(const vector<string> &arr, const string &b) {
    int result;
    for (int i = 0; i < arr.size(); i++) {
        string a = arr[i];
        result = substringSearch(a, b);
        if (result != -1) return true;
    }
    return false;
}

int main() {
    string a = "Happy happy joy joy";
    string b = "happy";

    int result = substringSearch(a, b);
    cout << result << endl;

    vector<string> arr = {"Anna", "Bob", "Alan", "Nadin"};
    string target = "Nadin";
    bool isFound = substringSearchInArray(arr, target);
    cout << boolalpha << isFound << endl;

    return 0;
}


