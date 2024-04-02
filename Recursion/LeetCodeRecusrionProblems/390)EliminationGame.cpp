class Solution {
public:
    int lastRemaining(int n) {
        return remainingNumber(n, true, 1, 1);
    }
    
    int remainingNumber(int n, bool leftToRight, int head, int step) {
        if (n == 1) 
            return head;
        
        if (leftToRight || n % 2 == 1) {
   
            head += step;
        }
        
        return remainingNumber(n / 2, !leftToRight, head, step * 2);
    }
};
