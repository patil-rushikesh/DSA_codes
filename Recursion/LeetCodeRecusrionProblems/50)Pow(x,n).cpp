class Solution {
public:
    double myPow(double base, int exponent) {
        if (exponent == 0)
            return 1;
        else if (exponent == 1)
            return base;
        else if (exponent == -1)
            return 1 / base;
        
        double result = myPow(base * base, exponent / 2);
        if (exponent % 2 != 0) {
            if (exponent > 0)
                result *= base;
            else
                result /= base;
        }
        
        return result;
    }
};
