class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return ~dividend + 1;
        int result = 0;
        bool sign = (dividend < 0) ^ (divisor < 0);
        if (dividend > 0)
            dividend = ~dividend + 1;
        if (divisor > 0)
            divisor = ~divisor + 1;
        while (dividend <= divisor) {
            result--;
            dividend -= divisor;
        }
        if (!sign)
            return (~result + 1);
        return result;
    }
    int divide2(int dividend, int divisor) {
        //sign== false means result will be positive
        bool sign= (divisor == abs(divisor)) ^ (dividend == abs(dividend));
        int result= 0;
        if(divisor > 0)
            divisor *= -1;
        if(dividend > 0)
            dividend *= -1;
        while(dividend <= divisor){
            dividend -= divisor;
            result++;
        }
        if(sign)
            result *= -1;
        return result;
    }
};