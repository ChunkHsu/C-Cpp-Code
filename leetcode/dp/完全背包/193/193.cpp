#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        // 字符串 s 作为背包，单词列表作为物品
        unordered_map<string, int> letter;
        for (string word : wordDict) // 记录存在的单词列表
            letter[word] = 1;

        int n = s.size();
        vector<bool> dp(n + 1, false); // 前 j 个字符串中，是否有拼接方案，dp[j] = 1, 有 否则 无
        int m = wordDict.size();

        dp[0] = true;
        for (int j = 0;j <= n;j++) // 遍历字符串（背包）
            for (int i = 0;i < m;i++) { // 便利单词（物品）
                int t = wordDict[i].size(); 
                if (j >= t) // 背包可装下
                    if (letter.count(s.substr(j - t, t))) // 单词存在
                        dp[j] = max(dp[j], dp[j - t]);
            }
        return dp[n];
    }
};
int main()
{
    Solution so;
    string s = "leetcodek";
    vector<string> wordDict = {"leet","code"};
    cout << so.wordBreak(s, wordDict) << endl;
}