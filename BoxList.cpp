//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "BoxList.h"

// Name:   BoxList
// Desc:   Default Constructor
// input:  none
// output: none
// return: none
BoxList::BoxList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Name:   ~BoxList
// Desc:   Destructor
// input:  none
// output: none
// return: none
BoxList::~BoxList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
};

// Name:   BoxList
// Desc:   Copy Constructor
// input:  none
// output: none
// return: none
BoxList::BoxList(const BoxList &list) {
    head = nullptr;
    tail = nullptr;
    size = list.size;

    Node *curr = list.head;
    Node *prev = nullptr;

    while (curr) {
        Node *newNode = new Node();
        newNode->data = curr->data;
        newNode->next = nullptr;

        if (prev == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            prev->next = newNode;
            tail = newNode;
        }

        prev = newNode;
        curr = curr->next;
    }
};

// Name:   insertAtTail
// Desc:   Adds a Node to the end of the BoxList linked list.
// input:  Box object to be inserted into the linked list.
// output: none
// return: none
void BoxList::insertAtTail(Box *box) {
    Node *newNode = new Node();
    newNode->data = box;
    newNode->next = nullptr;

    if (tail == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;

    size++;
}

// Name:   startIterating
// Desc:   Sets the mCurrent pointer to head.
// input:  none
// output: none
// return: none
void BoxList::startIterating() {
    mCurrent = head;
}

// Name:   getNextBox
// Desc:   Returns the Box in the node that mCurrent is pointing to and then moves mCurrent to the next node.
// input:  none
// output: none
// return: A pointer to a Box object representing the next Box in the iteration.
const Box* BoxList::getNextBox() {
    Box *temp = nullptr;
    if (mCurrent != nullptr) {
        temp = mCurrent->data;
        mCurrent = mCurrent->next;
    }

    return temp;
}

// Name:   hasNextBox
// Desc:   Returns true if mCurrent is non-null or false otherwise.
// input:  none
// output: none
// return: A boolean value indicating whether there is a next Box in the iteration.
bool BoxList::hasNextBox() {
    return mCurrent != nullptr;
}