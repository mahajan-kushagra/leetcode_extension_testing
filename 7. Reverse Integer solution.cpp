class Solution {
public:
    int reverse(int x) {
        bool sign= false;
        int reversed= 0, rangeVal= (1u << 31)/10;
        if(x < 0){
            if(x == -(1u <<31))
                return 0;
            x = x*-1;
            sign = true;
        }
        while(x){
            if(reversed > rangeVal)
                return 0;
            //mod = x%10;
            // if(reversed == rangeVal)     //Extra condition
            //     if((!sign && mod > 7) || (sign && mod > 8))
            //         return 0;
            reversed = reversed*10 + x%10;
            x = x/10;
        }
        if(sign)
            reversed = reversed*-1;
        return reversed;
    }
};