// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE 
//Maximillian Austin, 1/8/25

#include "intlist.h"

#include <iostream>
using std::cout;
struct Node {
    int info;
    Node *next;
};

class IntList {
private:
    Node *head;
    Node *tail;
public:
    IntList(); // constructor
    ~IntList(); // destructor
    IntList(const IntList& source); // copy constructor
    IntList& operator=(const IntList& source); // assignment operator

    void push_front(int value);
    void push_back(int value);
    int sum() const;
    bool contains(int value) const;
    int max() const;
    double average() const;
    int count() const;
    void print() const;
    
};

// copy constructor
IntList::IntList(const IntList& source) {
    if (source.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = new Node;
        head->info = source.head->info;
        head->next = nullptr;
        tail = head;
        Node* cur = source.head->next;
        while (cur != nullptr) {
            push_back(cur->info);
            tail = tail->next;
            cur = cur->next;
        }
        
    }
    //IMPLEMENT THIS

}

// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    Node * cur = head;
    int total = 0;
    while (cur != nullptr) {
        total += cur->info;
        cur = cur->next;
        //IMPLEMENT THIS
    }
    return total; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node * cur = head;
    while (cur != nullptr) {
        if (cur->info == value) {
            return true;
        }
        cur = cur->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) {
        return 0;
    } else {
        Node* cur = head;
        int max = cur->info;
        while (cur != nullptr) {
            if (cur->info > max) {
                max = cur->info;
            }
            cur = cur->next;
        }
        return max;
    }
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr) {
        return 0.0;
    } else {
        double total = 0.0;
        int count = 0;
        Node* cur = head;
        while (cur != nullptr) {
            total += cur->info;
            count++;
            cur = cur->next;
        }
        return total / count;
    }
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* oldhead = head;
    head = new Node;
    head->info = value;
    head->next = oldhead;
    // IMPLEMENT
}

// append value at end of list
void IntList::push_back(int value) {
    Node* oldtail = tail;
    tail = new Node;
    tail->info = value;
    oldtail->next = tail;
    tail->next = nullptr;
    // IMPLEMENT
 
}

// return count of values
int IntList::count() const {
    Node* cur = head;
    int cnt = 0;
    while (cur != nullptr) {
        cnt++;
        cur = cur->next;
    }
    return cnt;

}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
        return *this; // self-assignment, do nothing
    }
    if (head != nullptr && tail != nullptr) {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr; 
        tail = nullptr;
    } 
    if (source.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = new Node;
        head->info = source.head->info;
        head->next = nullptr;
        tail = head;
        Node* cur = source.head->next;
        while (cur != nullptr) {
            push_back(cur->info);
            tail = tail->next;
            cur = cur->next;
        }
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
    //IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

