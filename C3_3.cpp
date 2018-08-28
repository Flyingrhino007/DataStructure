//C++ file
/*=============================================
*
*      Filename: 20180824/C3_3.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 链表栈，插入删除，取栈顶元素
*        Create: 2018-08-28 14:27:38
# Last Modified: 2018-08-28 14:28:02
=============================================*/

#include<string>
#include<string.h>
using namespace std;

struct Elem
{
    char name[10];
    Elem *next;
};

class SqBT
{
private:
    Elem *top;
public:
    SqBT();
    ~SqBT();
    void Creat();
    void GetTop();
    void Reset();
    void SqBTpush(const char *inname);
    Elem SqBTpop();
};

SqBT::SqBT()
{
    top = nullptr;
}

SqBT::~SqBT()
{
    Elem *p = top;
    while(top != nullptr){
        top = p->next;
        delete p;
        p = top;
    }
}

void SqBT::Creat()
{
    top = new Elem;

}

void SqBT::SqBTpush(const char *inname)
{
    Elem *p = new Elem;
    p->next = top;
    strcpy(p->name,inname);
    top = p;
}

Elem SqBT::SqBTpop()
{
    Elem x;
    Elem *p = top;
    if(top != nullptr)
    {
        strcpy(x.name, p->name);
        top = p->next;
        delete p;
    }
    else if(top == nullptr)
    {
        cout<<"\n\n栈为空：";
    }
    return x;
}

void SqBT::GetTop()
{
    if(top != nullptr)
    {
        cout<<"\n"<<top->name;
    }
    else if(top == nullptr)
        cout<<"\n\n 栈为空";
}

void SqBT::Reset()
{
    while(top != nullptr)
    {
        Elem *p = top;
        top = p->next;
        delete p;
    }
}

int main(int agrc, char* argv[])
{
    int k;
    Elem e;
    SqBT SS;
    cout<<"\n\n    1.入栈：插入数据元素 ";
    cout<<"\n\n    2.出栈：删除数据元素";
    cout<<"\n\n    3.输出栈顶元素";
    cout<<"\n\n    4.结束程序";
    cout<<"\n--------------------------------------";
    do
    {
        cout<<"\n请输入选择的模式：";
        cin>>k;
        switch(k)
        {
            case 1:
                cout<<"\n\n 请输入压入栈的姓名：";
                cin>>e.name;
                SS.SqBTpush(e.name);
                break;
            case 2:
                e = SS.SqBTpop();
                cout<<"\n\n 弹出的是："<<e.name;
                break;
            case 3:
                cout<<"\n栈顶元素是：";
                SS.GetTop();
                break;
            default:
                break;
        }
    }while(k>=1 && k<4);
    cout<<"程序结束！";
    return 0;
}
