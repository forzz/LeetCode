class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {//先判断再添加map可以保证不会重复
            if (m.count(target - nums[i])) 
                return {i, m[target - nums[i]]};
            m[nums[i]] = i;
        }
        return {};
    }
}; 
