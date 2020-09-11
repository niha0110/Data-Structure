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
void SingleLL::searchData(int data){}