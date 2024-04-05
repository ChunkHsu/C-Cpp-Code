# include<iostream>
# include<vector>

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        ans[0] = celsius + 237.15;
        ans[1] = celsius * 1.80 + 32.00;
        return ans;
    }
};

vector<double> convertTemperature(double celsius) {
    vector<double> ans;
    ans.push_back(celsius + 237.15);
    ans.push_back(celsius * 1.80 + 32.00);
    return ans;
}

int main()
{
    double celsius = 36.2;
    vector<double> ans = convertTemperature(celsius);
    for(unsigned int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] << endl;
    }
}
