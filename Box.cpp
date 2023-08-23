//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "Box.h"

Box::Box() {
    this->boxNum = 0;
    this->plantName = new char[1];
    strcpy(this->plantName, "");
}

Box::Box(int boxNum, const char *plantName) {
    this->boxNum = boxNum;
    this->plantName = new char[strlen(plantName) + 1];
    strcpy(this->plantName, plantName);
}

Box::~Box() {
    delete[] plantName;
}

Box::Box(const Box &box) {
    boxNum = box.boxNum;
    plantName = new char[strlen(box.plantName) + 1];
    strcpy(plantName, box.plantName);
}

Box& Box::operator=(const Box &box) {
    if (this != &box) {
        delete[] plantName;
        boxNum = box.boxNum;
        plantName = new char[strlen(box.plantName) + 1];
        strcpy(plantName, box.plantName);
    }

    return *this;
}

int Box::getNum() const {
    return boxNum;
}

char* Box::getPlantName() const {
    return plantName;
}

void Box::print() {
    cout << boxNum << ". " << plantName << endl;
}