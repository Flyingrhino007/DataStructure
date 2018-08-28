#include<iostream>
#include<cstring>
#include<string.h>
#include<string>
using namespace std;

class StringCC
{
private:
    char *str;
    int size;
    void Getnext(StringCC t, int next[]);
public:
    StringCC();
    StringCC(char *chx);
    ~StringCC(){};
    void Creat();
    void Display();
    int Length(){return size;};
    StringCC SubString(int pos, int num);
    void Insert(StringCC s, int pos);
    void Delete(int pos, int num);
    int Find(StringCC s, int pos);
    int KMPFind(StringCC s, int pos);
};

StringCC::StringCC()
{
    str = new char;
    if(!str)
    {
        cout<<"\n\n分配不成功";
        return ;
    }
    size = 0;
    str[0] = '\0';
}

StringCC::StringCC(char *chx)
{
    size = strlen(chx);
    str = new char[size];
    strcpy(str, chx);
}

void StringCC::Creat()
{
    char p[]  = "";
    char *chone = p;
    cout<<"\n\n请输入String：";
    cin>>p;
    size = strlen(chone);
    str = new char[size];
    strcpy(str, chone);
    //str[size] = '\0';
    //delete chone;    //char到string 尾部加\0
}

void StringCC::Display()
{
    cout<<"\n\nString 是 "<<str;
}

StringCC StringCC::SubString(int pos, int num)
{
    StringCC tp;
    if(pos<1 || pos>size || num<=0)
    {
        cout<<"\n\n pos或num超出范围";
        return tp;
    }
    if(num > size - pos)
        num = size - pos;
    pos--;
    cout<<"\n\n子串为: ";
    for(int i = pos; i<num; i++)
    {
        cout<<str[i];
    }
    delete tp.str;
    str = new char[num+1];
    for(int i=0, j =pos; i<num; i++, j++)
        tp.str[i] = str[j];
    tp.str[num] = '\0';
    tp.size = num;
    return tp;
}

void StringCC::Insert(StringCC s, int pos)
{
//    char p[] ="";
    char *x ;
    pos--;
    if(pos<0 || pos>size-1)
        cout<<"\n\n pos超出范围";
    x= str;
    int sizeNew = s.size + size;
    delete str;
    str = new char[sizeNew];
    str = x;
    for(int i = size-1; i>=pos; i--)
    {
        str[i+s.size ] = str[i];
    }
    for(int j=0; j<s.size; j++)
    {
        str[pos + j] = s.str[j];
    }
    size = sizeNew;
    str[size] = '\0';
}

void StringCC::Delete(int pos, int num)
{

//    StringCC *tp ;
//    strcpy(tp, str);
    if(pos<1 || pos>size || num<=0)
    {
        cout<<"\n\n pos或num超出范围";
    }
    if(num > size - pos)
        size = pos;
    else
    {
        pos--;
        for(int i=pos; i<num; i++)
        {
            str[i] = str[i+num];
        }
        size = size - num;
    }
   str[size] = '\0';
}

int main(int argc, char *argv[])
{
    StringCC s,s0,s1,s2,s3;
    StringCC ssub;
    int pos,num,k;
    do
    {
        cout<<"\n    1.取子串";
        cout<<"\n    2.插入子串";
        cout<<"\n    3.删除子串";
        cout<<"\n    4.模式匹配";
        cout<<"\n    5.结束程序";
        cout<<"\n*************************************";
        cout<<"\n    请输入你的选择(1,2,3,4,5)";
        cin>>k;
        switch(k)
        {
            case 1:
                s0.Creat();
                s0.Display();
                cout<<"\n请输入截取的位置和长度";
                cin>>pos>>num;
                ssub = s0.SubString(pos, num);
                ssub.Display();
                break;
            case 2:
                cout<<"\n请输入主串:";
                s1.Creat();
                cout<<"\n请输入插入的子串:";
                s2.Creat();
                cout<<"\n请输入插入的位置：";
                cin>>pos;
                s1.Insert(s2, pos);
                cout<<"\n插入后：";
                s1.Display();
                break;
            case 3:
                cout<<"\n请输入主串:";
                s3.Creat();
                cout<<"\n请输入删除的位置和长度：";
                cin>>pos>>num;
                s3.Delete(pos, num);
                cout<<"\n删除后：";
                s3.Display();
                break;
            case 4:
                break;
            default:
                break;
        }
    }while(k>0 && k<5);
    cout<<"\n**********程序结束************";
    return 0;
}
