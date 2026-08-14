// Last updated: 14/08/2026, 15:35:02
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long k=1;
        if(1+num2>num1){
            return -1;
        }
        else{
            while(k<=60){
                int p=0;
                long long sol = (long long)num1-k*num2;
                if(sol<0){
                    return -1;
                }
                long long temp_sol = sol;
                while(temp_sol!=0){
                    long long largest_power_of_2 = (long long)pow(2, floor(log2(temp_sol)));
                    if (largest_power_of_2 == 0) {
                        largest_power_of_2 = 1;
                    }
                    temp_sol -= largest_power_of_2;
                    p++;
                }
                if (p <= k && k <= sol){
                    return k; 
                }
                k++;
            }
        }
        return -1;
    }
};