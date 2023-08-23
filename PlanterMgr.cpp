//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "PlanterMgr.h"
#include "BoxList.h"

void PlantMgr::plant(int boxNumber, const char *plantName) {
//    The plant() method accepts a box number and a plant name. It then creates a
//    Box object with that data and calls the BoxTree::insert() method. It prints a
//    message indicating that the plant was planted.
}

void PlantMgr::harvest(int start, int end, const char *plantName) {
    BoxList list = tree.getRange(start, end);
//    For each Box, it
//    checks to see if that Box plant name matches the one passed to harvest(). If
//    so, then it prints a message that that plant is being harvested.
}

void PlantMgr::prune(int boxNumber) {
//    The prune() method accepts a box number. It calls BoxTree::remove() with that
//    box number. It prints a message indicating that the plant was pruned.
}