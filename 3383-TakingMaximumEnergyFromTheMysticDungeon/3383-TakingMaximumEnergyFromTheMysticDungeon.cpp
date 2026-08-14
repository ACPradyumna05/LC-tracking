// Last updated: 14/08/2026, 15:34:34
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> magic(n, 0);
        int maxMagic=INT_MIN;
        
        for (int i = n-1; i>=0; i--) {
            magic[i]=energy[i] + (i+k<n?magic[i+k]:0);
            if(magic[i]>maxMagic){
                maxMagic=magic[i];
            }
        }
        return maxMagic;
    }
};