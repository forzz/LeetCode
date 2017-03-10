class Solution {//模拟竖式乘法
//假设两个整数的长度分别为了l1和l2，则其最后结果长度为l1+l2（最后有进位）或者l1+l2-1（最后没有有进位）。
//因此，可以先用长度为l1+l2的数组记录结果，最后再转成字符串。
//进行乘法的时候，先把各个位的相乘结果对应累加起来，即第1个整数的第i位（低位到高位）和第2个整数的第j位（低位到高位）
//相乘的结果应该存放在数组的i+j位。然后再统一处理进位。然后再统一处理进位。
//最后再将数组转成字符串前，需要跳过前面的零。如果结果只有0，则只返回0。
public:
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');//结果数组，模拟竖式计算
    for (int i = num1.size() - 1; 0 <= i; --i) {//后序扫描num1，作为乘数
        int carry = 0;//进位
        for (int j = num2.size() - 1; 0 <= j; --j) {//后序扫描num2，整体作为被乘数
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            //(sum[i + j + 1] - '0')竖式计算中的上一次计算相应位上的结果
            sum[i + j + 1] = tmp % 10 + '0';//当前位值
            //计算该位结果，暂存i+j+1位（循环结束后，至多j+1位上就是num1当前位的结果）
            carry = tmp / 10;//进位
        }
        sum[i] += carry;//将最高位的进位值放到相应位置上（之前循环计算，最高到sum[i+1]）
    }
    int startpos = sum.find_first_not_of("0");
    if (startpos!=-1) 
        return sum.substr(startpos);
    else
        return "0";
}
};
