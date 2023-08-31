//
// Created by Jeremiah Barro on 22/8/2023.
//

#ifndef PLANTERS_BOXLIST_H
#define PLANTERS_BOXLIST_H

#include <cstring>

#include "Box.h"

class BoxList {
    private:
        struct Node {
            Box *data;
            Node *next;
        };

        Node *head;
        Node *tail;
        Node *mCurrent;
        int size = 0;

    public:
        BoxList();
        ~BoxList();
        BoxList(const BoxList &list);

        void insertAtTail(Box*);
        void startIterating();
        const Box* getNextBox();
        bool hasNextBox();
        int getSize();

};


#endif //PLANTERS_BOXLIST_H
