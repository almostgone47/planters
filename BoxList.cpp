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

//Name:   operator=
//Desc:   Redefines = to perform deep copy.
//input:  Reference to the linked list to copy from.
//output: none
//return: A reference to the linked list that used the method to copy.
const BoxList & BoxList::operator= (const BoxList &list) {
    if (this != &list) {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;

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
    }

    return *this;
}

//Name:   insertFront
//Desc:   Adds a Node to the front of the linked list.
//input:  Person object to be inserted into the linked list.
//output: none
//return: none
void BoxList::insertFront(Box box) {
    Node *newNode = new Node();
    newNode->data = box;
    newNode->next = head;
    head = newNode;
    size++;
}

//Name:   removeById
//Desc:   Removes the first Node that matches the passed in Box id.
//input:  A string representing the id of the person object to be removed.
//output: none
//return: none
void BoxList::removeById(int id) {
    Node *curr = head, *prev = nullptr;

    while(curr) {
        if (id == curr->data.getNum()) {
            if (prev == nullptr) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }

            delete curr;
            size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

//Name:   searchById
//Desc:   Searches for a matching Person id to the passed in id argument.
//input:  A string representing the id of the person object to be returned.
//output: none
//return: A pointer to a person object searched ror.
Box* BoxList::searchById(int id) const {
    Node *curr = head;
    Box *box = nullptr;

    while(curr) {
        if (id == curr->data.getNum()) {
            box = &curr->data;
            break;
        }
        curr = curr->next;
    }

    return box;
}

//Name:   printList
//Desc:   Loops through each Box and calls the Box print method.
//input:  none
//output: The person object details.
//return: none
void BoxList::printList() const {
    Node *curr = head;

    while(curr) {
        curr->data.print();
        curr = curr->next;
    }
}

//void BoxList::startIterating() {
//
//}
//
//const Box& BoxList::getNextBox() {
//
//}
//
//bool BoxList::hasNextBox() {
//
//}