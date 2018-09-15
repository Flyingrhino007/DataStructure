#include<iostream>
using namespace std;

const int MAXSIZE = 100;
typedef int KeyType;
struct datanode
{
    KeyType key;
//    char ch;
};

class Sqtable
{
private:
    datanode r[MAXSIZE];
    int n;
public:
    Sqtable(int nn);
    void Creat();
    void Output();
    void Sq_Search(KeyType K);
    void Binary_Search(KeyType K);
    void D_Search(int m, int k,KeyType K);
};

Sqtable::Sqtable(int nn)
{
    n = nn;
    for(int i=0; i<n; i++)
        r[i].key = 0;
}

void Sqtable::Creat()
{
    KeyType kk;
    cout<<"\n 输入第1个参数，以-1结束";
    cin>>kk;
    int i=0;
    while(kk!=-1 && i<n)
    {
        r[i].key = kk;
        i++;
        cout<<"\n 输入第"<<i+1<<"个参数，以-1结束";
        cin>>kk;
    }
}

void Sqtable::Output()
{
    int i=0;
    cout<<"\n";
    while(r[i].key!=0)
    {
        cout<<r[i].key<<"\t";
        i++;
    }
}

void Sqtable::Sq_Search(KeyType K)
{
    int i=0;
    while(r[i].key != K)
        i++;
    if(i<n)
    {
        cout<<"\n查找成功，在位置"<<i+1;
    }
    else
        cout<<"\n 查找失败";
}

void Sqtable::Binary_Search(KeyType K)
{
    int m,low,high,find;
    low = 0;
    high = n-1;
    find = 0;
    do
    {
        m = (low+high)/2;
        if(K==r[m].key)
        {
            cout<<"\n查找成功,该数据在位置："<<m+1;
            find = 1;
        }
        else if(K<r[m].key)
            high = m-1;
        else
            low = m+1;
    }while(low<=high && find ==0);
    if(find == 0)
        cout<<"\n 查找失败";
}
void Sqtable::D_Search(int low,int high, KeyType K)
{
    int m = (low+high)/2;
    if(r[m].key==K)
        cout<<"\n查找成功，位置在:"<<m+1;
    else if(low==high && K!=r[m].key)
        cout<<"\n查找失败";
    else if(K<r[m].key)
        D_Search(low, m-1, K);
    else
        D_Search(m+1,high,K);
}

int main(int argc, char *argv[])
{
    int m,K,nn;
    cout<<"\n输入顺序表长度";
    cin>>nn;
    Sqtable ss(nn);
    cout<<"\n    1.建立顺序表";
    cout<<"\n    2.顺序查找";
    cout<<"\n    3.折半查找";
    cout<<"\n    4.递归折半查找";
    cout<<"\n    5.程序结束";
    cout<<"\n请输入你的选择(1,2,3,4,5)";
    cin>>m;
    while(m>0 && m<5)
    {
        switch(m)
        {
            case 1:
                ss.Creat();
                ss.Output();
                break;
            case 2:
                cout<<"\n请输入要查找的元素";
                cin>>K;
                ss.Sq_Search(K);
                break;
            case 3:
                cout<<"\n请输入要查找的元素";
                cin>>K;
                ss.Binary_Search(K);
                break;
            case 4:
                cout<<"\n请输入要查找的元素";
                cin>>K;
                ss.D_Search(0,nn-1,K);
                break;
            default:
                break;
        }
        cout<<"\n请输入你的选择(1,2,3,4,5)";
        cin>>m;
    }
    cout<<"\n程序结束";
    return 0;
}
