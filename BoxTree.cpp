//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "BoxTree.h"
#include "BoxList.h"

//Name:   BoxList
//Desc:   Constructor for BoxList class.
//input:  none
//output: none
//return: none
BoxTree::BoxTree() {
    root = nullptr;
}

//Name:   ~BoxList
//Desc:   Destructor for BoxList class. The delete keyword deallocates memory and the pointers are
//        set to null so as not to leave dangling pointers.
//input:  none.
//output: none
//return: none
BoxTree::~BoxTree() {
//    while (root != nullptr) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//    head = nullptr;
//    size = 0;
};

//Name:   LinkedList
//Desc:   Copy constructor for LinkedList class.
//input:  none.
//output: none
//return: none
BoxTree::BoxTree(const BoxTree &tree) {
//    head = nullptr;
//    size = list.size;
//
//    Node *curr = list.head;
//    Node *prev = nullptr;
//
//    while (curr) {
//        Node *newNode = new Node();
//        newNode->data = curr->data;
//
//        if (prev == nullptr) {
//            head = newNode;
//        } else {
//            prev->next = newNode;
//        }
//
//        prev = newNode;
//        curr = curr->next;
//    }
}

//Name:   operator=
//Desc:   Redefines = to perform deep copy.
//input:  Reference to the linked list to copy from.
//output: none
//return: A reference to the linked list that used the method to copy.
const BoxTree & BoxTree::operator= (const BoxTree &tree) {
//    if (this != &tree) {
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//        size = 0;
//
//        Node *curr = list.head;
//        Node *prev = nullptr;
//
//        while (curr) {
//            Node *newNode = new Node();
//            newNode->data = curr->data;
//
//            if (prev == nullptr) {
//                head = newNode;
//            } else {
//                prev->next = newNode;
//            }
//
//            prev = newNode;
//            curr = curr->next;
//        }
//    }
//
//    return *this;
}

void BoxTree::inorder() {

}

void BoxTree::insert(Box box) {

}

void BoxTree::remove(int boxNum)  {

}

BoxList* BoxTree::getRange(int start, int end) {

}

void BoxTree::printLeaves() {

}