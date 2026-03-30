class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        // gain(p,t) = how much the ratio improves when we add 1 genius
        // from p/t → (p+1)/(t+1), so gain = (p+1)/(t+1) - p/t
        auto gain = [&](double p, double t) {
            return (p + 1) / (t + 1) - p / t;
        };

        // Max priority queue: stores {gain, pass, total}
        // C++ pq is max by default → biggest gain comes out first
        priority_queue<tuple<double,int,int>> pq;

        // Push every class with its initial gain
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), c[0], c[1]});
        }

        // Greedily assign each extra student one at a time
        while (extraStudents--) {
            // Always pick the class benefiting the MOST right now
            auto [g, p, t] = pq.top(); pq.pop();

            // Add 1 genius to this class
            p++; t++;

            // Re-insert with updated gain (gain changes after adding!)
            pq.push({gain(p, t), p, t});
        }

        // Sum up all final pass ratios
        double total = 0;
        while (!pq.empty()) {
            auto [g, p, t] = pq.top(); pq.pop();
            total += (double) p / t;
        }

        // Return average = sum / number of classes
        return total / classes.size();
    }
};