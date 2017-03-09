class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];//随便初始化
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());//排序后才能使用双指针
        for (int i = 0; i < nums.size() - 2; ++i) {//双指针
            int left = i + 1, right = nums.size() - 1;//在i的右面查找
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) {//找到更优解
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};
