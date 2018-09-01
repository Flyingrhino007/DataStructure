#include<iostream>
using namespace std;

template<class T>class SqStack
{
public:
    SqStack(int s=30);
    ~SqStack(){delete[] elem;}
    void Push(T item);
    T Pop();
    T GetTop();
    void MakeEmpty(){top = -1;}
    int IsEmpty(){return top == -1;}
    int IsFull(){return top == maxSize-1;}
    void PrintOut();
private:
    int top;
    T *elem;
    int maxSize;
};

template<class T>SqStack<T>::SqStack(int s)
{
    top =-1;
    maxSize=s;
    elem=new T[maxSize];
    for(int i=0; i<maxSize; i++)
        elem[i]=0;
}

template<class T>void SqStack<T>::Push(T item)
{
    if(!IsFull())
    {
        top++;
        elem[top]=item;
    }
}

template<class T>T SqStack<T>::Pop()
{
    T x;
    if(!IsEmpty())
    {
        x = elem[top];
        top--;
    }
    return x;
}

template<class T>T SqStack<T>::GetTop()
{
    if(!IsEmpty())
        return elem[top];
}

template<class T>void SqStack<T>::PrintOut()
{
    int i=0;
    if(IsEmpty())
        cout<<"\n 栈已空";
    else
    {
        i = top;
        while(i!= -1)
        {
            cout<<"\n data="<<elem[i];
            i--;
        }
    }
    cout<<"\n任意键继续";
}
