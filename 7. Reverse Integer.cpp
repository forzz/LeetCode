class Solution {
//需要注意溢出的问题。一个int可以表示数字范围是2147483647— -2147483648。当逆序的数字超过这个范围，那么函数返回0。
public:
    int reverse(int x) {//只有当x=0时才停止
        long long res = 0;//
        while(x) {
            res = res*10 + x%10;//取末位
            x /= 10;//右移
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
