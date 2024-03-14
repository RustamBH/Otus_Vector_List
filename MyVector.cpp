// MyVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyVector.h"


int main()
{    
    MyVector<int> myvec;

    for (size_t i = 0; i < 10; ++i) {
        myvec.push_back(i);
    }
    std::cout << "Output myvec: ";
    std::cout << myvec.print(); // 0 1 2 3 4 5 6 7 8 9

    std::cout << "Size myvec = " << myvec.getSize() << std::endl;  // 10

    std::cout << "Erase 3,5,7 elements from myvec by count: ";
    myvec.erase(2);
    myvec.erase(3);
    myvec.erase(4);    
    std::cout << myvec.print(); // 0 1 3 5 7 8 9    

    std::cout << "Size myvec = " << myvec.getSize() << std::endl;   // 7    
    myvec.insert(0, 10);
    std::cout << myvec.print(); // 10 0 1 3 5 7 8 9
    myvec.insert(4, 20);
    std::cout << myvec.print(); // 10 0 1 3 20 5 7 8 9
    int sz = myvec.getSize(); // 9
    myvec.insert(sz, 30);
    std::cout << myvec.print(); // 10 0 1 3 20 5 7 8 9 30
    
    std::cout << "myvec[" << sz << "] = " << myvec[sz] << std::endl; // 30
    std::cout << "Size myvec " << myvec.getSize() << std::endl; // 10
    std::cout << "Capacity myvec = " << myvec.getCapacity() << std::endl;  // 16 
}
