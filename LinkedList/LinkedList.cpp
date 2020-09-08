#include<iostream>
#include"SingleLL.h"

int main()
{
    std::cout<<"Linked Lists";
    std::cout<< std::endl;

    SingleLL sll;
    sll.InsertAtBeg(2);
    sll.InsertAtBeg(1);
    sll.InsertAtLast(4);
    sll.InsertAtLast(5);
    sll.InsertAtPosition(3,3);

    sll.printList();
}