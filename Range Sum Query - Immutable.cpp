#include <iostream> 
#include <vector>


using namespace std;

class NumArray {
    private: vector<int> pref;

    public:
        NumArray(vector<int>& nums) {
           pref.resize(nums.size() + 1, 0);
           for(int i = 0; i < nums.size(); i++)
            {
                pref[i + 1] = pref[i] + nums[i];
            }
        }
        
        int sumRange(int left, int right) {
            
            return pref[right + 1] - pref[left];
    };

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray obj(nums);
    cout << obj.sumRange(1,3) << endl;
    cout << obj.sumRange(0,4) << endl;
}