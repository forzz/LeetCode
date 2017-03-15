class Solution {
//int（-2147483648~2147483647）4Bytes   abs(-2147483648) 结果还是 -2147483648
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))//边界值而且与实际不符（也不可能有这种结果），只能特判
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;//异或可以表示仅有一个条件为真的情况
//当 dividend = INT_MIN时，-dividend会溢出，所以用 long long
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { //除法可以转换为不断减除数，可以通过对除数和结果的位操作实现加速
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {//每次给除数翻倍，结果也翻倍
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;//当前除数的倍数无法乘2的时候，可以做减法更新结果，然后等待循环下一次除数从最初再次翻倍
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};
