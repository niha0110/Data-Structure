#include<iostream>
#include"Vector.h"

int main()
{
    Vector<int> vec;
    for(int i=1; i<=5; i++)
        vec.push_back(i);
    std::cout<<"-------------------------------------------------------"<<std::endl;
    std::cout<<vec.getSize()<<std::endl;
    std::cout<<vec.getCapacity()<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    vec.print();
    std::cout<<"-------------------------------------------------------"<<std::endl;
    std::cout<<vec.at(3)<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    vec.push_back(9);
    vec.print();
    std::cout<<"-------------------------------------------------------"<<std::endl;
    vec.pop_back();
    vec.print();
    std::cout<<"-------------------------------------------------------"<<std::endl;
    vec.resize(4);
    vec.print();
    std::cout<<"-------------------------------------------------------"<<std::endl;
    std::cout<<vec.getSize()<<std::endl;
    std::cout<<vec.getCapacity()<<std::endl;
    vec.shrink_to_fit();
    std::cout<<vec.getSize()<<std::endl;
    std::cout<<vec.getCapacity()<<std::endl;

    return 0;
}
