//C++ file
/*=============================================
*
*      Filename: C5_6.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description:此程序用十字链表示稀疏矩阵，并实现稀疏矩阵的建立，输出，加法，乘法等。
*        Create: 2018-08-28 14:07:48
# Last Modified: 2018-08-28 14:33:47
=============================================*/

using namespace std;

typedef int Elemtype;

struct Node
{
    int row;
    int col;
    Node *down;
    Node *right;
    union
    {
        Node *next;
        Elemtype val;
    };
};

class Linkedmat
{
private:
    Node *hm;
public:
    Linkedmat();
    ~Linkedmat();
    void Creat();
    void Show();
    Linkedmat *Add(const Linkedmat &, const Linkedmat &);
    Linkedmat *Multi(const Linkedmat &, const Linkedmat &);
};

Linkedmat::Linkedmat()
{
    //hm = new Node;
    //hm->row = 0;
    //hm->col = 0;
    //hm->down = nullptr;
    //hm->right = nullptr;
    //hm->next = nullptr;
}

Linkedmat::~Linkedmat()
{
    Node *p = hm->next;
    while(p != hm)
    {
        Node *t = p->down;
        while(t != p)
        {
            Node *q = t->down;
            delete t;
            t = q;
        }
        t = p->next;
        delete p;
        p = t;
    }
//    delete p;
    delete hm;
    cout<<"\n析构函数";
}

void Linkedmat::Creat()
{
    int m,n,s,r,c,v;
    Node *p, *q, *h[10];
    cout<<"\n 请输入矩阵参数：";
    cout<<"\n 行数：";
    cin>>m;
    cout<<"\n 列数：";
    cin>>n;
    s = m>n? m:n;
    p = new Node;
    p->row = m;
    p->col = n;
    hm = p;
    h[0] = p;
    for(int i=1; i<=s; i++)
    {
        p = new Node;
        p->row = 0;
        p->col = 0;
        h[i] = p;
        p->right = p;
        p->down = p;
        h[i-1]->next = p;
    }
    h[s]->next = hm;
    cout<<"\n 最大行数："<<m<<"\n最大列数："<<n<<"\n元素数最多为："<<m*n<<"、\n请输入非零元素个数：";
    int t = 0;
    cin>>t;
    cout<<"\n输入三原数组(i,j,value)，并以空格分开，回车结束";
    for(int i=0; i<t; i++)
    {
        cout<<"\n第 "<<i+1<<"个：";
        cin>>r>>c>>v;
        p = new Node;
        p->row = r;
        p->col = c;
        p->val = v;
        q = h[r];
        while((q->right->col <c) && (q->right != h[r]))
            q = q->right;
        p->right = q->right;
        q->right = p;
        q = h[c];
        while((q->down->row <r)&&(q->down != h[c]))
            q = q->down;
        p->down = q->down;
        q->down = p;
    }
}

void Linkedmat::Show()
{
    Node *p, *q;
    int i,j;
    cout<<"\n此十字链表存储的矩阵为：\n ";
    for( i=0;i< hm->col; i++)
        cout<<i+1<<" ";
    cout<<endl;
    for(i=1, p=hm->next; p!=hm; i++)
    {
        cout<<i;
        q = p->right;
        for(j=1; q!=p; j++)
        {
            if(j == q->col)
            {
                cout<<q->val;
                q = q->right;
            }
            else
                cout<<" ";
            cout<<" ";
        }
        p = p->next;
        cout<<endl;
    }
}

