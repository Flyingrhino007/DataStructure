//C++ file
/*=============================================
*
*      Filename: 20180825/C4_5.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 测试字符串是否为回文
*        Create: 2018-08-28 14:31:00
# Last Modified: 2018-08-28 14:31:21
=============================================*/

#include<cstring>
using namespace std;

int main(int argc, char *argv[])
{
    char s1[] = "abcdedcba";
    char s2[] = "aabb";
    int p1 = strlen(s1);
    int p2 = strlen(s2);
    for(int i=0; i<(p1+1)/2; i++)
    {
        if(s1[i] != s1[p1-i-1])
        {
            cout<<"\n不是回文数"<<s1<<endl;
            break;
        }
    }
    for(int i=0; i<(p2+1)/2; i++)
    {
        if(s2[i] != s2[p2-i-1])
        {
            cout<<"\n不是回文数"<<s2<<endl;
            break;
        }
    }
    return 0;
}
