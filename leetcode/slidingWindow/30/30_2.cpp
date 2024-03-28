#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m=words.size();
        int n=words[0].size();
        int l=s.size();
        vector<int> ans;
        unordered_map<string, int> ht;
        for(string word: words) ht[word]++; // 记录单词个数

        for(int i=0;i<n;i++)
        {
            int t=0, left=i;
            unordered_map<string, int>ht2;
            for(int j=i;j<=l-n;j+=n)
            {
                string sub = s.substr(j,n);
                if(!ht.count(sub)) // 无key
                {
                    t=0;
                    left=j+n;
                    ht2.clear();
                    continue;
                }
                ht2[sub]++;
                if(ht2[sub]<=ht[sub])//单词不够
                    t++;
                else
                {//单词超过
                    string left_sub=s.substr(left,n);
                    while(left_sub!=sub)
                    {
                        
                        ht2[left_sub]--;
                        t--;
                        left+=n;
                        left_sub=s.substr(left,n);
                    }
                    left+=n;
                    ht2[sub]--;
                }
                if(t==m) // 单词够的话
                {
                    // 左窗口右移
                    ans.push_back(left);
                    string left_sub=s.substr(left,n);
                    ht2[left_sub]--;
                    t--;
                    left+=n;
                }            
            }
        }
        return ans;
    }
};
int main()
{
    Solution so;
    string s="barfoofoobarthefoobarman";
    vector<string> words={"foo","bar", "the"};
    for(auto t: so.findSubstring(s, words))
        cout<< t <<" ";
    cout<<endl;
}