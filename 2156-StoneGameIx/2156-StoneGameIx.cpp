// Last updated: 29/08/2026, 03:06:58
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        if(stones.size()<=1){
            return false;
        }
        int cnt[3]={};
        for(int x:stones){
            cnt[x%3]++;
        }
        int p =cnt[0];
        int q =cnt[1];
        int r =cnt[2];

        if(q==0||r==0){
            return max(q,r) > 2 && (p%2 == 1);
        }

        return abs(q-r) > 2 || (p%2==0);
    }
};