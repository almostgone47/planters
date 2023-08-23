//
// Created by Jeremiah Barro on 22/8/2023.
//

#ifndef PLANTERS_PLANTERMGR_H
#define PLANTERS_PLANTERMGR_H

#include "BoxTree.h";

class PlantMgr {
    private:
        BoxTree tree;
    public:
        void plant(int boxNumber, const char *plantName);
        void harvest(int start, int end, const char *plantName);
        void prune(int boxNumber);
};

#endif //PLANTERS_PLANTERMGR_H
