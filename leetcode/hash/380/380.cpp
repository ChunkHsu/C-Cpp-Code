#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<ctime>
using namespace std;

class RandomizedSet2 {
public:
    RandomizedSet() {
        ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    }   
    
    bool insert(int val) {
        if(indexHash.contains(val)){
            return false;
        }

        int n = nums.size();
        indexHash[val] = n;
        nums.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!indexHash.contains(val)){
            return false;
        }

        int n = nums.back();
        int index = indexHash[val];
        nums[index] = n;
        indexHash[n] = index;
        indexHash.erase(val);
        nums.pop_back();

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
private:
    vector<int> nums;
    unordered_map<int,int> indexHash;
};


class RandomizedSet
{
    vector<int> vec;
    unordered_map<int, int> hashTable;
public:
    RandomizedSet( )
    {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (hashTable.find(val) == hashTable.end( ))
            return false;
        int n = vec.size( );
        vec.emplace_back(val);
        hashTable[val] = n;
        return true;
    }
    
    bool remove(int val) {
        if (! hashTable.count(val))
            return false;
        int n = hashTable[val];
        vec.erase(vec.begin( ) + n);
        hashTable.erase(val);
        for (auto &pair : hashTable)
            if (pair.second > n)
                pair.second--;
        return true;
    }
    
    int getRandom( )
    {
        int n=vec.size();
        return vec[rand( ) % n];
    }
};
int main( )
{
    RandomizedSet *obj = new RandomizedSet( );
    int val;
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
}


