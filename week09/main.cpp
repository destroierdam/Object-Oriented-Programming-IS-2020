#include <iostream>
#include "Node.h"
#include "LinkedList.h"
int main()
{
    LinkedList<int> list;
    list.print(); // nullptr

    list.push_front(15);
    list.print(); // 15 -> nullptr
    list.push_front(10);
    list.print(); // 10 -> 15 -> nullptr
    list.push_back(20);
    list.print(); // 10 -> 15 -> 20 -> nullptr

    cout << "____________\n";


    LinkedList<int> newList(list);
    newList.print();
}
