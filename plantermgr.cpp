//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "plantermgr.h"
#include "BoxList.h"

void plantermgr::plant(int boxNumber, const char *plantName) {
//    The plant() method accepts a box number and a plant name. It then creates a
//    Box object with that data and calls the BoxTree::insert() method. It prints a
//    message indicating that the plant was planted.
}

void plantermgr::harvest(const char *plantName, int start, int end) {
    BoxList *list = tree.getRange(start, end);
//    For each Box, it
//    checks to see if that Box plant name matches the one passed to harvest(). If
//    so, then it prints a message that that plant is being harvested.
}

void plantermgr::prune(int boxNumber) {
//    The prune() method accepts a box number. It calls BoxTree::remove() with that
//    box number. It prints a message indicating that the plant was pruned.
}