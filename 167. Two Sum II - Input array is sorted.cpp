class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {//先判断再添加map可以保证不会重复
            if (m.count(target - nums[i])) 
                return {++m[target - nums[i]],++i};//m中保存的是较小值，i是较大值
            m[nums[i]] = i;
        }
        return {};
    }
}; 
