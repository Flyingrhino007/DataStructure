//C++ file
/*=============================================
*
*      Filename: 20180818/C2_3.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 实现顺序表逆置，在原数组上操作
*        Create: 2018-08-28 14:19:12
# Last Modified: 2018-08-28 14:19:46
=============================================*/

#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int x[5] = {1, 2, 3, 4, 5};
    int len = sizeof(x);
    for (int i = 0; i < len; i++)
    {
        cout << x[i] << endl;
    }
   for (int i = 0; i <= len / 2; i++)
    {
        int tmp = x[i];
        x[i] = x[len - i];
        x[len - i] = tmp;
    }
    for (int i = 0; i < len; i++)
    {
        cout << x[i] << endl;
    }
    return 0;
}
