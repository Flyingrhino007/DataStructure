//C++ file
/*=============================================
*
*      Filename: 20180825/C4_3.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 字符串连接
*        Create: 2018-08-28 14:29:47
# Last Modified: 2018-08-28 14:29:59
=============================================*/

#include<cstring>

using namespace std;

int main(int argc, char *argv[])
{
    char s1[] = "aaa";
    char s2[] = "bbb";
    char *p1 = s1, *p2 =s2;
    int size = strlen(s1)+strlen(s2);
    char s3[size];
    cout<<s1<<endl<<s2<<endl<<size<<endl;
    for(int i=0,j=0,k=0; i<size; i++)
    {
        if(i<strlen(s1))
        {
            s3[i]=s1[j];
            j++;
        }
        else
        {
            s3[i] = s2[k];
            k++;
        }
    }
    cout<<s3;


    return 0;
}
