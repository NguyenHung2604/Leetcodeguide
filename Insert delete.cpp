#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;

class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> v;

    public:
        RandomizedSet() {

        }
        
        bool check(int val)
        {
            if(mp.find(val) != mp.end())
            {
                return true;
            }

            return false;
        }

        bool insert(int val) {
           if(check(val))
           {
                return false;
           }
           v.push_back(val);
           mp[val] = v.size() - 1; // su dung index cua thang nay de gan vao gia tri second cua map
           return true;
        }
        
        bool remove(int val) {
            if(!check(val))
            {
                return false;
            }

            auto it = mp.find(val);
            v[it->second] = v.back();
            v.pop_back();
            mp[v[it->second]] = it->second;
            mp.erase(val);
            return true;
        } 

        
        int getRandom() {
            return v[rand() % (v.size())];
        }
    };
    
    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */

int main() {
    return 0;
}