//
// Created by Jeremiah Barro on 22/8/2023.
//

#ifndef PLANTERS_BOX_H
#define PLANTERS_BOX_H

#include <iostream>

using namespace std;

class Box {
    private:
        int num;
        char *plantName;

    public:
        Box();
        Box(int num, const char *plantName);
        ~Box();
        Box(const Box &other);
        Box& operator=(const Box &other);

        int getNum() const;
        char* getPlantName() const;
        void print();

};

#endif //PLANTERS_BOX_H
