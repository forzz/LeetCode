class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        int sign = 1;
        const int n =str.size();
        int i = 0;
        while (str[i] == ' ' && i < n) i++;//找到第一个不是空格的元素
        if (str[i] == '+') {//判断符号
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        for (; i < n; i++) {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (num > INT_MAX / 10 ||(num == INT_MAX / 10 &&(str[i] - '0') > INT_MAX % 10)) {//考虑数的越界问题
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
};
