//
// Created by Jeremiah Barro on 22/8/2023.
//

using namespace std;

#include "../include/plantermgr.h"
#include "../include/BoxList.h"

// Name:   plant
// Desc:   Creates a new Box with the specified box number and plant name, and inserts it into the BoxTree.
// input:  An integer for the box number for the new plant and a char pointer for the plant name for the new plant.
// output: Planting information printed to the console.
// return: none
void PlanterMgr::plant(int boxNumber, const char *plantName) {
    Box *box = new Box(boxNumber, plantName);
    cout << "Planting " << plantName <<" in box " << boxNumber << endl;
    tree.insert(box);
}

// Name:   harvest
// Desc:   Retrieves a list of boxes containing plants within the specified range and harvests the requested plant.
// input:  A char pointer for the plant name to harvest.
//         An integer for the starting box number of the range to harvest.
//         An integer for the ending box number of the range to harvest.
// output: The harvesting info and a list of harvested boxes.
// return: none
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

// Name:   prune
// Desc:   Removes a specific box containing a plant from the BoxTree.
// input:  An integer for the box number of the plant to prune.
// output: The information for the plants pruned.
// return: none
void PlanterMgr::prune(int boxNumber) {
    cout << "Pruning box number " << boxNumber << "." << endl;
    tree.remove(boxNumber);
}