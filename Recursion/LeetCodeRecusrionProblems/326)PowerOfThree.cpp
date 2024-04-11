class Solution {
public:
long long powerOfThree(int n){
    if(n == 0){
        return 1;
    } else {
        return powerOfThree(n-1) * 3LL;
    }
}

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    for(int i = 0; ; i++){
        long long result = powerOfThree(i);
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