#include<iostream>
using namespace std;
const int MAXSIZE = 100;
typedef int ElemType;
struct Data
{
    ElemType key;
//    int shu;
    int point;
};

//Data ar[MAXSIZE], br[MAXSIZE];
int yx(int m, int i);
template<class T>void bubblesort(T r[], int n);
template<class T>void quicksort(T a[], int l, int h);
template<class T>int hoarse(T a[], int l, int h);
template<class T>void stinsort(T a[], int n);
template<class T>void shellsort(T a[], int n);
template<class T>int radixsort(T r[], int n);
void generate(Data ary[],int count)
{
    long int a = 1001;
    int i;
    ary[0].key=0;
    ary[0].point=0;
    for(i = 1; i<=count; i++)
    {
        a = (a*125)%5757;
        ary[i].key = (int)a;
        ary[i].point = 0;
    }
}

void prdata(Data ary[], int count)
{
    int i;
    char ch;
    cout<<"\n 数据输出\n";
    for(i=1; i<=count; i++)
        cout<<"\t"<<ary[i].key;
    cout<<"\n\n 结束显示";
}

template<class T>void bubblesort(T r[], int n)
{
    int i=1,tag,m;
    T x;
    do
    {
        tag = 0;
        x = r[i];
        for(int j=n;j>i;j--)
        {
            if(r[j].key<r[j-1].key)
            {
                x = r[j];
                r[j] = r[j-1];
                r[j-1] = x;
                tag = 1;
            }
        }
        i++;
    }while(tag==1 && i<n);
}

template<class T>int hoarse(T a[], int l, int h)
{
    int i,j;
    T x;
    i = l;
    j = h;
    x.key = a[i].key;
    do
    {
        while(i<j && a[j].key>=x.key)
            j--;
        if(i<j)
        {
            a[i].key = a[j].key;
            i++;
        }
        while(i<j && a[i].key<=x.key)
            i++;
        if(i<j)
        {
            a[j].key = a[i].key;
            j--;
        }
    }while(i<j);
    a[i].key = x.key;
    return i;
}

template<class T>void quicksort(T a[], int l,int h)
{
    int i;
    if(l<h)
    {
        i = hoarse(a, l, h);
        quicksort(a,l,i-1);
        quicksort(a,i+1,h);
    }
}

template<class T>void stinsort(T a[], int n)
{
    T x;
    for(int j=2;j<=n;j++)
    {
        bool tag = false;
        x.key = a[j].key;
        int i=1;
        while(tag == false &&i<j)
        {
            if(x.key>a[i].key)
                i++;
            else
                tag = true;
        }
        if(i<j && tag ==true)
        {
            for(int k=j-1;k>=i;k--)
                a[k+1]=a[k];
        }
        a[i].key=x.key;
    }
}

template<class T>void shellsort(T a[], int n)
{
    T x;
    int d[] = {8,4,2,1,0};
    for(int i=0;d[i]!=0;i++)
    {
        int dd = d[i];
        for(int j=0;j<=dd;j++)
        {
           /* for(int p=j;p<=n;p+=dd)*/
            //{
                //int pp = j;
                //bool tag = false;
                //x = a[p];
                //while(pp<p && tag==false)
                //{
                    //if(a[pp].key<x.key)
                        //pp+=dd;
                    //else
                        //tag = true;
                //}
                //if(pp<p)
                //{
                    //int k = p;
                    //for(;k>pp;k-=dd)
                        //a[k].key = a[k-dd].key;
                    //a[k].key = x.key;
                //}
            /*}*/
            for(int p=n-j;p>dd;p-=dd)
            {
                x = a[p];
                int pp = p-dd;
                while(pp>=0 && a[pp].key>x.key)
                {
                    a[pp+dd].key = a[pp].key;
                    pp-=dd;
                }
                a[pp+dd].key = x.key;
            }

        }
/*        for(int j=n;j>n-dd;j--)*/
        //{
            //x = a[j];
            //int p = j-dd;
            //bool tag = false;
            //while(p>=1 && tag==false)
            //{
                //if(a[p].key>x.key)
                //{
                    //a[p+dd].key = a[p].key;
                    //p-=dd;
                //}
                //else
                    //tag = true;
                //if(p<j-dd)
                    //a[p+dd].key = x.key;
            //}
        /*}*/
    }
}

int yx(int m, int i)
{
    int x;
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

template<class T>int radixsort(T r[], int n)
{
    int f[10],e[10];
    for(int i=1;i<n;i++)
        r[i].point = i+1;
    r[n].point = 0;
    int p = 1;
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<10;j++)
        {
            f[j]=0;
            e[j]=0;
        }
        while(p!=0)
        {
            int k=yx(r[p].key,i);
            if(f[k]==0)
            {
                f[k]=p;
                e[k]=p;
            }
            else
            {
                int l = e[k];
                r[l].point = p;
                e[k] = p;
            }
            p = r[p].point;
        }
        int j = 0;
        while(f[j]==0)
            j++;
        p = f[j];
        int t = e[j];
        while(j<10)
        {
            j++;
            while(j<10 && f[j]==0)
                j++;
            if(j<10 && f[j]!=0)
            {
                r[t].point = f[j];
                t = e[j];
            }
            r[t].point = 0;
        }
    }
    return p;
}

int main(int argc, char *argv[])
{
    int k,n,j,m;
    char ch;
    Data ar[MAXSIZE],br[MAXSIZE];
    cout<<"\n\n 1.产生一批随机数准备排序";
    cout<<"\n 2.一般情况的冒泡排序";
    cout<<"\n 3.有序情况的冒泡排序";
    cout<<"\n 4.一般情况选择排序";
    cout<<"\n 5.有序情况的快速排序";
    cout<<"\n 6.插入排序";
    cout<<"\n 7.希尔排序";
    cout<<"\n 8.基数排序";
    cout<<"\n 9.结束程序";
    cout<<"\n---------------------------------";
    cout<<"\n 请输入你的选择:";
    cin>>k;
    while(k>0&&k<9)
    {
        switch(k)
        {
            case 1:
                cout<<"\n数据数目:";
                cin>>n;
                generate(ar, n);
                for(j=0; j<=n;j++)
                    br[j]=ar[j];
                prdata(ar,n);
                break;
            case 2:
                for(j=0;j<=n;j++)
                    ar[j] = br[j];
                bubblesort(ar,n);
                prdata(ar,n);
                break;
            case 3:
                bubblesort(ar,n);
                prdata(ar,n);
                break;
            case 4:
                for(j=0;j<=n;j++)
                    ar[j]=br[j];
                quicksort(ar,1,n);
                prdata(ar,n);
                break;
            case 5:
                quicksort(ar,1,n);
                prdata(ar,n);
                break;
            case 6:
                for(j=0;j<=n;j++)
                    ar[j]=br[j];
                stinsort(ar,n);
                prdata(ar,n);
                break;
            case 7:
                for(j=0;j<=n;j++)
                    ar[j]=br[j];
                shellsort(ar,n);
                prdata(ar,n);
                break;
            case 8:
                for(j=0;j<=n;j++)
                    ar[j]=br[j];
                m = radixsort(ar,n);
                cout<<"\n";
                while(m!=0)
                {
                    cout<<"\t"<<ar[m].key;
                    m = ar[m].point;
                }
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
