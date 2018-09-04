//#include<iostream>
#include<SqQueue.h>
#include<climits>
//using namespace std;
const int MaxVectices = 100;
typedef int VerT;
typedef int DisT;
//-------------------声明定义结构体和类
struct Edge
{
    int dest;
    DisT weight;
    Edge *next;
};
struct item
{
    VerT data;
    Edge *adj;
};
struct MinSpanTree
{
    int begin, end;
    float length;
};
class AdjTWGraph
{
private:
    item Vertices[MaxVectices];
    int numV;
    int numE;
public:
    AdjTWGraph();
    ~AdjTWGraph();
    void CreatG(int n, int e);
    void PrintOut();
    void DepthFirst();
    void BroadFirst();
    void Prim(int v);
private:
    void DepthFirst(int v, int visited[]);
    void BroadFirst(int v, int visited[]);
};

//-------------------声明函数

//-------------------定义函数
AdjTWGraph::AdjTWGraph()
{
    for(int i=0; i<MaxVectices; i++)
    {
        Vertices[i].data = 0;
        Vertices[i].adj = nullptr;
    }
    numE = 0;
    numV = 0;
}

AdjTWGraph::~AdjTWGraph()
{
    for(int i=0; i<numV; i++)
    {
        Edge *p = Vertices[i].adj, *q;
        while(p!=nullptr)
        {
            q = p->next;
            delete p;
            p = q;
        }
        Vertices[i].adj = nullptr;
    }
    cout<<"\n调用析构函数";
}

void AdjTWGraph::CreatG(int n, int e)
{
    int vi,vj;
    DisT w;
    numE = e;                                       //e为边的数目，n为顶点的数目
    numV = n;
    cout<<"\n输入顶点的信息";
    for(int i=0; i<numV; i++)                       //顶点信息的输入
    {
        cout<<"\n"<<i+1<<":";
        cin>>Vertices[i].data;
    }
    for(int i=0; i<numE; i++)
    {
        cout<<"\n 请输入边的信息：顶点号vi 顶点号vj 边的权重w\n";
        cin>>vi>>vj>>w;
        if(vi<1||vj<1||vi>numV||vj>numV)
            cout<<"\n顶点号越界";
        //------------------------------第i条链表插入vi--vj
        Edge *q = new Edge;
        q->dest = vj;
        q->weight = w;
        q->next = nullptr;
        if(Vertices[vi-1].adj == nullptr)                                //插入第一条边
            Vertices[vi-1].adj = q;
        else
        {
            Edge *curr = Vertices[vi-1].adj, *pre = nullptr;
            while(curr != nullptr && (curr->dest < q->dest))              //向右搜索直到标记点到q后侧
            {
                pre = curr;
                curr = curr->next;
            }
            if(pre==nullptr)                                            //在已有链表的第一个边节点前插入
            {
                q->next = Vertices[vi-1].adj;
                Vertices[vi-1].adj = q;
            }
            else
            {
                q->next = pre->next;
                pre->next = q;
            }
        }
        //------------------------------第j条链表插入vj--vi
        Edge *p = new Edge;
        p->dest = vi;
        p->weight = w;
        p->next = nullptr;
        if(Vertices[vj-1].adj==nullptr)
            Vertices[vj-1].adj = p;
        else
        {
            Edge *curr = Vertices[vj-1].adj;
            Edge *pre = nullptr;
            while(curr!=nullptr && curr->dest<p->dest)
            {
                pre = curr;
                curr = curr->next;
            }
            if(pre==nullptr)
            {
                p->next = Vertices[vj-1].adj;
                Vertices[vj-1].adj = p;
            }
            else
            {
                p->next = pre->next;
                pre->next = p;
            }
        }
    }
}

void AdjTWGraph::PrintOut()
{
    Edge *curr, *pre;
    cout<<"\n 输出顶点信息编号，邻接点的编号和边的权重:";
    for(int i=0; i<numV; i++)
    {
        curr = Vertices[i].adj;
        cout<<"\n顶点："<<Vertices[i].data;
        while(curr!=nullptr)
        {
            cout<<"\t邻接点 "<<Vertices[curr->dest-1].data<<"\t权重 "<<curr->weight;
            pre = curr;
            curr = curr->next;
        }
        cout<<"\n";
    }
}

void AdjTWGraph::DepthFirst(int v, int visited[])
{
    v--;
    int vj;
    Edge *p;
    cout<<Vertices[v].data<<"\t";
    visited[v] = 1;
    p = Vertices[v].adj;
    while(p!=nullptr)
    {
        vj = p->dest;
        if(visited[vj-1]==0)
            DepthFirst(vj, visited);
        p = p->next;
    }
}

