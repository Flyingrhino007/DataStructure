#include<iostream>
using namespace std;

typedef int KeyType;
struct BstNode
{
    KeyType key;
//    char ch;
    BstNode *lch, *rch;
};

class Bstree
{
public:
    Bstree(){root = nullptr;}
    ~Bstree(){postorderX(root);cout<<"\n 调用析构函数";}
    void postorderX(BstNode *&p);
    void creat();
    void inorder(){inorder(root);}
    int Search(KeyType K);
    void Insert(KeyType K);
private:
    BstNode *root;
    BstNode *insert(BstNode *t, BstNode *s);
    void inorder(BstNode *p);
};

/*Bstree::~Bstree()*/
//{
    //BstNode *q = root;
    //while(q!=nullptr)
        //postorderX(q);
    //cout<<"\n 调用析构函数";
//}

void Bstree::postorderX(BstNode *&p)
{
    if(p!=nullptr)
    {
        postorderX(p->lch);
        postorderX(p->rch);
        delete p;
    }
}

void Bstree::creat()
{
    BstNode *s;
    int n, i;
    KeyType k;
    cout<<"\n n=?";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"\n key=?"<<i<<" ";
        cin>>k;
        s = new BstNode;
        s->key = k;
        s->lch = nullptr;
        s->rch = nullptr;
        root = insert(root, s);
    }
}

BstNode *Bstree::insert(BstNode *t, BstNode *s)
{
    if(t == nullptr)
        t = s;
    else if(s->key < t->key)
        t->lch = insert(t->lch, s);
    else
        t->rch = insert(t->rch, s);
    return t;
}

void Bstree::inorder(BstNode *p)
{
    if(p != nullptr)
    {
        inorder(p->lch);
        cout<<"\t"<<p->key;
        inorder(p->rch);
    }
}

int Bstree::Search(KeyType K)
{
    int flag = 0;
    BstNode *q = root;
    while(q!= nullptr && flag ==0)
    {
        if(q->key == K)
        {
            cout<<"\n 查询成功"<<q->key;
            flag = 1;
        }
        else if (K<q->key)
            q = q->lch;
        else
            q = q->rch;
    }
    if(flag == 0)
        cout<<"\n 查询失败";
    return flag;
}

void Bstree::Insert(KeyType K)
{
    int flag = 0;
    BstNode *q = root, *p, *r;
    while(q!=nullptr && flag==0)
    {
        if(K == q->key)
        {
            cout<<"\n 查找成功，不再插入";
            flag = 1;
        }
        else if(K<q->key)
        {
            p = q;
            q = q->lch;
        }
        else
        { 
            p = q;
            q = q->rch;
        }
        if(flag ==0)
        {
            cout<<"\n 查找，无此节点，进行插入";
            r = new BstNode;
            r->key = K;
            r->lch = nullptr;
            r->rch = nullptr;
            if(K < p->key)
                p->lch = r;
            else
                p->rch = r;
        }
    }
}

int main(int argc, char *argv[])
{
    Bstree H;
    KeyType key00;
    int k;
    char ch;
    cout<<"\n\n    1.建立二叉树并且中序遍历";
    cout<<"\n    2.在树中查找关键字";
    cout<<"\n    3.准备插入新元素";
    cout<<"\n    4.结束程序";
    cout<<"\n------------------------------------------";
    cout<<"\n请输入你的选择(1,2,3,4)";
    cin>>k;
    while(k>0 && k<4)
    {
        switch(k)
        {
            case 1:
                H.creat();
                cout<<"\n 中跟遍历输出";
                H.inorder();
                break;
            case 2:
                cout<<"\n 请输入查找的关键字";
                cin>>key00;
                H.Search(key00);
                break;
            case 3:
                cout<<"\n 请输入插入的关键字";
                cin>>key00;
                H.Insert(key00);
                H.inorder();
                break;
            default:
                break;
        }
        cout<<"\n请输入你的选择(1,2,3,4)";
        cin>>k;
    }
    cout<<"\n 程序结束";
    return 0;
}
