//C++ file
/*=============================================
*
*      Filename: 20180824/C3_5.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 十进制转八进制
*        Create: 2018-08-28 14:29:10
# Last Modified: 2018-08-28 14:29:21
=============================================*/


using namespace std;

void trans10_8(int x)
{
    int a = x/8;
    int b = x%8;
    if(a < 1)
        cout<<x;
    else //if(a >= 1)
    {
        cout<<b;
        trans10_8(a);
    }
}

int main(int argc, char *arhv[])
{
    int a,b,p,i=0,res[100];
    cout<<"\n\n 请输入数字：";
    cin>>b;
    cout<<"\n\n 请输入要转换的进制：";
    cin>>p;
    while(b != 0)
    {
        a = b%p;
        b = b/p;
        res[i] = a;
        i++;
    }
    cout<<"\n\n十进制到"<<p<<"进制"<<"转换结果是：\n";
    for(int m=i-1; m>=0; m--)
        cout<<res[m];
    return 0;
}
