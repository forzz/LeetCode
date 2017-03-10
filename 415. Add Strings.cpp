class Solution {
public:
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){//当carry不为0时仍需进行
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;//sum保存当前两位相加的结果，此时更新carry
        sum = sum % 10;
        res =  res + to_string(sum);//利用字符串保存由低位到高位的结果
    }
    reverse(res.begin(), res.end());//翻转字符串
    return res;
}
};
