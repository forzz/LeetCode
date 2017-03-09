//方法一用set去重，遇到多重复数据会TLE
class Solution {
public:
vector<vector<int> > fourSum(vector<int> &num, int target) {  
        vector<vector<int>> res;  
        int numlen = num.size();  
        if(num.size()<4)return res;  
        sort(num.begin(),num.end());  
        set<vector<int>> tmpres;  
        for(int i = 0; i < numlen; i++)  //枚举第一个
        {  
            for(int j = i+1; j < numlen; j++)  //枚举第二个
            {  
                int begin = j+1;  
                int end = numlen-1;  
                while(begin < end)  //由于数组已排序，一个从后，一个从前，不断枚举
                {  
                    int sum = num[i]+ num[j] + num[begin] + num[end];  
                    if(sum == target)  
                    {  
                        vector<int> tmp;  
                        tmp.push_back(num[i]);  
                        tmp.push_back(num[j]);  
                        tmp.push_back(num[begin]);  
                        tmp.push_back(num[end]);  
                        tmpres.insert(tmp);  
                        begin++;  
                    }else if(sum<target)  
                        begin++;  
                    else  
                        end--;  
                }  
            }  
        }  
        for(auto it=tmpres.begin(); it != tmpres.end(); it++)  
            res.push_back(*it);  
        return res;  
    }  
};

//方法二手工去重，一般会慢，遇到重复数据更快
class Solution {
public:
vector<vector<int> > fourSum(vector<int> &num, int target) {  
        vector<vector<int>> tmpres;  
        int numlen = num.size();  
        if(num.size()<4)return tmpres;  
        sort(num.begin(),num.end());  
        for(int i = 0; i < numlen-3; i++)  
        {  
            for(int j = i+1; j < numlen-2; j++)  
            {  
                int begin = j+1;  
                int end = numlen-1;  
                while(begin < end)  
                {  
                    int sum = num[i]+ num[j] + num[begin] + num[end];  
                    if(sum == target)  
                    {  
                        vector<int> tmp;  
                        tmp.push_back(num[i]);  
                        tmp.push_back(num[j]);  
                        tmp.push_back(num[begin]);  
                        tmp.push_back(num[end]);  
                        tmpres.push_back(tmp);  
                    while(num[begin]==num[begin+1])   begin++;//跳过重复元素
                    while(num[end]==num[end-1])   end--;//跳过重复元素
                        begin++; 
                    }else if(sum<target)  
                        begin++;  
                    else  
                        end--;  
                while(num[j]==num[j+1])     j++;
                }  
                while(num[i]==num[i+1])     i++;
            }  
        }    
        return tmpres;  
    }  
};
