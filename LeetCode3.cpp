class Solution {
public:
    int IsA(string a, char c)
    {
        for(int j=0; j<a.size(); j++)
        {
            if(c==a[j])
                return j;
        }
        return -1;
    }
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        int index = 0, len = 1;
        int Tindex = 0, Tlen = 1;
        string a("");
        a.push_back(s[0]);
        for(int i=1; i<s.size(); i++)
        {
            int tmp = IsA(a, s[i]);
            if(tmp == -1)                  //与子串中元素不重复
            {
                a.push_back(s[i]);
                len ++;
                if(len >= Tlen)
                {
                    Tlen = len;
                    Tindex = index;
                }
            }else if(tmp != -1)            //有重复的情况
            {
                a.erase(0,tmp+1);           //删除重复的字母及其之前的元素
                a.push_back(s[i]);
                index += (tmp+1);
                len = a.size();
            }
        }
        return Tlen;       
    }
};
