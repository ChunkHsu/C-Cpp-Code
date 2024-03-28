#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        if(tn>sn)return "";
        unordered_map<char, int> ht;
        for(char c: t) ht[c]++;
        int ans = INT_MAX, index=0;

        int left = 0;
        int need = tn;
        for(int i=0;i<sn;i++)
        {
            
            if(ht[s[i]]>0) need--;
            ht[s[i]]--;// 增加hit
            
            if(need==0)
            {
                while((ht[s[left]]<0 && left <= i)) // 无key 或 key < 0冗余
                {   
                    ht[s[left]]++;
                    left++;
                }
            
                if(ans>i-left+1) // update ans
                {
                    ans=i-left+1;
                    index=left;
                }
                need++;
                ht[s[left]]++;
                left++;
            }
        }
        if(ans==INT_MAX)
            return "";
        else
            return s.substr(index, ans);
    }
    string minWindow2(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        if(tn>sn)return "";
        unordered_map<char, int> ht;
        for(char c: t) ht[c]++;
        int ans = INT_MAX, index=0;

        int left = 0;
        int need = tn;
        for(int i=0;i<sn;i++)
        {
            if(ht.count(s[i])!=0) // 有key
            {
                if(ht[s[i]]>0)need--;
                ht[s[i]]--;// 增加hit
            }
            
            if(need==0)
            {
                while((!ht.count(s[left]) || (ht.count(s[left]) && ht[s[left]]<0)) && left<sn) // 无key 或 key < 0冗余
                {
                    if(ht.count(s[left])) // 去除key < 0冗余
                    {   
                        ht[s[left]]++;
                        left++;
                    }
                    else
                        left++; // 去除非 key
                }
                
                if(ans>i-left+1) // update ans
                {
                    ans=i-left+1;
                    index=left;
                }
                ht[s[left]]++;
                left++;
                need++;
            }
        }
        if(ans==INT_MAX)
            return "";
        else
            return s.substr(index, ans);
    }
};
int main()
{
    Solution so;
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<so.minWindow2(s,t)<<endl;
}