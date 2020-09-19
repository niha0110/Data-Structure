#include<iostream>

class SNode
{
    int data;
    SNode *next;
    public:
    SNode();
    int getData(); 
    void setData(int d);
    SNode* getNext();
    void setNext(SNode *n);
};
class SingleLL
{
    SNode *head;
    int length;
    public:
    SingleLL()
    {
        head = nullptr;
        length=0;
    }
    void InsertAtLast(int data);
    void InsertAtBeg(int data);
    void InsertAtPosition(int data, int pos);

    int DeleteAtLast();
    int DeleteAtBeg();
    int DeleteAtPosition(int pos);
    
    void printList();
    void searchPosition(int pos);
    void MakeitCircular();
    void searchNthFromEnd(int n);
    void ReverseList();
    SNode * SplitCList();
    void printCircular(SNode *h = nullptr);
};