//C++ file
/*=============================================
*
*      Filename: 20180825/C4_4.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 置换字符串第pos位置开始的num个元素
*        Create: 2018-08-28 14:30:20
# Last Modified: 2018-08-28 14:30:45
=============================================*/

#include<cstring>
#include<string.h>

using namespace std;

int main(int argc, char *argv[])
{
    char s1[] = "abcdefg";
    char s2[] = "mmm";
    int i,pos,num;
//   cout<<"\n请输入子串X：";
//    cin>>s2;
    cout<<"\n请输入插入的位置pos和字符数num：";
    cin>>pos>>num;
    int sssss = strlen(s1);
    if(pos<1 || pos>sssss)
    {
        cout<<"\npos输入错误";
        return 0;
    }
    int slen = strlen(s2);
    i = pos-1;
    int k=0,s=0;
    while(k<num && s<slen && i<sssss)
    {
        s1[i] = s2[s];
        i++;
        s++;
        k++;
    }
    cout<<"\n 结果是";
    cout<<s1;
    
    
    return 0;
}
