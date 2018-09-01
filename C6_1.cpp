#include<iostream>
#include<SqStack.h>
using namespace std;

typedef int Elemtype;
struct Nodetype
{
    Elemtype data;
    Nodetype *lch;
    Nodetype *rch;
};
class BiTree
{
public:
    BiTree(){ root = nullptr;}
    ~BiTree(){ destroy(root);}
    void Creat();
    void inorder(){ int i=0;inorder(root, i);cout<<"\n"<<i<<"个节点";}                     //不带z为递归遍历算法
    void inorderz();                                    //带z为非递归遍历算法
    void preorder(){ preorder(root);}
    void preorderz();
    void postorder(){ postorder(root);}
    void postorderz();
    int predepth(){ return predepth(root);}
private:
    Nodetype *root;
    Nodetype *creat_bt();
    void preorder(Nodetype *p);
    void inorder(Nodetype *p, int &i);
    void postorder(Nodetype *p);
    int predepth(Nodetype *t);
    void destroy(Nodetype *&p);
    int max(int x, int y);

};

void BiTree::Creat()
{
    cout<<"\n 按照二叉树 先根次序，且将空孩子置为零，组织数据\n";
    cout<<"\n 每次输入节点的数据，假设是一颗3个节点的满二叉树\n";
    cout<<"\n 那么输入应该是1 2 0 3 0 0\n 以-999结束";
    root = creat_bt();
}

Nodetype *BiTree::creat_bt()
{
    Nodetype *t;
    Elemtype e;
    cout<<"\n data = ";
    cin>>e;
//    while(e!=-999)
//    {
        if(e==0)
        {
//            t->data = 0;
//            t->lch = nullptr;
//            t->rch = nullptr;
            t = nullptr;
        }
        else{
            t = new Nodetype;
            t->data = e;                //先根次序建立
            t->lch = creat_bt();
            t->rch = creat_bt();
        }
//    }
    return t;
}

void BiTree::destroy(Nodetype *&p)          //删除二叉树
{
    if(p!=nullptr)
    {
        destroy(p->lch);
        destroy(p->rch);
        delete p;
    }
    cout<<"\n删除节点";
}

void BiTree::inorder(Nodetype *p, int &i)           //中根递归遍历
{
    if(p!=nullptr)
    {
        inorder(p->lch, i);
        cout<<"\t"<<p->data;
        i++;
        inorder(p->rch, i);
    }
}

void BiTree::inorderz()
{
    SqStack<Nodetype *>s;
    Nodetype *q;
    q = root;
    bool flag = true;
    cout<<"\n 中根遍历：\n";
    do
    {
        while(q!=nullptr)
        {
            s.Push(q);
            q = q->lch;
        }
        if(s.IsEmpty()) flag = false;
        else
        {
            q = s.Pop();
            cout<<q->data<<"\t";
            q = q->rch;
        }

    }while(flag);
}

void BiTree::preorder(Nodetype *p)
{
    if(p!=nullptr)
    {
        cout<<p->data<<"\t";
        preorder(p->lch);
        preorder(p->rch);
    }
}

void BiTree::preorderz()
{
    SqStack<Nodetype *>s;
    Nodetype *q;
    q = root;
    bool flag = true;
    do
    {
        while(q!=nullptr)
        {
            cout<<q->data<<"\t";
            s.Push(q);
            q = q->lch;
        }
        if(s.IsEmpty()) flag = false;
        else
        {
            q = s.Pop();
            q = q->rch;
        }
    }while(flag);
}

void BiTree::postorder(Nodetype *p)
{
    if(p!=nullptr)
    {
        postorder(p->lch);
        postorder(p->rch);
        cout<<p->data<<"\t";
    }
}

void BiTree::postorderz()
{
    SqStack<Nodetype *>s;
    SqStack<int> s2;
//    int i = 0;
    Nodetype *q;
    q = root;
    bool flag = true;
    cout<<"\n 后根非递归遍历\n";
    do
    {
        while(q!=nullptr)
        {
//            cout<<q->data<<"\t";
            s.Push(q);
            //i = 1;
            s2.Push(1);
            q = q->lch;
        }
        if(s.IsEmpty()) flag = false;
        else
        {
            if(s2.GetTop()==1)
            //if(i == 1)
            {
                s2.Pop();
                s2.Push(2);
                //i = 2;
                q = s.GetTop();
                q = q->rch;
            }
            else
            {
                s2.Pop();
                q = s.Pop();
                cout<<q->data<<"\t";
                q = nullptr;
            }
        }
    }while(flag);
}

int BiTree::predepth(Nodetype *t)
{
    if(t!=nullptr)
        return 1+max(predepth(t->lch), predepth(t->rch));
    else return 0;
}

int BiTree::max(int x, int y)
{
    return x>=y? x:y; 
}

int main(int argc, char *argv[])
{
    int k;
    BiTree root0;
    cout<<"\n\n 1.建立二叉树";
    cout<<"\n\n 2.中根递归遍历二叉树";
    cout<<"\n\n 3.中根非递归遍历二叉树";
    cout<<"\n\n 4.先根非递归遍历二叉树";
    cout<<"\n\n 5.先根递归遍历二叉树";
    cout<<"\n\n 6.后根非递归遍历二叉树";
    cout<<"\n\n 7.后根递归遍历二叉树";
    cout<<"\n\n 8.求二叉树深度";
    cout<<"\n\n 9.结束程序";
    do
    {
        cout<<"\n-------------------------------------";
        cout<<"\n  请输入您的选择(0,1,2,3,4,5,6,7,8,9):";
        cin>>k;
        switch(k)
        {
            case 1:
                cout<<"\n建立二叉树";
                root0.Creat();
                break;
            case 2:
                cout<<"\n中根遍历二叉树";
                root0.inorder();
                break;
            case 3:
                cout<<"\n中根非递归遍历二叉树";
                root0.inorderz();
                break;
            case 4:
                cout<<"\n先根非递归遍历二叉树";
                root0.preorderz();
                break;
            case 5:
                cout<<"\n先根递归遍历二叉树";
                root0.preorderz();
                break;
            case 6:
                cout<<"\n后根非递归遍历二叉树";
                root0.postorderz();
                break;
            case 7:
                cout<<"\n后根递归遍历二叉树";
                root0.postorder();
                break;
            case 8:
                cout<<"\n求二叉树深度";
                cout<<root0.predepth();
                break;
            default:
                break;
        }
    }while(k>0 && k<9);
    return 0;


}
