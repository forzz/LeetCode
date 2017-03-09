class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()==0)    return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++)//只需要枚举到倒数第三个，后面2个是left和right
        {
            int left = i+1;
            int right = n-1;
            while(left<right)
            {
                if(nums[i]+nums[left]+nums[right]==0)
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    while(nums[left]==nums[left+1])   left++;//跳过重复元素
                    while(nums[right]==nums[right-1])   right--;//跳过重复元素
                    left++;//跳过1个left，为i++腾出位置
                }
                else if((nums[i]+nums[left]+nums[right]>0))
                    right--;
                else
                    left++;
            }
            while(nums[i]==nums[i+1])
                i++;
        }
        return ans;
        
    }
};

