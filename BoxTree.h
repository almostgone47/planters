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

            Node(Box *box) {
                data = box;
                leftNode = nullptr;
                rightNode = nullptr;
            }
        };

        Node *root;
        int totalLeaves;

    public:
        BoxTree();
        ~BoxTree();
        BoxTree(const BoxTree &tree);
        const BoxTree & operator= (const BoxTree &tree);

        void copyTree(Node *&newTree, Node *oldTree);
        void insert(Box *box);
        void insert(Node*, Box*);
        void remove(int);
        void remove(Node*, int);
        void deleteNode (Node *, int);
        BoxList getRange(const int start,const int stop);
        void printLeaves();
        void getRangeRecursive(Node *node, const int start, const int end, BoxList *list);
        void deleteTree(Node *&node);
};

#endif //PLANTERS_BOXTREE_H
