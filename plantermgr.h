//
// Created by Jeremiah Barro on 22/8/2023.
//

#ifndef PLANTERS_PLANTERMGR_H
#define PLANTERS_PLANTERMGR_H

#include "BoxTree.h"

class plantermgr {
    private:
        BoxTree tree;
    public:
        void plant(int boxNumber, const char *plantName);
        void harvest(const char *plantName, int start, int end);
        void prune(int boxNumber);
};

#endif //PLANTERS_PLANTERMGR_H
