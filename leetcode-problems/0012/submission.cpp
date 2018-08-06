class Solution {
public:
    string intToRoman(int num) {
        string ans;
        if((num / 1000) > 0){
            ans += string(num/1000, 'M');
            num %= 1000;
        }
        if((num/100) > 0){
            int a = num/100;
            if(a >=5){
                if(a == 9){
                    ans += "CM";
                } else{
                    ans += "D";
                    ans += string(a-5, 'C');
                }
            } else{
                if(a==4){
                    ans += "CD";
                } else{
                    ans += string(a, 'C');
                }
            }
            num %= 100;
        }
        if(num/10 > 0){
            int a = num/10;
            if(a >=5){
                if(a == 9){
                    ans += "XC";
                } else{
                    ans += "L";
                    ans += string(a-5, 'X');
                }
            } else{
                if(a==4){
                    ans += "XL";
                } else{
                    ans += string(a, 'X');
                }
            }
            num %= 10;
        }
        if(num > 0){
            int a = num;
            if(a >=5){
                if(a == 9){
                    ans += "IX";
                } else{
                    ans += "V";
                    ans += string(a-5, 'I');
                }
            } else{
                if(a==4){
                    ans += "IV";
                } else{
                    ans += string(a, 'I');
                }
            }
            num %= 1;
        }
        
        return ans;
    }
};
