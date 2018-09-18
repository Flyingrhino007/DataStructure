class Solution {
public:
    string Mirror(string n)
    {
        auto len = n.size();
        string res = n.substr(0,len/2);
        string str = n.substr(0,len/2);
        if(len%2==1)
        {
            reverse(str.begin(),str.end());
            res = res + n[len/2] + str;
        }
        else if(len%2==0)
        {
            reverse(str.begin(),str.end());
            res = res + str;
        }
        cout<<res<<endl;
        return res;
    }
    string nearestPalindromic(string n) {
        if(n=="1")
            return "0";

        auto len = n.size();
        long long old = stoll(n);
//------------------------------------------第1种情况，直接逆置前n/2个字符。
        string str1 = Mirror(n);
        long long diff1 = LONG_LONG_MAX;
        diff1 = llabs(stoll(str1) - old);
        if(diff1 == 0)
            diff1 = LONG_LONG_MAX;
//        cout<<111<<endl;
//------------------------------------------第2种情况，n/2的位置是0，先退9再逆置。
        string str2(n);
        int i = (str2.size()-1)/2;
        long long diff2 = LONG_LONG_MAX;
        while(i>=0 && str2[i] == '0')
        {
            str2.replace(i,1,"9");
            i--;
        }
        if(i == 0 && str2[i]=='1')
        {
            str2.erase(0,1);
            auto mid = (str2.size()-1)/2;
            str2.replace(mid,1,"9");
        }
        else
            str2.replace(i,1,1,(char)((str2[i])-1));
//        cout<<str2;
        string str22(Mirror(str2));
        diff2 = llabs(stoll(str22) - old);
//        cout<<222<<endl;
//------------------------------------------第3种情况，n/2位置是9，先进1再逆置
        string str3(n);
        i = (str3.size()-1)/2;
        long long diff3 = LONG_LONG_MAX;
        while(i>=0 && str3[i] == '9')
        {
            str3.replace(i,1,"0");
            i--;
        }
        if(i<0)
        {
            str3.insert(0,"1");
        }else{
            str3.replace(i,1,1,(char)(str3[i]+1));
        }
        string str33(Mirror(str3));
        diff3 = llabs(stoll(str33)- old);
//        cout<<333<<endl;
//----------------------------------------------比较哪种最近并返回
    if(diff2<=diff1 && diff2<=diff3)
        return str22;
    else if(diff1<=diff2 && diff1<=diff3)
        return str1;
    else
        return str33;
    }
};
