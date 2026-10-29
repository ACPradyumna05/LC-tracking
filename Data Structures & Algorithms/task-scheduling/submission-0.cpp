class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(char t:tasks){
            freq[t-'A']++;
        }
        int maxFreq=0;
        for(int f:freq){
            maxFreq=max(maxFreq,f);
        }

        int countMax=0;
        for(int f:freq){
            if(f==maxFreq){
                countMax++;
            }
        }

        int emptySlot = (maxFreq-1)*(n+1)+countMax;

        return max(emptySlot, (int)tasks.size());
    }
};
