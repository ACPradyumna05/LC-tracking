// Last updated: 14/08/2026, 15:35:23
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            double before = (double)pass / total;
            double after = (double)(pass + 1) / (total + 1);
            return after - before;
        };

        // Max heap: store {gain, pass, total}
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto [g, pt] = pq.top(); pq.pop();
            int pass = pt.first + 1;
            int total = pt.second + 1;
            pq.push({gain(pass, total), {pass, total}});
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto [_, pt] = pq.top(); pq.pop();
            sum += (double)pt.first / pt.second;
        }

        return sum / classes.size();

    }
};