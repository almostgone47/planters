//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "Box.h"

Box::Box() {
}

Box::Box(int num, const char *plantName) {
    this->num = num;
    this->plantName = new char[strlen(plantName) + 1];
    strcpy(this->plantName, plantName);
}

Box::~Box() {
    delete[] plantName;
}

Box::Box(const Box &box) {
    num = box.num;
    plantName = new char[strlen(box.plantName) + 1];
    strcpy(plantName, box.plantName);
}

Box& Box::operator=(const Box &box) {
    if (this != &box) {
        delete[] plantName;
        num = box.num;
        plantName = new char[strlen(box.plantName) + 1];
        strcpy(plantName, box.plantName);
    }
    return *this;
}

int Box::getNum() const {
    return num;
}

char* Box::getPlantName() const {
    return plantName;
}

void Box::print() {
    cout << num << ", " << plantName << endl;
}