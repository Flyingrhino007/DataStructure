//C++ file
/*=============================================
*
*      Filename: 20180825/C4_8.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 实现字符串中所有子串w用另一个字符串x来替换,w和x可以长度不同。
*        Create: 2018-08-28 14:32:21
# Last Modified: 2018-08-28 14:33:19
=============================================*/

#include<cstring>

using namespace std;

void Getnext(char s1[], int next[])
{
    int j=0,k=-1;
    next[0]=-1;
    int len = strlen(s1);
    while(j<len)
    {
        if(k==-1 || s1[j]==s1[k])
        {
            k++;
            j++;
            next[j]=k;
        }
        else
        {
            k = next[k];
        }
    }
}

void KMPFind(char s1[], char s2[], int result[])
{
    int next[10]={0},i,j,k=0;
    Getnext(s2, next);
    i=0;
    j=0;
    while(i<strlen(s1))
    {
        if(j== -1 || s1[i]== s2[j])
        {
            i++;
            j++;
        }
        else
            j =next[j];
        if(j==strlen(s2))
        {
            result[k]=i-j+1;
            k++;
            j = 0;
        }
    }
}


int main(int argc, char *argv[])
{
    char s1[]="abcdabcdabcdabcd";
    char s2[]="abcd";
    int n1[20] = {0}, n2[5]={0};
    Getnext(s1, n1);
    Getnext(s2, n2);
//    cout<<n1<<endl;
//    cout<<n2<<endl;
//    for(int i=0; i<20; i++)
//        cout<<n1[i]<<"\t";
    cout<<"\n";
    for(int i=0; i<5; i++)
        cout<<n2[i]<<"\t";
    cout<<"\n";
    int res[10]={0};
    KMPFind(s1,s2,res);
    int ilen = sizeof(res)/sizeof(int);
    for(int i=0; i<ilen; i++)
        cout<<res[i]<<"\t";
    return 0;
}
