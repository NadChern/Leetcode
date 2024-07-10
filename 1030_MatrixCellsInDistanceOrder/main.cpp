//You are given four integers row, cols, rCenter, and cCenter.
// There is a rows x cols matrix and you are on the cell with the coordinates
// (rCenter, cCenter).
//
//Return the coordinates of all cells in the matrix, sorted by their distance
// from (rCenter, cCenter) from the smallest distance to the largest distance.
// You may return the answer in any order that satisfies this condition.
//
//The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.
//
//Examples:
//
//Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
//Output: [[0,0],[0,1]]
//Explanation: The distances from (0, 0) to other cells are: [0,1]
//
//Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
//Output: [[0,1],[0,0],[1,1],[1,0]]
//Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
//The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.

//Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
//Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
//Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
//There are other answers that would also be accepted as correct,
// such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>


using namespace std;

int calcDistance(int row, int colms, int rCenter, int cCenter) {
    return abs(rCenter - row) + abs(cCenter - colms);
}

// using lambda
vector<vector<int>>
allCellsDistOrder(int row, int colms, int rCenter, int cCenter) {
    vector<vector<int>> result;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colms; j++) {
            result.push_back({i, j});
        }
    }

    // result.begin(), result.end() = range of el that will be sorted
    // capture list [rCenter, cCenter]
    // parameters vector<int>&a,b a = cell where a[0] = row, a[1]=column
    sort(result.begin(), result.end(),
         [rCenter, cCenter](vector<int> &a, vector<int> &b) {
             int distA = calcDistance(a[0], a[1], rCenter, cCenter);
             int distB = calcDistance(b[0], b[1], rCenter, cCenter);
             return distA < distB;
         });
    return result;
}


// using multimap:
// allows to store multiple elements with same key = distance in sorted order
vector<vector<int>>
allCellsDistOrder2(int rows, int cols, int rCenter, int cCenter) {
    multimap<int, vector<int>> map;

    // populate map with distance and cell coordinates
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int distance = abs(i - rCenter) + abs(j - cCenter);
            map.insert({distance, {i, j}});
        }
    }

    // Converting multimap into 2D vector
    vector<vector<int>> result;
    for (const auto &pair: map) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    int rows = 1;
    int cols = 2;
    int rCenter = 0;
    int cCenter = 0;

    int rows1 = 2;
    int cols1 = 3;
    int rCenter1 = 1;
    int cCenter1 = 2;

    vector<vector<int>> r1 = allCellsDistOrder(rows, cols, rCenter, cCenter);
    vector<vector<int>> r2 = allCellsDistOrder2(rows1, cols1, rCenter1,
                                                cCenter1);
    // Print the sorted coordinates
    for (const auto &cell: r1) {
        cout << "[" << cell[0] << "," << cell[1] << "], ";
    }
    cout << endl;

    for (const auto &cell: r2) {
        cout << "[" << cell[0] << "," << cell[1] << "], ";
    }
    cout << endl;

    return 0;

}