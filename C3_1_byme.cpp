//C++ file
/*=============================================
*
*      Filename: 20180822/C3_1_byme.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 火车过站问题
*        Create: 2018-08-28 14:25:15
# Last Modified: 2018-08-28 14:25:56
=============================================*/

#include <vector>
#include <stack>

using namespace std;

bool Match(int strold[], int strnew[], int k, int N)
{
    bool ret;
    stack<int> sta;
    int index_in = 0;
    int index_out = 0;
    while(index_out < N)
    {
        while(index_in <N)
        {
            if(sta.empty())
            {
                sta.push(strold[index_in]);
                index_in++;
            }
            else if(sta.top()!=strnew[index_out])
            {
                sta.push(strold[index_in]);
                index_in++;
            }else
                break;
        }
        if(sta.top()==strnew[index_out])
        {
            sta.pop();
            index_out++;
        }
        else
            break;
    }
    if(sta.empty())
        ret = true;
    else
        ret =false;
    return ret;
}

void perm(int strold[], int strnew[], int k, int N)
{
    if(k == N)
    {
        if(Match(strold, strnew, k, N) == true)
        {
            cout<<"\n队列输出为：\n";
            for(int i=0;i<N; i++)
            {
                cout<<strnew[i]<<"\t";
            }
            cout<<endl;
        }

    }
    else
    {
        for(int i=k; i<N; i++)
        {
            swap(strnew[i], strnew[k]);
            perm(strold, strnew, k+1, N);
            swap(strnew[i], strnew[k]);
        }
    }
}

int main()
{
    int N = 0,i = 0;
    /* 存放火车的编号 */
    int data[10] = {0};
    int data_bk[10] = {0};
    cout<<"\n请输入列车总数：\n";
    cin >> N;
    cout<<"\n请输入列车编号：\n";
    for(i = 0; i < N; i++)
    {
        cin >> data[i];
        data_bk[i] = data[i];
    }
    perm(data_bk,data,0,N);


    return 0;
}

