#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution{
public:
    enum state{
        STATE_initial,
        STATE_int_sign,
        STATE_integer,
        STATE_point,
        STATE_point_without_int,
        STATE_fraction,
        STATE_exp,
        STATE_exp_sign,
        STATE_exp_number,
        STATE_end,
    };
    enum Chartype{
        CHAR_number,
        CHAR_exp,
        CHAR_piont,
        CHAR_sign,
        CHAR_sapce,
        CHAR_illegal,
    };

    Chartype toChartype(char ch){
        if(ch > '0' && ch <' 9'){ //这里没有把'0'给加进去。
            return CHAR_number;
        }
        else if(ch == 'e' || ch == 'E'){
            return CHAR_exp;
        }
        else if(ch == '.'){
            return CHAR_piont;
        }
        else if(ch == '+' || ch == '-'){
            return CHAR_sign;
        }
        else if(ch == ' '){
            return CHAR_sapce;
        }
        else{
            return CHAR_illegal;
        }
    }

    
    bool isNumber(string s) {
        unordered_map<state, unordered_map<Chartype, state>> transfer{
            {
                STATE_initial, {
                    {CHAR_sapce, STATE_initial},
                    {CHAR_number, STATE_integer},
                    {CHAR_piont, STATE_point_without_int},
                    {CHAR_sign, STATE_int_sign},
                }
            }, {
                STATE_int_sign, {
                    {CHAR_number, STATE_integer},
                    {CHAR_piont, STATE_point_without_int},
                }
            }, {
                STATE_integer, {
                    {CHAR_number, STATE_integer},
                    {CHAR_exp, STATE_exp},
                    {CHAR_piont, STATE_point},
                    {CHAR_sapce, STATE_end},
                }
            }, {
                STATE_point, {
                    {CHAR_number, STATE_fraction},
                    {CHAR_exp, STATE_exp},
                    {CHAR_sapce, STATE_end},
                }
            }, {
                STATE_point_without_int, {
                    {CHAR_number, STATE_fraction},
                }
            }, {
                STATE_fraction,
                {
                    {CHAR_number, STATE_fraction},
                    {CHAR_exp, STATE_exp},
                    {CHAR_sapce, STATE_end},
                }
            }, {
                STATE_exp,
                {
                    {CHAR_number, STATE_exp_number},
                    {CHAR_sign, STATE_exp_sign},
                }
            }, {
                STATE_exp_sign, {
                    {CHAR_number, STATE_exp_number},
                }
            }, {
                STATE_exp_number, {
                    {CHAR_number, STATE_exp_number},
                    {CHAR_sapce, STATE_end},
                }
            }, {
                STATE_end, {
                    {CHAR_sapce, STATE_end},
                }
            }
        };

        int len = s.length();
        state st = STATE_initial;

        for (int i = 0; i < len; i++) {
            Chartype typ = toChartype(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_integer || st == STATE_point || st == STATE_fraction || st == STATE_exp_number || st == STATE_end;
    }

};