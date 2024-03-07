// MyList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyList.h"


int main()
{
    MyList<int> mylist;

    for (size_t i = 0; i < 10; ++i) {
        mylist.push_back(i);
    }

    std::cout << "Output mylist: ";
    mylist.print(); // 0 1 2 3 4 5 6 7 8 9

    std::cout << "Size mylist: " << mylist.getSize() << std::endl;    

    std::cout << "Erase 3,5,7 elements from mylist by count: ";
    mylist.erase(2);
    mylist.erase(4);
    mylist.erase(6);
    std::cout << std::endl;    
    mylist.print(); // 0 1 2 3 4 5 6 7 8 9    

    std::cout << "Size mylist = " << mylist.getSize() << std::endl;   // 7    
    mylist.insert(0, 10);
    mylist.print(); // 10 0 1 3 5 7 8 9
    mylist.insert(4, 20);
    mylist.print(); // 10 0 1 3 20 5 7 8 9
    
    int sz = mylist.getSize();
    std::cout << "Size mylist " << sz << std::endl; // 10
    mylist.insert(sz, 30);
    mylist.print(); // 10 0 1 3 20 5 7 8 9 30      
    
    std::cout << "mylist["<< sz << "] = " << mylist[sz] << std::endl; // 30
    std::cout << "Size mylist " << mylist.getSize() << std::endl; // 10    
}
