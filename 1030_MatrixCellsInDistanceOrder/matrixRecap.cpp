// Matrix in C++
// (1) int [][] fixed-size traditional 2d array
//              + less memory overheads
//              + good for fixed sizes matrices
//              - require manual resizing, check for bounds
//              - need to allocate/deallocate memory yourself

// (2) vector<vector<int>>   2d vector
//                - overheads with memory management
//                + dynamic resizing and check bounds
//                + auto management of allocation/deallocation
//                + built-in methods push_back()/pop_back() / clear() / size(), empty(), begin() - end()



#include <iostream>
#include <vector>

using namespace std;


int main() {

    // Create fixed-size matrix
    int rows = 3;
    int cols = 4;
    int matrix[rows][cols]; // declare matrix,
    // var matrix will point to the first element in matrix

    // !Reminder!: Stack storage is faster but limited in size compared to heap.
    // For larger and dynamically sized arrays consider to use heap

    // Initialize matrix by setting all values to 0 to avoid random nums
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    // Change some values
    matrix[0][0] = 1;
    matrix[2][3] = 2;

    // Display matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }


    // Create 2D vector
    vector<vector<int>> matrixV(3, vector<int>(4)); // rows 3, columns 4
    vector<vector<int>> matrixT = {
            {1, 2, 3},
            {4, 5},
            {6, 7, 8, 9}
    };

    vector<vector<int>> matrixTest;

    // Add elements to 2D vector
    // element added by row to the end of the vector
    matrixTest.push_back({3,1,1}); // push in row 0  values 003
    matrixTest.push_back({1,6,1}); // push in row 1 values 161
    matrixTest.push_back({1,1,9}); // push in row 2 values 119

    // Access  element (ATTENTION TO SYNTAX!)
    for(const auto& row: matrixTest) {
        for(int val:row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Modify element
    matrixTest[2][0] = 0;
    cout << "Modified matrix:" << endl;
    for (const auto& row : matrixTest) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Remove last row
    matrixTest.pop_back();
    cout << "Matrix after removing the last row:" << endl;
    for (const auto& row : matrixTest) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Size and capacity
    // If all rows have the same number of columns, you can simply check the size of the first row.
    cout << "Number of rows: " << matrixTest.size() << endl;
    cout << "Number of columns in the first row: " << matrixTest[0].size() << endl;

    // If the number of columns can vary, you can iterate through all rows
    // to find the number of columns for each row.
    for(int i = 0; i < matrixTest.size(); i++) {
        cout << "Number of columns in row " << i << "-" << matrixTest[i].size() << endl;
    }

    // Total number of elements (cells) in matrix, sum sizes of rows
    int totalElements = 0;
    for (const auto& row : matrixTest) {
        totalElements += row.size();
    }
    cout << "Total number of elements: " << totalElements << endl;

    return 0;
}




