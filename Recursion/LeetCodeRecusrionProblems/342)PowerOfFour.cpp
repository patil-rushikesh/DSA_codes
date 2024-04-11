class Solution {
public:
long long powerOfFour(int n){
    if(n == 0){
        return 1;
    } else {
        return powerOfFour(n-1) * 4LL;
    }
}

bool isPowerOfFour(int n) {
    if (n <= 0) {
        return false;
    }
    for(int i = 0; ; i++){
        long long result = powerOfFour(i);
        if(result == n){
            return true;
        }
        if(result > n || result < 0) { // Check for overflow or if result has surpassed n
            break;
        }
    }
    return false;
}


};