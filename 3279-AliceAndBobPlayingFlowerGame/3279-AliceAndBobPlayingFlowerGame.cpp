// Last updated: 14/08/2026, 15:34:58
class Solution {
public:
    long long flowerGame(int n, int m) {
        if(n%2==0){
            long long nOdd = n/2;
            long long nEven = n/2;
            if(m%2==0){
                long long mOdd = m/2;
                long long mEven = m/2;
                return nOdd*mEven + nEven*mOdd;
            }
            else{
                long long mOdd = floor(m/2)+1;
                long long mEven = m/2;
                return nOdd*mEven + nEven*mOdd;
            }
        }
        else{
            long long nOdd = floor(n/2)+1;
            long long nEven = floor(n/2);
            if(m%2==0){
                long long mOdd = m/2;
                long long mEven = m/2;
                return nOdd*mEven + nEven*mOdd;
            }
            else{
                long long mOdd = floor(m/2)+1;
                long mEven = floor(m/2);
                return nOdd*mEven + nEven*mOdd;
            }
        }
    }
};