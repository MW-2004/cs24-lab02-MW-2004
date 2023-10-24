// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first=0;
    if(!source.first) return;
    first=new Node{source.first->info,0};
    Node *tmp=first;
    for(int n:Iterator(source.first->next)){
        tmp->next=new Node{n,0};
        tmp=tmp->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    while(first){
        Node *tmp=first->next;
        delete first;
        first=tmp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int s=0;
    for(int n: iter()) s+=n;
    return s;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for(int n: iter()) if(n==value) return true;
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!first) return 0;
    int max=first->info;
    for(int n: iter()) if(n>max) max=n;
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!first) return 0;
    int c=0, s=0;
    for(int n:iter()){
        c++;
        s+=n;
    }
    return 1.0*s/c;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    first=new Node{value, first};
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    while(first){
        Node *tmp=first->next;
        delete first;
        first=tmp;
    }
    first=0;
    if(!source.first) return *this;
    first=new Node{source.first->info,0};
    Node *tmp=first;
    for(int n:Iterator(source.first->next)){
        tmp->next=new Node{n,0};
        tmp=tmp->next;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}