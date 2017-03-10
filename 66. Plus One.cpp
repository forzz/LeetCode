class Solution
{
    public:
        vector<int> plusOne(vector<int> &digits)
        {
            int c = 1; // 令进位标识初始值为1
            for(int i = digits.size() - 1; i >= 0; -- i)
            {// 不断处理进位
                int a = digits[i] + c;
                digits[i] = a % 10;
                c = a / 10;
            }
            if(c == 1) // 如果最后还有进位，则在数组最前面在插入1
                digits.insert(digits.begin(), 1);
            return digits;
        }
};
