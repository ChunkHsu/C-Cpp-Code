#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l=s.size();
        bool f[l+1]; // f[i]表示第直到i个字母都能被拼成与否
        int minl=wordDict[0].size(),maxl=wordDict[0].size(); // 记录最大最小的word单词字符数
        unordered_map<string, int> ht; // 初始化map 并更新maxl与minl
        for(string word : wordDict)
        {
            int word_len = word.size();
            if(word_len > maxl) maxl = word_len;
            if(word_len < minl) minl = word_len; 
            ht[word] = 1;
        }
        s="0"+s;
        f[0]=true;
        // 开始递推
        for(int i=1; i<=l;i++)
        {
            /* f[i] = ((f[i-minl] && ht.count(s.substr(i-minl+1,minl))) ||
                        (f[i-minl-1] && ht.count(s.substr(i-minl,minl+1))) || ... 
                        (f[i-maxl] && ht.count(s.substr(i-maxl+1,maxl))))*/
            f[i]=false;
            for(int j=minl; j <= maxl; j++)
            {
                if(i-j<0)break;
                string st = s.substr(i-j+1, j);
                f[i] = ht.count(st) && f[i-j]? true: f[i];
            }
        }
        return f[l];
    }
};
int main()
{
    Solution so;
    string s="applepenapple";
    vector<string> words={"apple", "pen"};
    cout<< so.wordBreak(s, words) <<endl;
    int t = 1 && 0?1:0; 
    cout<<t<<endl;
}