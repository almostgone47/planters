//
// Created by Jeremiah Barro on 22/8/2023.
//
#include <cstring>
#include "../include/Box.h"

// Name:   Box
// Desc:   Box Constructor
// Input:  None
// Output: None
// Return: None
Box::Box() {
    this->boxNum = 0;
    this->plantName = new char[1];
    strcpy(this->plantName, "");
}

// Name:   Box
// Desc:   Box Constructor
// Input:  An integer representing the box number and a pointer to a constant character representing the plant name.
// Output: None
// Return: None
Box::Box(int boxNum, const char *plantName) {
    this->boxNum = boxNum;
    this->plantName = new char[strlen(plantName) + 1];
    strcpy(this->plantName, plantName);
}

// Name:   ~Box
// Desc:   Box Destructor
// Input:  None
// Output: None
// Return: None
Box::~Box() {
    delete[] plantName;
    plantName = nullptr;
}

// Name:   Box
// Desc:   Copy Constructor
// Input:  A reference to a constant Box object to be copied.
// Output: None
// Return: None
Box::Box(const Box &box) {
    boxNum = box.boxNum;
    plantName = new char[strlen(box.plantName) + 1];
    strcpy(plantName, box.plantName);
}

// Name:   =
// Desc:   Assignment Operator
// Input:  A reference to a constant Box object to be copied.
// Output: None
// Return: A reference to the modified Box object after the copy.
Box& Box::operator=(const Box &box) {
    if (this != &box) {
        delete[] plantName;
        boxNum = box.boxNum;
        plantName = new char[strlen(box.plantName) + 1];
        strcpy(plantName, box.plantName);
    }

    return *this;
}

// Name:   getNum
// Desc:   Getter for the boxNum.
// Input:  None
// Output: None
// Return: An integer representing the box number.
int Box::getNum() const {
    return boxNum;
}

// Name:   getPlantName
// Desc:   Getter for the plantName of the Box.
// Input:  None
// Output: None
// Return: A constant pointer to the character array representing the plant name.
char* Box::getPlantName() const {
    return plantName;
}