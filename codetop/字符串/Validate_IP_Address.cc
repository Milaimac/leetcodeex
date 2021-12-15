/*
 * @Date: 2021-12-03 11:18:13
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-03 12:30:53
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string validIPAddress(string queryIP)
    {
        if(isIpv4(queryIP)){
            return "IPv4";
        }
        if(isIPv6(queryIP)){
            return "IPv6";
        }
        return "Neither";
    }

    bool isIpv4(string IP)
    {
        vector<string> res;
        split(IP, res, '.', 3);
        if(res.size() != 4){
            return false;
        }

        for(int i = 0;i < res.size();++i){
            string temp = res[i];
            if(temp[0] == '0' && temp.size() > 1){ // 如果有前导零
                return false;
            }
            if(temp.size() > 3)
            {
                return false;
            }

            int num = 0;
            for(int j = 0;j < temp.size();++j)
            {
                num = 10* num + temp[j] - '0';
                if(temp[j] < '0' || temp[j] > '9'){
                    return false;
                }
                if(num > 255){
                    return false;
                }
            }
        }
        return true;
    }


    /**
     * @description:
     * 16 bit == 16 个二进制位， 那么16比特等价于4个16进制位
     * 不能有分隔符连在一起的情况。 
     * 可以有前导零， 但是不能有多余的0 ； 02001
     * 有7个分隔符 
     * @param {string} ip
     * @return {*}
     */
    bool isIPv6(string ip){
        vector<string> res;
        split(ip, res, ':', 7);
        if(res.size() != 8){
            return  false;
        }
        for(int i = 0;i < res.size();++i){
            string temp = res[i];
            // 段内中的长不能超过4
            if(temp.size() > 4){
                return false;
            }
            for(int j = 0;j < temp.size();++j){
                if((temp[j] >= '0' && temp[j] <= '9') || (temp[j] >= 'a' && temp[j] <= 'f') || (temp[j] >= 'A' && temp[j] <= 'F')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }

    // 将string s分隔出来到字符串数组中， 交给对应的ipv解析器解决。
    void split(string s, vector<string> &res, char delimiter, int delimitercnt)
    {
        int i = 0;
        int cnt = 0;
        string temp;
        while (i < s.size())
        {
            if (s[i] != delimiter)
            {
                temp.push_back(s[i]);
            }
            if (s[i] == delimiter || i == s.size() - 1)
            {
                if(temp.size() == 0){
                    //连续两个分割符
                    res.clear();
                    return;
                }
                if(s[i] == delimiter)
                {
                    //计算分割符的个数
                    cnt++;
                }
                if(cnt > delimitercnt)
                {
                    res.clear();
                    return; 
                }
                res.push_back(temp);
                temp.clear();
            }   
            ++i;
        }
    }
};

// ipv4地址中的点分十进制 是0到255， 其中不会有前导零
//