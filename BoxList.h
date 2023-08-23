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
            Box data;
            Node *next;
        };

        Node *head;
        Node *mCurrent; //"the next value to give to the caller".
        int size = 0;

    public:
        BoxList();
        ~BoxList();
        BoxList(const BoxList &list);

        void insertAtTail(Box);
        void startIterating();
        const Box& getNextBox();
        bool hasNextBox();

};


#endif //PLANTERS_BOXLIST_H
