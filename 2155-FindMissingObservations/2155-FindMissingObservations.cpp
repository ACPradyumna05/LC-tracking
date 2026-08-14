// Last updated: 14/08/2026, 15:35:08
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalRolls = rolls.size() + n;
        int requiredSum = totalRolls * mean;
        int currentSum = std::accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = requiredSum - currentSum;
        
        // Check if it's possible to distribute the missingSum among n rolls
        if (missingSum < n || missingSum > 6 * n) {
            return {}; // Not possible
        }

        // Calculate the base value for each missing roll
        std::vector<int> result(n, 1);
        missingSum -= n; // Subtract the minimum value for each roll
        
        // Distribute the remaining sum
        for (int i = 0; i < n; ++i) {
            int add = std::min(5, missingSum); // Add up to 5 to each roll
            result[i] += add;
            missingSum -= add;
        }
        
        return result;
    }
};