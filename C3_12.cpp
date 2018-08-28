//C++ file
/*=============================================
*
*      Filename: 20180824/C3_12.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 杨辉三角打印，不够完善！！！
*        Create: 2018-08-28 14:26:15
# Last Modified: 2018-08-28 14:26:35
=============================================*/

using namespace std;

int main(int argc, char *argv[])
{
    int i,k,maximum;
    int a[50];
    cout<<"\n\n    请输入行数i：";
    cin>>maximum;
    a[0] = 1;
    a[1] = 1;
    i = 2;
    while(i<maximum)
    {
        int b = a[0];
        cout<<"\n"<<a[0]<<" ";
        for(k = 1; k<i; k++)
        {
            int tmp = b;
            b = a[k];
            a[k] = tmp + a[k];
            cout<<a[k]<<" ";
        }
        a[i] = 1;
        cout<<a[i]<<endl;
        i++;
    }
    return 0;
}
