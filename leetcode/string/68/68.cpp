#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size( );
        vector<int> lens(n, 0);
        vector<pair<int, int>>row_num; // 存放一行的元素个数,空格数
        int row = 0;
        int sum_len = 0;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            lens[i] = words[i].size( );
            sum_len += lens[i] + 1;
            num++;
            if (sum_len - 1 > maxWidth)
            {
                row++; // 新的一行
                sum_len = sum_len - lens[i] - num;
                row_num.push_back(make_pair(num - 1, maxWidth - sum_len)); // 存放一行的元素个数,空格数
                sum_len = 0;
                num = 0;
                i--; // 继续访问这个元素
                continue; 
            }
            if (i == n - 1 && sum_len - 1 <= maxWidth)
            {
                row++; // 新的一行
                
                sum_len = sum_len - num;
                row_num.push_back(make_pair(num, maxWidth - sum_len)); // 存放一行的元素个数,空格数
                sum_len = 0;
                num = 0;
            }
        }

        for (pair<int, int> p : row_num)
            cout << p.first << " " << p.second << endl;
        
        int max_row = row;
        int pre = 0;
        vector<string> ans(row);
        row = 0;
        int t = row_num[row].first;
        // 计算space
        int space = 0, res_space = 0;
        if (row_num[row].first != 1)
        {
            res_space = row_num[row].second % (row_num[row].first - 1);
            space = row_num[row].second / (row_num[row].first - 1);
        }
        else
            space = row_num[row].first;
        
        if (row == max_row)
        {
            space = 1; res_space = 0;
        }
        // 填入
        for (int i = 0;i < n;i++)
        {
            if (i < t)
            {
                
                if (i != t - 1)
                {
                    int ext = 0;
                    cout << res_space << endl;
                    if (i - pre < res_space)
                        ext = 1;
                    ans[row] += words[i] + string(ext + space, ' ');
                }
                else
                {
                    ans[row] += words[i];
                    int last = maxWidth - ans[row].size( );
                    if(last>0)
                        ans[row] += string(last, ' ');
                }
            }
            else
            {
                pre = row_num[row].first;
                row++;i--;
                t += row_num[row].first;
                space = 0; res_space = 0;
                if (row_num[row].first != 1)
                {
                    res_space = row_num[row].second % (row_num[row].first - 1);
                    space = row_num[row].second / (row_num[row].first - 1);
                }
                else
                    space = row_num[row].first;
                if (row == max_row-1)
                {
                    space = 1; res_space = 0;
                }
            }
        }
        
        return ans;
    }
};
int main( )
{
    Solution so;
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    for (string str : so.fullJustify(words, maxWidth))
        cout <<"*"<< str <<"*"<< endl;
    
}
/*
输出:
[
    "This    is    an",
    "example  of text",
    "justification.  "

    "What   must   be",
    "acknowledgment  ",
    "shall be        "

    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
]
*/
