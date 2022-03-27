#include<algorithm>
#include<iterator>
#include<iostream>

template<class T>
class Vector
{
    T *arr;
    int size;
    int capacity;

    public:
        Vector()
        {
            arr = new T[1];
            capacity = 1;
            size = 0;
        }
        Vector(const int s)
        {
            arr = new T[s];
            capacity = s;
            size = 0;
        }
        Vector(const Vector &v)
        {
            arr = new T[v.getCapacity()];
            capacity = v.getCapacity();
            size = v.getSize();
            std::copy_n(v.getArray(),size,arr);
        }
        T* getArray()
        {
            return arr;
        }
        int getSize()
        {
            return size;
        }
        int getCapacity()
        {
            return capacity;
        }
        void push_back(T data)
        {
            if(size==capacity)
            {
                capacity *= 2;
                T *temp = new T[capacity];
                std::copy_n(arr,size,temp);
                delete[] arr;
                arr = temp;
            }
            arr[size]=data;
            size++;
        }
        void resize(int s)
        {
            if(size>=s)
            {
                size = s;
            }
            else
            {
                std::cout<<"Cannot resize!"<<std::endl;
            }
        }
        bool empty()
        {
            if(size == 0)
                return true;
            return false;
        }
        void shrink_to_fit()
        {
            capacity = size;
            T *temp = new T[capacity];
            std::copy_n(arr,size,temp);
            delete[] arr;
            arr = temp;
        }
        T at(int index)
        {
            return arr[index];
        }
        void pop_back()
        {
            if(size!=0)
            {
                size = size-1;
            }
            else
            {
                std::cout<<"No elements present!"<<std::endl;
            }
        }
        void print()
        {
            for(int i=0;i<size;i++)
                std::cout<<arr[i]<<std::endl;
        }
};