Linkedmat *Linkedmat::Add(const Linkedmat &a, const Linkedmat &b)
{
    //cout<<"\n 矩阵a\n";
    //a.Show();
    //cout<<"\n 矩阵b\n";
    //b.Show();
    //准备矩阵Cc
    Linkedmat *CC;
    int m,n,s,r,c,v;
    Node *p, *h[10];
    m = b.hm->row;
    n = b.hm->col;
    s = m>n? m:n;
    p = new Node;
    p->row = m;
    p->col = n;
    CC->hm = p;
    h[0] = p;
    for(int i=1; i<=s; i++)
    {
        p = new Node;
        p->row = 0;
        p->col = 0;
        h[i] = p;
        p->right = p;
        p->down = p;
        h[i-1]->next = p;
    }
    h[s]->next = CC->hm;

    //开始加法操作
    Node *pa, *pb, *ppa, *ppb, *tmp;
    pa = a.hm->next;
    pb = b.hm->next;
    for(int i=0; i<m; i++)                  //按照矩阵a行数循环
    {
        
        ppa = pa->right;          //每一行开始元素  pa为h[i]
        ppb = pb->right;                  //tmp 将运算好元素连接入十字链表用
        while(ppa!=pa || ppb!= pb)
        {
            Node *q = new Node;
            if(((ppa->col < ppb->col)||ppb->col==0) && ppa->col!=0)     //按从左往右的顺序。某位置上，a有元素，b无
            {
                q->row = ppa->row;
                q->col = ppa->col;
                q->val = ppa->val;
                tmp = h[ppa->row];      //将计算好的新元素链接入CC表
                while((tmp->right !=  h[ppa->row]) && (tmp->col <ppa->col))
                    tmp = tmp->right;
                q->right = tmp->right;
                tmp->right = q;
                tmp = h[ppa->col];
                while((tmp->down != h[ppa->col]) && (tmp->row < ppa->row))
                    tmp = tmp->down;
                q->down = tmp->down;
                tmp->down = q;
                ppa = ppa->right;
            }else if(((ppa->col > ppb->col)||ppa->col==0) && ppb->col!=0)//b有,a无
            {
                q->row = ppb->row;
                q->col = ppb->col;
                q->val = ppb->val;
                tmp = h[ppb->row];      //将计算好的新元素链接入CC表
                while((tmp->right != h[ppb->row]) && (tmp->col <ppb->col))
                    tmp = tmp->right;
                q->right = tmp->right;
                tmp->right = q;
                tmp = h[ppb->col];
                while((tmp->down != h[ppb->col]) && (tmp->row < ppb->row))
                    tmp = tmp->down;
                q->down = tmp->down;
                tmp->down = q;
                ppb = ppb->right;
            }else if((ppa->val + ppb->val)==0)//同一个位置上a,b均有元素，但和为0
            {
                delete q;
                ppa = ppa->right;
                ppb = ppb->right;
            }
            else if((ppa->val + ppb->val)!=0)                           //同一个位置上a,b均有元素，和不为0
            {
                q->row = ppa->row;
                q->col = ppa->col;
                q->val = ppa->val+ppb->val;
                tmp = h[ppa->row];          //将计算好的新元素链接入CC表
                while((tmp->right !=  h[ppa->row]) && (tmp->col <ppa->col))
                    tmp = tmp->right;
                q->right = tmp->right;
                tmp->right = q;
                tmp = h[ppa->col];
                while((tmp->down != h[ppa->col]) && (tmp->row < ppa->row))
                    tmp = tmp->down;
                q->down = tmp->down;
                tmp->down = q;
                ppa = ppa->right;
                ppb = ppb->right;

            }
        }
        pa = pa->next;                      //转换到下一行
        pb = pb->next;

    }
//    cout<<"\nCC和矩阵为\n";
//    CC.Show();
    return CC;
}

Linkedmat *Linkedmat::Multi(const Linkedmat &a, const Linkedmat &b)
{
    Linkedmat *CC;
    int m,n,s,r,c,v;
    Node *p, *h[10];
    m = a.hm->row;                          //准备矩阵CC
    n = b.hm->col;
    s = m>n? m:n;
    p = new Node;
    p->row = m;
    p->col = n;
    CC->hm = p;
    h[0] = p;
    for(int i=1; i<=s; i++)
    {
        p = new Node;
        p->row = 0;
        p->col = 0;
        h[i] = p;
        p->right = p;
        p->down = p;
        h[i-1]->next = p;
    }
    h[s]->next = CC->hm;

    //开始乘法操作
    Node *pa, *pb, *ppa, *ppb, *tmp;
    pa = a.hm->next;
    for(int i=0; i< a.hm->row; i++)                         //
    {
        pb = b.hm->next;    
        for(int j=0; j< b.hm->col; j++)
        {
            ppa = pa->right;
            ppb = pb->down;
            Node *q = new Node;                             //预备存储点
            q->val = 0;
            q->row = ppa->row;
            q->col = ppb->col;
            while(ppa!=pa || ppb!=pb)                       //计算左行乘右列，与加法类似，索引号相同时A，B矩阵对应元素相乘，若为0删除节点
            {
                if(((ppa->col < ppb->row)||ppb->row==0) && ppa->col!=0)
                {
                    ppa = ppa->right;
                }else if(((ppa->col > ppb->row)||ppa->col==0) && ppb->row!=0)
                {
                    ppb = ppb->down;
                }else if((ppa->col ==ppb->row)&&(ppa->col!=0)&&(ppb->row!=0))
                {
                    q->val += ppa->val * ppb->val;
                    ppa = ppa->right;
                    ppb = ppb->down;
                }
            }
            if(q->val != 0)
            {
                tmp = h[pa->right->row];      //将计算好的新元素链接入CC表，使用[pa->right->row]保证行的位置，同理pb->down->col保证列的位置
                while((tmp->right !=  h[pa->right->row]) && (tmp->col <pb->down->col))
                    tmp = tmp->right;
                q->right = tmp->right;
                tmp->right = q;
                tmp = h[pb->down->col];
                while((tmp->down != h[pb->down->col]) && (tmp->row < pa->right->row))
                    tmp = tmp->down;
                q->down = tmp->down;
                tmp->down = q;
            }else if(q->val == 0)
                delete q;
            pb = pb->next;
        }
        pa = pa->next;
    }
//    CC->Show();
    return CC;
}


int main(int argc, char *argv[])
{
    Linkedmat aa,bb,*cc,*dd;
    aa.Creat();
    aa.Show();
    bb.Creat();
    bb.Show();
//    cc = aa.Add(aa, bb);
//    cc->Show();
    dd = aa.Multi(aa, bb);
    dd.Show();
    return 0;
}
