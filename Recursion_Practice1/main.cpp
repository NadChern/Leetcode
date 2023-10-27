#include <iostream>
#include <algorithm>

using namespace std;

int linearSearchI(int [], int, int);
// linear search iterative

int linearSearchR(int [], int, int);
// linear search recursive

int linearSearchR(int [], int, int, int);
// linear search recursive - helper function

int findDuplicatesI(string &);
// find duplicates iterative

int findDuplicatesR(string &);
// find duplicates recursive

int findDuplicatesR(string &, int, int);
// find duplicates recursive - helper function


int main() {
    int SIZE = 6;
    int arr[] = {10, 5, -2, 6, 0, 11};
    int result = linearSearchI(arr, SIZE, -2);
    if (result == -1) {
        cout << "Not found" << endl;
    } else {
        cout << "Found at index: " << result << endl;
    }

    int array[] = {10, 5, -2, 6, 0, 11, -7};
    int resultR = linearSearchR(array, 7, 11);
    if (resultR == -1) {
        cout << "Not found" << endl;
    } else {
        cout << "Found at index: " << resultR << endl;
    }

    string str1 = "fgggKlmnOg";
    int duplicates = findDuplicatesI(str1);
    cout << "Number of duplicates: " << duplicates << endl;

    string str2 = "naddind";
    int dup = findDuplicatesR(str2);
    cout << "Number of duplicates: " << dup << endl;

    return 0;
}


int linearSearchI(int arr[], int size, int key) {
    if (size == 0) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int linearSearchR(int arr[], int size, int key) {
    if (size == 0) // empty array
        return -1;
    return linearSearchR(arr, size, key, 0);
}

int linearSearchR(int arr[], int size, int key, int index) {
    if (size == index) { // not found
        return -1;
    }
    if (arr[index] == key) {
        return index;
    }

    return linearSearchR(arr, size, key, index + 1);
}

int findDuplicatesI(string &str) {
    int count = 0;
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == str[i + 1])
            count++;
    }
    return count;
}

int findDuplicatesR(string &str) {
    sort(str.begin(), str.end());
    return findDuplicatesR(str, 0, 0);

}

int findDuplicatesR(string &str, int count, int index) {
    if (index >= str.length()) {
        return count; // duplicates not found
    }
    if (str[index] == str[index + 1]) {
        count++;
    }
    return findDuplicatesR(str, count, index + 1);
}
