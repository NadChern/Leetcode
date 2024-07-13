#include<unordered_map>
#include<iostream>
#include <sstream> // for using istringstream

using namespace std;


unordered_map<string, int> countWordFrequency(string &s) {
    unordered_map<string, int> counter;
    istringstream stream(s); // treat string as stream
    string word;

    while (stream
            >> word) { // reads one word at a time and stores it in word var
        if (counter.find(word) != counter.end()) {
            counter[word]++;
        } else {
            counter[word] = 1;
        }
    }
    return counter;
}

int main() {
    string s = "hello world hello";
    unordered_map<string, int> result = countWordFrequency(s);
    for (auto &pair: result) {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}

