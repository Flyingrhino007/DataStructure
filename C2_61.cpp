//C++ file
/*=============================================
*
*      Filename: 20180819/C2_61.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 单链表，插入删除，连接等功能。
*        Create: 2018-08-28 14:23:29
# Last Modified: 2018-08-28 14:24:11
=============================================*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct ElemType 
{
    char name[10];
    int tel;
};
struct NodeType
{
    ElemType data;
    NodeType *next;
};

class LinkListC
{
private:
    NodeType *Head;
    //int length;
public:
    NodeType * returnHead();
    int length;
    LinkListC();
    ~LinkListC();
    void Creat();
    void Insert(ElemType x);
    void Insert(const char* , ElemType x);
    void delet(ElemType x);
    void Display();
    void leng();
    void delet_repeat();
    void reverse();
    void lin(LinkListC & x);
};

LinkListC::LinkListC()
{
    Head = new NodeType;
    Head->next = nullptr;
//    Head->data.name = 'a';
    strcpy(Head->data.name,"");
    Head->data.tel = 0;
    cout<<"\n init!\n";
}

LinkListC::~LinkListC()
{
    NodeType *p = Head->next;
    while(p != nullptr)
    {
        Head->next = p->next;
        delete p;
        p = Head->next;
    }
    cout<<"\n 链表已删除。"<<endl;
    delete Head;
}

NodeType * LinkListC::returnHead()
{
    return Head;
}

void LinkListC::Display()
{
    NodeType *p;
    p = Head->next;
    while(p!=nullptr)
    {
        cout<<"\n";
        cout<<p->data.name<<"  ";
        cout<<p->data.tel<<endl;
        p=p->next;
    }
    cout<<endl;
}

void LinkListC::Creat()
{
    NodeType *p,*s;
    ElemType x;
    p = Head;
    cout<<"\n name=?";
    cin>>x.name;
    cout<<"tel=>(-999end)";
    cin>>x.tel;
    length = 0;
    while(x.tel!=-999)
    {
        s = new NodeType;
        s->data = x;
        s->next = nullptr;
        p->next = s;
        p = s;
        cout<<"\n name=?";
        cin>>x.name;
        cout<<"tel=?(-999end)";
        cin>>x.tel;
        length++;
    }
    cout<<"\n  链表建立结束。\n链表长度为"<<length;
}

void LinkListC::Insert(ElemType x)
{
    NodeType *p,*q,*s;
    s = new NodeType;
    s->data = x;
    q = Head;
    p = q->next;
    while(p!=nullptr && strcmp(p->data.name, x.name)<0)
    {
        q = p;
        p = p->next;
    }
    s->next = p;
    q->next = s;
}

void LinkListC::delet(ElemType x)
{
    NodeType *p,*q,*s;
    q = Head;
    p = Head->next;
    while(p!=nullptr && strcmp(p->data.name,x.name)!=0)
    {
        q = p;
        p = p->next;
    }
    if(p!=nullptr)
    {
        q->next = p->next;
        delete p;
        cout<<"\n 删除节点成功"<<endl;
    }
    else
        cout<<"\n x.name 不存在\n";
    
}

void LinkListC::leng()
{
    NodeType *p = Head->next;
    int len = 0;
    while(p != nullptr){
        len++;
        p = p->next;
    }
    cout<<"\n链表长度为 "<<len;
}

void LinkListC::Insert(const char *name_a,ElemType b)
{
    NodeType *s = Head->next;
    NodeType *tmp = new NodeType;
    tmp->data = b;
    cout<<tmp;
    while(strcmp(s->data.name, name_a)!=0 && s!=nullptr)
    {
        s = s->next;
    }
    if(s != nullptr)
    {
        tmp->next = s->next;
        s->next = tmp;
    }
    else
        s->next = tmp;
}

void LinkListC::delet_repeat()
{
    NodeType *p = Head->next;
    while(p!=nullptr)
    {
        NodeType *q = p;
        for(NodeType *tmp = q->next; tmp!= nullptr; )
        {
            if(strcmp(tmp->data.name, p->data.name)==0)
            {
                q->next = tmp->next;
                delete tmp;
                tmp = q->next;
                //cout<<tmp->data.name<<endl;
                //cout<<tmp->data.tel<<endl;
                //cout<<tmp->next<<endl;
                cout<<"\n删除相同项完成";
            }
            else
            {
                q = q->next;
                tmp = q->next;
            }
        }
        p = p->next;
    }
}

void LinkListC::reverse()
{
    NodeType *p = Head->next;
    NodeType *q = p->next;
    p->next = nullptr;
    NodeType *tmp = q->next;
    while(tmp != nullptr)
    {
        q->next = p;
        p = q;
        q = tmp;
        tmp = tmp->next;
    }
    q->next = p;
    Head->next = q;
    cout<<"\n\n链表逆置完成";
}

void LinkListC::lin(LinkListC & gg)
{
    NodeType *ph = Head->next;
    NodeType *pg = gg.returnHead();
    pg = pg->next;
    cout<<ph->data.name<<endl;
    cout<<pg->data.name<<endl;
    while(pg->next != nullptr)
    {
        NodeType *r = pg->next;
        pg->next = ph->next;
        ph->next = pg;
        ph = pg->next;
        pg = r;
    }
    pg->next = ph->next;
    ph->next = pg;
    cout<<"\n\n链表连接完成";
}

int main (int argc, char *argv[])
{
    ElemType e;
    LinkListC h,gg;
    int k;
    cout<<"\n              线性单链表存储结构演示";
    do{
        cout<<"\n\n       1.初步建立单链表";
        cout<<"\n\n       2.插入新电话记录";
        cout<<"\n\n       3.删除一个电话记录";
        cout<<"\n\n       4.显示链表长度";
        cout<<"\n\n       5.插入b到a之后";
        cout<<"\n\n       6.删除链表相同项目";
        cout<<"\n\n       7.逆置链表";
        cout<<"\n\n       8.建立链表2";
        cout<<"\n\n       9.合并2条链表为链表C";
        cout<<"\n\n       10.结束程序";
        cout<<"\n***************************";
        cout<<"\n  请输入你的选择（1,2,3,4,5,6,7,8,9,10）";
        cin>>k;
        switch(k)
        {
            case 1:
                h.Creat();
                h.Display();
                break;
            case 2:
                cout<<"\n 插入的姓名=?";
                cin>>e.name;
                cout<<"\n 插入的电话号=?";
                cin>>e.tel;
                h.Insert(e);
                h.Display();
                break;
            case 3:
                cout<<"\n 删除的姓名=>";
                cin>>e.name;
                h.delet(e);
                h.Display();
                break;
            case 4:
                h.leng();
                break;
            case 5:
                cout<<"\n插入到？之后:";
                char name_a[10];
                cin>>name_a;
                cout<<"\n插入的name?";
                ElemType b;
                cin>>b.name;
                cout<<"\n插入的tel?";
                cin>>b.tel;
                h.Insert(name_a, b);
                h.Display();
                break;
            case 6:
                h.delet_repeat();
                h.Display();
                break;
            case 7:
                h.reverse();
                h.Display();
                break;
            case 8:
                gg.Creat();
                gg.Display();
                break;
            case 9:
                if(h.length>gg.length)
                    h.lin(gg);
                else
                    gg.lin(h);
                cout<<"\n---------------------------------";
                h.Display();
                cout<<"\n---------------------------------";
                gg.Display();
                break;
            default:
                break;
        }
        cout<<"\n---------------------------";
    }while(k>=1 && k<10);
    cout<<"\n        再见!";
    cout<<"\n        按任意键返回";
    return 0;
}
