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
        int size = 0;

    public:
        BoxList();
        ~BoxList();
        BoxList(const BoxList &list);
        const BoxList & operator= (const BoxList &list);

        void insertFront(Box);
        void removeById(int);
        Box* searchById(int) const;
        void printList() const;
//
//        void startIterating();
//        const Box& getNextBox();
//        bool hasNextBox();

};


#endif //PLANTERS_BOXLIST_H
