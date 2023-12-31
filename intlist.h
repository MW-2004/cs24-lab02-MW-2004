// intlist.h
// Linked list header file 

#ifndef INTLIST_H
#define INTLIST_H

class IntList {

public:

    // constructor and 3 methods already done in intlist.cpp (NO CHANGE):
    IntList();              // constructor
    void append(int value); // append value at end of list
    void print() const;     // print values separate by ' '
    int count() const;      // return count of values

    // destructor, copy constructor and 6 other METHODS YOU MUST 
    // IMPLEMENT IN intlist.cpp (NO CHANGE HERE):
    ~IntList();                      // destructor
    IntList(const IntList& source); //copy constructor (deep copy)
    int sum() const;                 // sum of all values
    bool contains(int value) const;  // true if value in list
    int max() const;                 // maximum value
    double average() const;          // average of all values
    void insertFirst(int value);     // insert new first value

    IntList& operator=(const IntList& source); //overloaded  (NO CHANGE)

private:

    // (Optional) You can add some private helper functions here.

    // definition of Node structure (DO NOT CHANGE):
    struct Node {
        int info;
        Node *next;
    };
    class Iterator{
        Node *p;
        public:
            Iterator()=delete;
            Iterator(Node *ptr){p=ptr;}
            Iterator& begin(){return *this;}
            Iterator end(){return *this;}
            int operator*(){return p->info;}
            bool operator!=(Iterator o){return p!=0;}
            Iterator& operator++(){
                p=p->next;
                return *this;
            }
    };
    Iterator iter() const {
        return Iterator(first);
    }
    Node *first; // pointer to first node (DO NOT CHANGE):
};

#endif
