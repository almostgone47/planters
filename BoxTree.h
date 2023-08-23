//
// Created by Jeremiah Barro on 22/8/2023.
//

#ifndef PLANTERS_BOXTREE_H
#define PLANTERS_BOXTREE_H

#include "Box.h";

struct Node {
    Box data;
    Node *leftNode;
    Node *rightNode;
};

class BoxTree {
    private:
        Node *root;

    public:
        void inorder();
        void insert(Box);
        void remove(int);
        BoxList* getRange(int start, int end);
        void printLeaves();
};

#endif //PLANTERS_BOXTREE_H
