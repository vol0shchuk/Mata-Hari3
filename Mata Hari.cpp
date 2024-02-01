// Mata Hari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    MyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() {
        if (!head) {
            cout << "List is empty. Cannot pop_back()." << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
    }

    MyLinkedList& operator+=(const MyLinkedList& other) {
        Node* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
        return *this;
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    MyLinkedList list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    MyLinkedList list2;
    list2.push_back(4);
    list2.push_back(5);

    list1 += list2;

    list1.print();

    list1.pop_back();
    list1.print();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
