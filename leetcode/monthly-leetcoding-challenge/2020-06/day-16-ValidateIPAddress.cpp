/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

class Solution {
public:
    bool isvalidcharv6 (char a) {
        if (a >= '0' && a <= '9')
            return true;
        if (a >= 'a' && a <= 'f')
            return true;
        if (a >= 'A' && a <= 'F')
            return true;
        if (a == ':')
            return true;
        return false;
    }
    
    bool isvalidcharv4 (char a) {
        if (a >= '0' && a <= '9')
            return true;
        if (a == '.')
            return true;
        return false;
    }
    
    string validIPAddress(string IP) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int numcolon, numdot;
        numdot = count (IP.begin(), IP.end(), '.');
        numcolon = count (IP.begin(), IP.end(), ':');
        
        if(IP.size() > 39)
            return "Neither";
        
        if (numdot == 3){
            int startidx = 0, itemp, iszero = 0;
            string temp;
            for (int i = 0; i < IP.size(); ++i){
                if (!isvalidcharv4(IP[i])){
                    return "Neither";
                }
                if (IP[i] == '.'){
                    temp = IP.substr(startidx, i - startidx);
                    if (temp == ""){
                        return "Neither";
                    }
                    itemp = stoi(temp);
                    if (iszero){
                        if (itemp){
                            return "Neither";
                        }
                        else{
                            if (i - startidx != 1){
                                return "Neither";
                            }
                        }
                    }
                    if (itemp > 255){
                        return "Neither";
                    }
                    startidx = i + 1;
                    iszero = 0;
                }
                if ((i && IP[i-1] == '.') || !i){
                    if (IP[i] == '0'){
                        iszero = 1;
                    }
                }
            }
            temp = IP.substr(startidx, IP.size() - startidx);
            if (temp == ""){
                return "Neither";
            }
            itemp = stoi(temp);
            if (iszero){
                if (itemp){
                    return "Neither";
                }
                else{
                    if (IP.size() - startidx != 1){
                        return "Neither";
                    }
                }
            }
            if (itemp > 255){
                return "Neither";
            }
            return "IPv4";
        }
        
        else if (numcolon == 7){
            int lenbetween = 0;
            for (int i = 0; i < IP.size(); ++i){
                lenbetween++;
                if (!isvalidcharv6(IP[i])){
                    return "Neither";
                }
                if (IP[i] == ':'){
                    lenbetween--;
                    if (lenbetween == 0 || lenbetween > 4){
                        return "Neither";
                    }
                    lenbetween = 0;
                }
            }
            if (lenbetween == 0 || lenbetween > 4){
                return "Neither";
            }
            lenbetween = 0;
            return "IPv6";
        }
        else{
            return "Neither";
        }
    }
};