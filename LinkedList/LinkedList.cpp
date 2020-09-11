#include<iostream>
#include"SingleLL.h"

int main()
{
    std::cout<<"Linked Lists";
    std::cout<< std::endl;

    SingleLL sll;
    std::cout<<"Insertion"<<std::endl;
    sll.InsertAtBeg(2);
    sll.InsertAtBeg(1);
    sll.InsertAtLast(4);
    sll.InsertAtLast(5);
    sll.InsertAtPosition(3,3);

    std::cout<<"All list"<<std::endl;
    sll.printList();

    std::cout<<"Deletion"<<std::endl;
    std::cout<< sll.DeleteAtPosition(3)<<std::endl;
    std::cout<< sll.DeleteAtBeg()<<std::endl;
    std::cout<< sll.DeleteAtLast()<<std::endl;

    std::cout<<"All list"<<std::endl;
    sll.printList();
}