void AdjTWGraph::DepthFirst()
{
    int v0;
    int visited[MaxVectices];
    for(int i=0; i<MaxVectices; i++)
        visited[i] = 0;
    cout<<"\n请输入深度遍历开始顶点";
    cin>>v0;
    cout<<"\n深度优先遍历";
    DepthFirst(v0, visited);
    cout<<"\n遍历结束";
}

void AdjTWGraph::BroadFirst(int v, int visited[])
{
    v--;
    int vj;
    Edge *p;
    SqQueue<int>Q;
    cout<<Vertices[v].data<<"\t";
    visited[v] = 1;
    Q.EnQueue(v);
    while(!Q.IsEmpty())
    {
        v = Q.DeQueue();
        p = Vertices[v].adj;
        while(p!=nullptr)
        {
            vj = p->dest;
            if(visited[vj-1]==0)
            {
                cout<<Vertices[vj-1].data<<"\t";
                visited[vj-1] = 1;
                Q.EnQueue(vj-1);
            }
            p = p->next;
        }
    }
    cout<<"\n end";
}

void AdjTWGraph::BroadFirst()
{
    int v0, visited[MaxVectices];
    for(int i=0; i<MaxVectices; i++)
        visited[i] = 0;
    cout<<"\n输入广度优先遍历起始顶点";
    cin>>v0;
    BroadFirst(v0, visited);
    cout<<"\n广度优先遍历结束";
}

//-----------------------------定义程序的函数，实现最小生成树算法
void AdjTWGraph::Prim(int v)                             //从顶点v开始的prim算法
{
    int n = numV;
    MinSpanTree e, mintree[20];
    Edge *p = Vertices[v-1].adj;
    for(int i=0; i<v-1; i++)                                //n个顶点，从v出发最多n-1条边
    {
        mintree[i].begin = v;
        mintree[i].end = Vertices[i].data;
        if(p!=nullptr && (mintree[i].end == p->dest))
        {
            mintree[i].length = p->weight;
            p = p->next;
        }
        else 
            mintree[i].length = INT_MAX;
    }
    for(int i=v-1; i<n-1; i++)                                //n个顶点，从v出发最多n-1条边
    {
        mintree[i].begin = v;
        mintree[i].end = Vertices[i+1].data;
        if(p!=nullptr && (mintree[i].end == p->dest))
        {
            mintree[i].length = p->weight;
            p = p->next;
        }
        else 
            mintree[i].length = INT_MAX;
    }

    for(int j=0; j<n-1; j++)
    {
        int min = INT_MAX;
        int jj;
        for(int m=j; m<n-1; m++)
        {
            if(mintree[m].length<min)
            {
                min = mintree[m].length;
                jj = m;
            }
        }
        e = mintree[j];
        mintree[j] = mintree[jj];
        mintree[jj] = e;
        int vv = mintree[j].end;                         //最小权值对应的顶点下标
        p = Vertices[vv-1].adj;
        while(p!=nullptr)
        {
            int k =j+1;
            for(;k<n-1;k++)
            {
                if(mintree[k].end== p->dest)
                    break;
            }
            if(p->weight < mintree[k].length && k<n-1)
            {
                mintree[k].length = p->weight;
                mintree[k].begin = vv;
            }
            p = p->next;
        }
    }
    cout<<"\nPrim算法，邻接链表存储下\n";
    for(int j=0; j<n-1; j++)
    {
        cout<<"\n第"<<j+1<<"条边起点 "<<mintree[j].begin<<" 终点 "<<mintree[j].end<<" 权重 "<<mintree[j].length;
    }
}

int main(int argc, char *argv[])
{
    AdjTWGraph G;
    int n, e, k,v;
    char ch;
    cout<<"\n\n 1.建立图的邻接链表";
    cout<<"\n 2.深度优先遍历图";
    cout<<"\n 3.广度优先遍历图";
    cout<<"\n 4.Prim算法，邻接链表存储实现最小生成树";
    cout<<"\n 5.结束程序运行";
    cout<<"\n--------------------------------";
    cout<<"\n 请输入你的选择(1,2,3,4)";
    cin>>k;
    while(k>0 && k<5)
    {
        switch(k)
        {
            case 1:
                cout<<"\n输入图的总顶点数和总边数(n,e=?)";
                cin>>n>>e;
                G.CreatG(n, e);
                G.PrintOut();
                break;
            case 2:
                G.DepthFirst();
//                G.PrintOut();
                break;
            case 3:
                G.BroadFirst();
//                G.PrintOut();
                break;
            case 4:
                cout<<"\n输入起始顶点v";
                cin>>v;
                G.Prim(v);
                break;
            default:
                break;
        }
        cout<<"\n 请输入你的选择(1,2,3,4)";
        cin>>k;
    }    
    cout<<"\n 程序结束";
    return 0;
}
