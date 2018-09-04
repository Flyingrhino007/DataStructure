#include<SqQueue.h>
const int MaxVertices = 10;
const int MaxWeight = 32767;
class AdjMWGraph
{
private:
    int Vertices[MaxVertices];
    int Edge[MaxVertices][MaxVertices];
    int numE;
    int numV;
public:
    AdjMWGraph();
    void CreatG(int n, int e);
    void PrintOut();
//    void Depth();
//    void DepthFF();
    void Broad();
//    void BroadFF();
private:
//    void Depth(int v, int visited[]);
    void Broad(int v, int visited[]);
};

AdjMWGraph::AdjMWGraph()
{
    for(int i=0; i<MaxVertices; i++)
        Vertices[i]=0;
    for(int i=0; i<MaxVertices; i++)
        for(int j=0; j<MaxVertices; j++)
        {
            if(i==j) Edge[i][j] = 0;
            else
                Edge[i][j] = MaxWeight;
        }
    numE = 0;;
    numV = 0;
}

void AdjMWGraph::CreatG(int n, int e)
{
    int i,vi,vj,w;
    numE = e;
    numV = n;
    cout<<"\n输入顶点信息";
    for(int i=0; i<numV; i++)
    {
        cout<<"\n第"<<i+1<<"个点：";
        cin>>Vertices[i];
    }
    cout<<"\n输入边的信息";
    for(int i=0; i<numE; i++)
    {
        cout<<"\n输入第"<<i+1<<"条边的起点，终点，权重：";
        cin>>vi>>vj>>w;
        Edge[vi-1][vj-1] = w;
        Edge[vj-1][vi-1] = w;
    }
}

void AdjMWGraph::PrintOut()
{
    cout<<"\n输入顶点信息\n";
    for(int i=0; i<numV; i++)
        cout<<Vertices[i]<<"\t";
    cout<<"\n输出边的信息";
    for(int i=0; i<numV; i++)
    {
        cout<<"\n"<<i+1;
        for(int j=0; j<numV; j++)
        {
            if(Edge[i][j]!=MaxWeight && Edge[i][j]!=0)
                cout<<Edge[i][j]<<"\t";
            else
                cout<<"\t";
        }
    }
}

void AdjMWGraph::Broad(int v, int visited[])
{
    SqQueue<int>Q;
    cout<<"\n 顶点"<<Vertices[v-1]<<"\t";
    Q.EnQueue(v);
    visited[v-1]=1;
    while(!Q.IsEmpty())
    {
        v = Q.DeQueue();
        for(int col=0; col<numV; col++)
        {
            if(Edge[v-1][col]>0 && Edge[v-1][col]<MaxWeight && visited[col]==0)
            {
                cout<<"\n顶点"<<Vertices[col];
                visited[col]=1;
                Q.EnQueue(Vertices[col]);
            }
        }
    }
}

void AdjMWGraph::Broad()
{
    cout<<"\n广度优先遍历";
    int visited[numV];
    for(int i=0; i<numV; i++)
        visited[i] = 0;
    int v;
    cout<<"\n请输入起始顶点: ";
    cin>>v;
    Broad(v, visited);
}


int main(int argc, char *argv[])
{
    AdjMWGraph G;
    int n, e, k,v;
    cout<<"\n\n 1.建立图的矩阵表";
    cout<<"\n 2.广度优先遍历图";
    cout<<"\n 3.结束程序运行";
    cout<<"\n--------------------------------";
    cout<<"\n 请输入你的选择(1,2,3)";
    cin>>k;
    while(k>0 && k<3)
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
                G.Broad();
//                G.PrintOut();
                break;
            default:
                break;
        }
        cout<<"\n 请输入你的选择(1,2,3)";
        cin>>k;
    }    
    cout<<"\n 程序结束";
    return 0;
}
