#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int ElemType;
const int MAXSIZE = 100;
class Sqlist
{
private:
        ElemType elem[MAXSIZE];
        int length;
public:
        Sqlist(void);
        ~Sqlist(){};
        void Creat();
        void Insert(int i, ElemType e);
        ElemType Delet(int i);
        void PrintOut();
        void Josephu(int i, int m);
        int Num(int i, int m);
};
//-------------------Func of Sqlist

Sqlist::Sqlist(){length = 0;}

void Sqlist::Creat(){
    cout<<"\n Input length= ";
    cin>>length;
    cout<<"\n Input Data:\n";
    for(int k=0; k<length; k++)
    {
        cin>>elem[k];
    }
}

void Sqlist::PrintOut()
{
    cout<<"\n length="<<length;
    cout<<"\n PrintOut Data:\n";
    for(int i=0; i<length; i++)
    {
        cout<<"\t"<<elem[i];
    }
    cout<<endl;
}

void Sqlist::Insert(int i, ElemType e){
    int j;
    i--;
    if(i<0 || i>length) cout<<"i Error!"<<endl;
    else 
    {
        for(int j=length; j>i; j--)
            elem[j] = elem [j-1];
        elem[i] = e;
        length++;
    }
}

ElemType Sqlist::Delet(int i)
{
    ElemType x;
    int j; 
    i--; 
    if(i<0 || i>length-1) 
    { 
        cout<<"\n\n     i超出范围\n"; 
        x=-1; 
    } 
    else 
    { 
        x = elem[i]; 
        for(j=i; j<length-1; j++) 
            elem[j] = elem[j+1]; 
        length--; 
    } 
    return x; 
} 

int Sqlist::Num(int i, int m)
{
    int j = 0;
//    if(elem[i] == 0)
//        j=0;
//    if(elem[i] != 0)
//        j=1;
    while(1)
    {
        if(elem[i] != 0)
        {
            j++;
            if(j == 3)
                return i;
        }
        i++;
        if(i>length-1)
            i = 0;
//        cout<<"\n"<<i<<"\t"<<j;
    }
    //cout<<"\n\n"<<i;
//    return i;
}

void Sqlist::Josephu(int i, int m)
{
    i--;
    for(int j=0; j<length; j++)
    {
        i = Num(i, m);
        elem[i] = 0;
//        PrintOut();
        cout<<"\n第 "<<j+1<<"个出列的是 "<<i+1;
    }

}

int main(int argc, char const *argv[])
{
    int i,k,m;
    ElemType e,x;
    Sqlist as;
    cout<<"\n  -----------顺序表存储演示\n";
    do{
        cout<<"\n\n    1.建立线性表";
        cout<<"\n\n    2.插入一个数据元素";
        cout<<"\n\n    3.删除一个元素，返回该值";
        cout<<"\n\n    4.Josephu问题";
        cout<<"\n\n    5.程序结束";
        cout<<"\n**********************************";
        cout<<"\n      请输入选择(1,2,3,4,5)";
        cin>>k;
        switch(k)
        {
            case 1:
                as.Creat();
                as.PrintOut();
                break;
            case 2:
                cout<<"\n\n请输入插入的位置，数据";
                cin>>i>>e;
                as.Insert(i,e);
                as.PrintOut();
                break;
            case 3:
                cout<<"\n\n请输入删除的位置";
                cin>>i;
                x = as.Delet(i);
                cout<<"\n  元素数值为  "<<x;
                as.PrintOut();
                break;
            case 4:
                cout<<"\n\n请输入Josephu开始的位置i";
                cin>>i;
                cout<<"\n\n请输入循环次数m";
                cin>>m;
                as.Josephu(i, m);
                break;
            default:
                break;
        }
    }while(k>=1 && k<5);
    cout<<"\n           再见";
    cout<<"\n           程序结束";
    return 0;
}
