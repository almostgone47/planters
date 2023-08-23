//
// Created by Jeremiah Barro on 22/8/2023.
//

#ifndef PLANTERS_BOXTREE_H
#define PLANTERS_BOXTREE_H

#include "Box.h"
#include "BoxList.h"

class BoxTree {
    private:
    Node *root;

    struct Node {
        Box *data;
        Node *leftNode;
        Node *rightNode;
    };

    public:
        BoxTree();
        ~BoxTree();
        BoxTree(const BoxTree &tree);
        const BoxTree & operator= (const BoxTree &tree);

        void inorder();
        void insert(Box);
        void remove(int);
        BoxList* getRange(int start, int end);
        void printLeaves();
};

#endif //PLANTERS_BOXTREE_H
