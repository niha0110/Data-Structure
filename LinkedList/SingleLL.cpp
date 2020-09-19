#include"SingleLL.h"

SNode::SNode()
{
    this->data = 0;
    this->next = nullptr;
}
int SNode::getData()
{
     return this->data;
}
void SNode::setData(int d)
{ 
    this->data = d;
}

SNode* SNode::getNext()
{ return this->next;}
void SNode::setNext(SNode *n)
{this->next = n;}

void SingleLL::InsertAtLast(int data)
{
    SNode *node = new SNode();
    node->setData(data);
    node->setNext(nullptr);
    if(head == nullptr)
    {
        head = node;
        length ++;
    }
    else
    {
        auto temp = head;
        
        for(int i=0; i < (length-1) ; i++)
        {
            temp = temp->getNext();
        }
        temp->setNext(node);
        length++;
    }
    
}
    
void SingleLL::InsertAtBeg(int data){
    SNode *node = new SNode();
    node->setData(data);
    node->setNext(nullptr);
    if(head == nullptr)
    {
        head = node;
        length ++;
    }
    else
    {
        auto temp = head;
        head = node;
        head->setNext(temp);
        length ++;
    }
    
}
void SingleLL::InsertAtPosition(int data, int pos){
    SNode *node = new SNode();
    node->setData(data);
    node->setNext(nullptr);
    if(head == nullptr || length < pos)
    {
        std::cout<<pos<<" is not there in the list"<<std::endl;
    }
    else
    {
        if(pos == 1)
        {
            InsertAtBeg(data);
        }
        else
        {
            auto temp = head;
            auto prev = head;
            for(int i = 1; i < pos ;i++)
            {
                prev = temp;
                temp = temp->getNext();
            }
            prev->setNext(node);
            prev->getNext()->setNext(temp);
            length++;
        }
    }
    
}

int SingleLL::DeleteAtLast(){ 
     if(head == nullptr)
    {
        std::cout<<"Nothing to delete!"<<std::endl;
        return -1;
    }
    if(length == 1)
    {
        int d = head->getData();
        delete(head);
        length=0;
        return d;
    }
    auto temp = head;
        
    for(int i=0; i < (length-2) ; i++)
    {
        temp = temp->getNext();
    }
    auto last = temp->getNext();
    int d = last->getData();
    temp->setNext(nullptr);
    delete(last);
    length--;
    return d;
    
}
int SingleLL::DeleteAtBeg(){
    if(length == 0)
    {
        std::cout<<"Nothing to delete!"<<std::endl;
        return -1;
    }
    if(length == 1)
    {
        int d = head->getData();
        delete(head);
        length=0;
        return d;
    }
    auto temp = head;
    head = head->getNext();
    int d = temp->getData();
    temp->setNext(nullptr);
    length --;
    delete(temp);
    return d;
}
int SingleLL::DeleteAtPosition(int pos){
    if(length == 0)
    {
        std::cout<<"Nothing to delete!"<<std::endl;
        return -1;
    }
    if(pos == 1)
        return DeleteAtBeg();
    if(pos == length)
        return DeleteAtLast();
    
    auto temp = head;
    auto prev = head;
    for(int i = 1; i < pos ;i++)
    {
        prev = temp;
        temp = temp->getNext();
    }
    prev->setNext(temp->getNext());
    int d = temp->getData();
    temp->setNext(nullptr);
    delete(temp);
    length--;
    return d;

}
    
void SingleLL::printList(){
    auto temp =head;
    for(int i = 0; i<length; i++)
    {
        std::cout<<temp->getData() <<std::endl;
        temp = temp->getNext(); 
    }
}
void SingleLL::searchNthFromEnd(int n){
    auto temp = head;
    auto nth = head;
    int i = 0;
    while(temp!= nullptr)
    {
        if(n <= i)
            nth = nth->getNext();
        temp = temp->getNext();
        i++;
    }

    std::cout<<n<<"th node from end: "<<nth->getData() <<std::endl;
}
void SingleLL::MakeitCircular(){
    auto temp = head;
    while(temp->getNext()!= nullptr)
    {
        temp = temp->getNext();
    }

    temp->setNext(head);
}

void SingleLL::ReverseList()
{
    SNode *ptr1, *ptr2, *ptr3;
    ptr1=head;
    ptr2 = head->getNext();
    ptr3 = ptr2->getNext();

    while(ptr2 != nullptr)
    {
        ptr2->setNext(ptr1);
        ptr1=ptr2;
        ptr2=ptr3;
        if(ptr3 != nullptr)
            ptr3 = ptr3->getNext();
    }

    head = ptr1;

}

SNode* SingleLL::SplitCList()
{
    SNode *slowptr, *fastptr;

    slowptr = fastptr = head;

    if(head == nullptr)
        return nullptr;

    while(fastptr->getNext()->getNext() != head && fastptr->getNext() != head)
    {
        fastptr = fastptr->getNext()->getNext();
        slowptr = slowptr->getNext();
    }
    
    if(fastptr == head)
        return nullptr;
    else
    {
        auto head2 = slowptr->getNext();
        slowptr->setNext(head);
        if(fastptr->getNext() != head)
        {
            fastptr=fastptr->getNext();
        }
        fastptr->setNext(head2);
        return head2;
    }
    
}

void SingleLL::printCircular(SNode *h)
{
    if(h == nullptr)
    {
        auto temp = head;
        while(temp->getNext() != head)
        {
            std::cout<<temp->getData()<<std::endl;
            temp = temp->getNext();
        }
        std::cout<<temp->getData()<<std::endl;
    }
    else
    {
        auto temp = h;
        while(temp->getNext() != h)
        {
              std::cout<<temp->getData()<<std::endl;
            temp = temp->getNext();
        }
        std::cout<<temp->getData()<<std::endl;
    }
    
}