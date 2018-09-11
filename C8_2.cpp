#include<iostream>
using namespace std;

typedef int KeyType;
const int MAXSIZE = 100;
struct ElemNode
{
    KeyType key;
    ElemNode *next;
};
class LinkHash
{
private:
    ElemNode *ht;
    int n;
    KeyType p;
public:
    LinkHash(int , int);
    ~LinkHash(){};
    int find(KeyType K);
    void creat_hash();
    void Printout();
};

LinkHash::LinkHash(int n1, int p1)
{
    n = n1;
    p = p1;
    ht = new ElemNode[n];
    for(int i=0; i<n; i++)
    {
        ht[i].key = 0;
        ht[i].next = nullptr;
    }
}
/*LinkHash::~LinkHash()*/
//{
    //for(int i=0; i<n; i++)
    //{
        //ht[i].key = 0;
        //while(ht[i].next != nullptr)
        //{
            //ElemNode *p =ht[i].next;
            //ElemNode *q = p->next;
            //if(q==nullptr)
            //{
                //delete p;
                //break;
            //}
            //while(q!=nullptr)
            //{
                //delete p;
                //p = q;
                //q = q->next;
            //}
        //}
    //}
/*}*/

int LinkHash::find(KeyType K)
{
    ElemNode *q;
    int i= K%p;
    if(ht[i].key == K)
        return i;
    q = ht[i].next;
    while(q!=nullptr && q->key != K)
        q = q->next;
    if(q!=nullptr && q->key == K)
        return i;
    else
        return -1;
}

void LinkHash::creat_hash()
{
    int i,j,K;
    ElemNode *r,*s,*q;
    cout<<"\n 请逐一输入各个关键字(-1结束)";
    cin>>K;
    while(K!=-1)
    {
        i = K%p;
        if(ht[i].key == 0)
        {
            ht[i].key = K;
            cout<<"\n 插入成功";
        }
        else if(ht[i].key == K)
            cout<<"\n查找成功，不再插入，位置在"<<i;
        else
        {
            q = ht[i].next;
            r = q;
            while(q!=nullptr && q->key!=K)
            {
                r = q;
                q = q->next;
            }
            if(q!=nullptr && q->key == K)
                cout<<"\n查找成功，不再插入，位置在  的外链上"<<i;
            else
            {
                s = new ElemNode;
                s->key = K;
                s->next = nullptr;
                if(ht[i].next == nullptr)
                    ht[i].next = s;
                else
                    r->next = s;
                cout<<"\n插入成功";
            }
        }
        cout<<"\n 请逐一输入各个关键字(-1结束)";
        cin>>K;
    }
}

void LinkHash::Printout()
{
    int i, j;
    ElemNode *r,*s;
    for(int i=0; i<n; i++)
    {
        cout<<"\n  i= ";
        if(ht[i].key != 0)
            cout<<"  key="<<ht[i].key;
        r = ht[i].next;
        while(r!=nullptr)
        {
            cout<<"\tkey= "<<r->key;
            r = r->next;
        }
    }
}

int main(int argc, char *argv[])
{
    int p0,n0,i;
    cout<<"\n 请输入n值(n应大于等于记录总数)";
    cin>>n0;
    cout<<"\n 请输入p值(p应不大于n的质数)";
    cin>>p0;
    LinkHash ha(n0,p0);
    ElemNode a;
    int k;
    char ch;
    cout<<"\n\n    1.建立哈希表(链地址法)";
    cout<<"\n    2.在哈希表中查找关键字";
    cout<<"\n    3.输出哈希表";
    cout<<"\n    4.结束程序";
    cout<<"\n------------------------------------------";
    cout<<"\n请输入你的选择(1,2,3,4)";
    cin>>k;
    while(k>0 && k<4)
    {
        switch(k)
        {
            case 1:
                ha.creat_hash();
                break;
            case 2:
                cout<<"\n 请输入待查找的关键字：";
                cin>>a.key;
                i=ha.find(a.key);
                if(i==-1)
                    cout<<"\n 关键字"<<a.key<<" 不存在";
                else
                    cout<<"\n 成功查找到"<<a.key<<" 位置在"<<i;
                break;
            case 3:
                ha.Printout();
                break;
            default:
                break;
        }
        cout<<"\n请输入你的选择(1,2,3,4)";
        cin>>k;
    }
    return 0;
}
