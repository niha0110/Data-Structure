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

    SingleLL sll1;
    sll1.InsertAtBeg(5);
    sll1.InsertAtBeg(4);
    sll1.InsertAtBeg(3);
    sll1.InsertAtBeg(2);
    sll1.InsertAtBeg(1);

    std::cout<<"Second List:"<<std::endl;
    sll1.printList();

    sll1.searchNthFromEnd(2);
    sll1.searchNthFromEnd(3);
    sll1.searchNthFromEnd(4);

    sll1.ReverseList();
    sll1.printList();

    SingleLL sll2;
    sll2.InsertAtBeg(5);
    sll2.InsertAtBeg(4);
    sll2.InsertAtBeg(3);
    sll2.InsertAtBeg(2);
    sll2.InsertAtBeg(1);

    sll2.MakeitCircular();
    auto head2 = sll2.SplitCList();
    std::cout<<"List1:\n";
    sll2.printCircular();
    std::cout<<"List2:\n";
    sll2.printCircular(head2);


}