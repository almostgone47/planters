//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "BoxList.h"

//Name:   BoxList
//Desc:   Constructor for BoxList class.
//input:  none
//output: none
//return: none
BoxList::BoxList() {
    head = nullptr;
    size = 0;
}

//Name:   ~BoxList
//Desc:   Destructor for BoxList class. The delete keyword deallocates memory and the pointers are
//        set to null so as not to leave dangling pointers.
//input:  none.
//output: none
//return: none
BoxList::~BoxList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
};

//Name:   LinkedList
//Desc:   Copy constructor for LinkedList class.
//input:  none.
//output: none
//return: none
BoxList::BoxList(const BoxList &list) {
    head = nullptr;
    size = list.size;

    Node *curr = list.head;
    Node *prev = nullptr;

    while (curr) {
        Node *newNode = new Node();
        newNode->data = curr->data;

        if (prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
        curr = curr->next;
    }
};

//Name:   insertFront
//Desc:   Adds a Node to the end of the linked list.
//input:  Person object to be inserted into the linked list.
//output: none
//return: none
void BoxList::insertAtTail(Box *box) {
    Node *curr = head;
    Node *newNode = new Node();
    newNode->data = box;

    if (curr == nullptr) {
        head = newNode;
    } else {
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    size++;
}

void BoxList::startIterating() {
    mCurrent = head;
}

const Box* BoxList::getNextBox() {
    if (mCurrent != nullptr) {
        Box *temp = mCurrent->data;
        mCurrent = mCurrent->next;
        return temp;
    }
}

bool BoxList::hasNextBox() {
    bool hasNext = true;
    if (mCurrent == nullptr) {
        hasNext = false;
    }
    return hasNext;
}