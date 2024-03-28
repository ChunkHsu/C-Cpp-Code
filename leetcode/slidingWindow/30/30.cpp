#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// 30. 串联所有单词的子串
class Solution {
public:
        vector<int> findSubstring(string s, vector<string>& words) {
        int m=words.size();
        int n=words[0].size();
        int l=s.size();
        vector<int> ans;
        // 初始化map
        unordered_map<string, int> ht1;
        for(string ts : words) ht1[ts]++;
        for(int i=0;i<n;i++)
        {
            int left=i, t=0;
            unordered_map<string, int> ht2;
            for(int j=i;j<=l-n;j+=n)
            {
                string sub = s.substr(j,n);
                if(ht1.count(sub)!=0)// 有key
                {
                    ht2[sub]++;
                    t++;
                    while(ht2[sub]>ht1[sub]) // 键的数量过多
                    {
                        string leftSub = s.substr(left, n);
                        --ht2[leftSub];
                        left+=n;
                        t--;
                    }
                    if(t==m) // word数目相等
                    {
                        ans.push_back(left);
                        string leftSub = s.substr(left, n);
                        --ht2[leftSub];
                        left+=n;
                        t--;
                    }
                }
                else{//无 key
                    ht2.clear();
                    left=j+n;
                    t=0;
                }
            }
        }
        return ans;
    }
};
class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int wordCount = words.size();
        int substringLength = wordLength * wordCount;
        vector<int> indices;
        if (s.size() < substringLength) return indices;

        // Build the word frequency map
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            ++wordFreq[word];
        }

        // Slide a window of size substringLength over the string s
        for (int i = 0; i < wordLength; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> seenWords;
            for (int j = i; j <= s.size() - wordLength; j += wordLength) {
                string word = s.substr(j, wordLength);
                // If the word is part of words
                if (wordFreq.find(word) != wordFreq.end()) {
                    ++seenWords[word];
                    ++count;
                    // If there are more occurrences of "word" than expected
                    while (seenWords[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLength);
                        --seenWords[leftWord];
                        --count;
                        left += wordLength;
                    }
                    // If all words match
                    if (count == wordCount) {
                        indices.push_back(left);
                        string leftWord = s.substr(left, wordLength);
                        --seenWords[leftWord];
                        --count;
                        left += wordLength;
                    }
                } else {
                    // Reset if the word is not in words
                    seenWords.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }
        return indices;
    }
};

int main( )
{
    Solution so;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = { "word","good","best","word" };
    for (auto i : so.findSubstring(s, words))
        cout << i << " ";
    cout<<endl;
}
