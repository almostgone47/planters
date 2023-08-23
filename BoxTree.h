//
// Created by Jeremiah Barro on 22/8/2023.
//

#ifndef PLANTERS_BOXTREE_H
#define PLANTERS_BOXTREE_H

#include "Box.h"
#include "BoxList.h"

class BoxTree {
    private:
        struct Node {
            Box *data;
            Node *leftNode;
            Node *rightNode;

            void insert(Box *box) {
                int newBoxNum = box->getNum();
                int currNum = this->data->getNum();

                if (newBoxNum < currNum && this->leftNode != nullptr) {
                    this->leftNode->insert(box);
                } else if (newBoxNum < currNum) {
                    Node *newNode = new Node();
                    newNode->data = box;
                    this->leftNode = newNode;
                } else if (newBoxNum > currNum && this->rightNode != nullptr) {
                    this->rightNode->insert(box);
                } else if (newBoxNum > currNum) {
                    Node *newNode = new Node();
                    newNode->data = box;
                    this->rightNode = newNode;
                }
            }

            void remove(int boxNum) {
                if (this != nullptr) {
                    int currNum = this->data->getNum();
                    if (currNum == boxNum) {
                        delete this;
                        return;
                    }

                    if (currNum < boxNum && this->rightNode) {
                        this->rightNode->remove(boxNum);
                    } else if  (currNum > boxNum && this->leftNode) {
                        this->leftNode->remove(boxNum);
                    }
                }
            }
        };

        Node *root;
        int totalLeaves;

    public:
        BoxTree();
        ~BoxTree();
        BoxTree(const BoxTree &tree);
        const BoxTree & operator= (const BoxTree &tree);

        void inorder();
        void insert(Box*);
        void remove(int);
        BoxList* getRange(int start, int end);
        void printLeaves();
};

#endif //PLANTERS_BOXTREE_H
