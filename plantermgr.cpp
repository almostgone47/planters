//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "plantermgr.h"
#include "BoxList.h"

void PlanterMgr::plant(int boxNumber, const char *plantName) {
    Box *box = new Box(boxNumber, plantName);
    cout << "Planting " << plantName <<" in box " << boxNumber << endl;
    tree.insert(box);
}

void PlanterMgr::harvest(const char *plantName, int start, int end) {
    BoxList *list = tree.getRange(start, end);
//    For each Box, it
//    checks to see if that Box plant name matches the one passed to harvest(). If
//    so, then it prints a message that that plant is being harvested.
}

void PlanterMgr::prune(int boxNumber) {
//    The prune() method accepts a box number. It calls BoxTree::remove() with that
//    box number. It prints a message indicating that the plant was pruned.
}