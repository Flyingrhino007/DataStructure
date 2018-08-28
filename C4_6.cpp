//C++ file
/*=============================================
*
*      Filename: 20180825/C4_6.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: 统计字符串中各字符出现的频度
*        Create: 2018-08-28 14:31:32
# Last Modified: 2018-08-28 14:31:55
=============================================*/

#include<vector>
#include<cstring>

using namespace std;

int main(int argc, char *argv[])
{
    vector<char> s1;
    int ss1[20];
    char test[] = "aaaabbcccdddddd";
    int len = strlen(test);
    s1.push_back(test[0]);
    ss1[0] = 1;
    for(int i=1, k=1; i<len; i++)
    {
        bool tmp = false;
        for(int j=0;j<s1.size(); j++)
        {
            if(test[i] == s1[j])
            {
                ss1[j]++;
                tmp = true;
            }
        }
        if(tmp == false)
        {
            s1.push_back(test[i]);
            ss1[k] = 1;
            k++;
        }
    }
    int slen = s1.size();
    for(int i=0; i<slen; i++)
    {
        cout<<s1[i]<<"\t"<<ss1[i]<<endl;
    }
    return 0;
}

