class Solution {
public:
long long powerOfTwo(int n){
    if(n == 0){
        return 1;
    } else {
        return powerOfTwo(n-1) * 2LL;
    }
}

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    for(int i = 0; ; i++){
        long long result = powerOfTwo(i);
        if(result == n){
            return true;
        }
        if(result > n || result < 0) { 
            break;
        }
    }
    return false;
}
};