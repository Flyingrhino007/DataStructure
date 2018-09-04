#include<iostream>
using namespace std;
template<class T>class SqQueue
{
public:
    SqQueue(int sz=30);
    ~SqQueue(){delete[] elem;}
    void EnQueue(T item);
    T DeQueue();
    T GetFront();
    void MakeEmpty(){ front=rear=0;}
    bool IsEmpty(){ return front==rear;}
    bool IsFull(){ return (rear+1)&Maxsize==front;}
    int length(){ return (rear-front+Maxsize)%Maxsize;}
    void PrintOut();
private:
    int front, rear;
    T *elem;
    int Maxsize;
};

template<class T>SqQueue<T>::SqQueue(int sz)
{
    front = 0;
    rear = 0;
    Maxsize = sz;
    elem = new T[Maxsize];
    for(int i=0; i<Maxsize; i++)
        elem[i] = 0;
}

template<class T>void SqQueue<T>::EnQueue(T item)
{
    if(!IsFull())
    {
        rear = (rear+1)%Maxsize;
        elem[rear] = item;
    }
}

template<class T>T SqQueue<T>::DeQueue()
{
    if(!IsEmpty())
    {
        front = (front+1)%Maxsize;
        return elem[front];
    }
}

template<class T>T SqQueue<T>::GetFront()
{
    if(!IsEmpty())
    {
        return elem[(front+1)%Maxsize];
    }
}

template<class T>void SqQueue<T>::PrintOut()
{
    int i;
    if(IsEmpty())
        cout<<"\n队列为空";
    else
    {
        i = rear;
        while(i!=front)
        {
            cout<<elem[i]<<"\t";
            i = (i-1)%Maxsize;
        }
    }
    cout<<"\n 按任意键，继续";
}
