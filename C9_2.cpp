#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node *next;
    int yx(int i);
};

class ListNode
{
private:
    Node *root;
    int n;
public:
    ListNode();
    ~ListNode();
    void Creat();
    void PrintOUt();
    void StinSort();
    void RadixSort();
};

int Node::yx(int i)
{
    int m = key,x=0;
    switch(i)
    {
        case 1:
            x = m%10;
            break;
        case 2:
            x = (m%100)/10;
            break;
        case 3:
            x = (m%1000)/100;
            break;
        case 4:
            x = (m%10000)/1000;
            break;
        default:
            break;
    }
    return x;
}

ListNode::ListNode()
{
    root = new Node;
    root->key = 0;
    root->next = nullptr;
}

ListNode::~ListNode()
{
    Node *p = root->next;
    while(p!=nullptr)
    {
        Node *q = p->next;
        delete p;
        p = q;
    }
    delete root;
    cout<<"\n\n 调用析构函数";
}

void ListNode::Creat()
{
    cout<<"\n请输入元素个数n：";
    int nn;
    cin>>nn;
    n = nn;
    long int a = 1001;
    Node *q = root;
    for(int i=0;i<n;i++)
    {
        Node *p = new Node;
        a = (a*125)%3257;
        p->key = (int)a;
        p->next = nullptr;
        q->next = p;
        q = q->next;
    }
}

void ListNode::PrintOUt()
{
    Node *p = root->next;
    cout<<"\n输出表:\n";
    while(p!=nullptr)
    {
        cout<<p->key<<"\t";
        p = p->next;
    }
}

void ListNode::StinSort()                       //链表实现插入排序
{
    Node *p = root->next->next;
    while(p!=nullptr)
    {
        Node *pp = root;
        Node *q = pp->next;
        Node *Tmp = p->next;
        while(q!=p &&(q->key < p->key))
        {
            q = q->next;
            pp = pp->next;
        }
        if(q!=p)
        {
            pp->next = p;
            p->next = q;
            while(q->next!=p)
                q = q->next;
            q->next = Tmp;
        }
        p = Tmp;
    }
}

void ListNode::RadixSort()
{
    Node *p = root->next;
    Node f[10],e[10];
    for(int i=1;i<=4;i++)
    {
        for(int i=0;i<10;i++)                   //f[],e[]存放有效数字序列，数组Node和指针Node调用成员函数的区别，.和->
        {
            f[i].key = 0;
            f[i].next = nullptr;
            e[i].key = 0;
            e[i].next = nullptr;
        }
        while(p!=nullptr)                       //将链表元素依次求出指定位数上的有效数字，划分到相应序列
        {
            int k = p->yx(i);
            if(f[k].next==nullptr)
            {
                f[k].next = p;
                e[k].next = p;
            }
            else
            {
                Node *m = e[k].next;
                e[k].next->next = p;
                e[k].next = p;
            }
            p = p->next;
        }
        int j=0;
        while(f[j].next==nullptr)
            j++;
        p = f[j].next;
        root->next = p;                         //时刻不要忘记链表是从root开始的
        Node *m = e[j].next;
        while(j<10)                             //把各有效数字序列的Node，收集并排序
        {
            j++;
            while(j<10 && f[j].next == nullptr)
                j++;
            if(j<10 && f[j].next!=nullptr)
            {
                m->next = f[j].next;
                m = e[j].next;
            }
            m->next = nullptr;
        }
    }
}

int main(int argc, char *argv[])
{  
    ListNode List;
    int k;
    cout<<"\n\n 1.产生一批随机数准备排序";
    cout<<"\n 2.一般情况的插入排序";
    cout<<"\n 3.动态链表实现基数排序";
/*    cout<<"\n 4.一般情况选择排序";*/
    //cout<<"\n 5.有序情况的快速排序";
    //cout<<"\n 6.插入排序";
    
    cout<<"\n 4.结束程序";
    cout<<"\n---------------------------------";
    cout<<"\n 请输入你的选择:";
    cin>>k;
    while(k>0&&k<4)
    {
        switch(k)
        {
            case 1:
                List.Creat();
                List.PrintOUt();
                break;
            case 2:
                List.StinSort();
                List.PrintOUt();
                break;
            case 3:
                List.RadixSort();
                List.PrintOUt();
                break;
            default:
                break;
        }
    cout<<"\n---------------------------------";
    cout<<"\n 请输入你的选择:";
    cin>>k;
    }
    cout<<"\n\n 程序结束";
    return 0;
}
