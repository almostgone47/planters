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
    BoxList list = tree.getRange(start, end);
    cout << "Harvesting " << plantName << " plants from boxes " << start << " to " << end << ". " << endl;
    cout << "The following boxes will be harvested: ";

    list.startIterating();
    while (list.hasNextBox()) {
        const Box *box = list.getNextBox();
        char *name = box->getPlantName();

        if (strcmp(name, plantName) == 0) {
            cout << box->getNum() << " ";
        }
    }
    cout << endl;
}

void PlanterMgr::prune(int boxNumber) {
    cout << "Pruning box number " << boxNumber << "." << endl;
    tree.remove(boxNumber);
}