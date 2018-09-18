#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
string Mirror(string n)
{
    auto len = n.size();
    string res = n.substr(0,len/2);
    string str = n.substr(0,len/2);
    if(len%2==1)
    {
        //res = n.substr(0,1+len/2);
        reverse(str.begin(),str.end());
        res = res + n[len/2] + str;
    }
    else if(len%2==0)
    {
        res = res + str;
    }
    return res;
}
int main(int argc, char *argv[]) {
    string line = "abcd";
    string str = "cdfe";
//    while (getline(cin, line)) {
//        string n = stringToString(line);

//        string ret = Solution().nearestPalindromic(n);
    char str23 =(char)(int(str[0])+1);
//    string str233("");
//    str233.push_back(str23);
    str.replace(0,1,1,str23);
    cout<<(char)(int(str[0])+1)<<endl;
    cout<<str;
//    string out1 = line + str;
//    reverse(str.begin(),str.end());
//    string out2 = line.substr(0,3) + str;
//        cout << out1 << endl<<out2<<endl;
//    }
    return 0;
}
