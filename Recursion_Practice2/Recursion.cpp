
#include "LinkedList.h"
#include <iostream>

using namespace std;



int main() {


    LinkedList<int> list;
    LinkedList<int> list1;
    LinkedList<double> list2;

    list1.append(3);
    list1.append(-2);
    list1.append(5);
    list1.append(12);
    list1.append(-2);
    list1.append(-4);
    list1.append(5);

    cout << "Linked List values: " << list1.to_string() << endl;
    cout << "Last negative number: " << list1.getLastNegative() << endl;
    int size = list1.size();
    cout << "Size = 7: " << size << endl;

    list2.append(3.2);
    list2.append(2.14);
    list2.append(-5.7);
    list2.append(5.2);
    list2.append(-12.01);
    list2.append(-2.99);
    list2.append(4.6);
    list2.append(5.3);


    cout << "Linked List values: " << list2.to_string() << endl;
    cout << "Last negative number: " << list2.getLastNegative() << endl;
    list2.removeDuplicates();
    cout << "Linked List values: " << list2.to_string() << endl;

    cout << "Adding 3, 5, 2, 7, -4, 6, 0...\n";
    list.insert(3);
    list.insert(6);
    list.insert(2);
    list.insert(7);
    list.insert(-4);
    list.insert(6);
    list.insert(0);


    cout << "LinkedList content: " << list.to_string() << endl;

    list.removeDuplicates();
    cout << "LinkedList content: " << list.to_string() << endl;

    // CHECK getMinMaxValue function
    int min{};
    int max{};
    list.getMinMaxValue(min, max);
    cout << min << endl;
    cout << max << endl;

    // VALIDATE INPUT
    int value;
    bool isValid = false;
    while (!isValid) {
        cout << "Enter value to search: ";
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            isValid = true;
        }
    }

    // SEARCH VALUE
//    bool result = list.getValue(value);
//    if (result) {
//        cout << "Found!" << endl;
//    } else {
//        cout << "Not found!" << endl;
//    }

    bool result1 = list.search(value);
    if (result1) {
        cout << "Found R!" << endl;
    } else {
        cout << "Not found R!" << endl;
    }


    return 0;
}

//
//int [] insertInArray(Node *head) {
//int SIZE = 10;
//int count = 0;
//int *ptr = new int[SIZE];
//Node * curr = head;
//while (curr != nullptr) {
//    ptr[count] = curr->data;
//    count++;
//    curr = curr->next;
//}
//return ptr*;
//}