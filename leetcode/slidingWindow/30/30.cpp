#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// 30. 串联所有单词的子串
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = words.size( );
        int n = words[0].size( );
        int l = s.size( );
        unordered_map<string, int> flag;
        for (int i = 0;i < m;i++)
            flag.insert({ words[i], 0 });
        
        int wl = m * n;
        for (int i = 0;i < n;i++)
        {
            int j = i;
            while (j<l-wl)
            {
                int t = j;
                while (t < wl+j)
                {
                    string sub = s.substr(t, n);
                    if (!flag.count(sub))
                        break;
                    else
                        flag[sub]++;
                    t += n;
                }
                int isI = 1;
                for (auto tmp : flag)
                {
                    if (tmp.second != 1)
                        isI = 0;
                    tmp.second = 0;
                }
                if (isI) ans.push_back(j);
                j += wl;
            }
        }
        return ans;
    }
};

int main( )
{
    Solution so;
    string s = "barfoothefoobarman";
    vector<string> words = { "foo","bar" };
    for (auto i : so.findSubstring(s, words))
        cout << i << " ";
}
