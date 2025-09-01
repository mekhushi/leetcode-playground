class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) -> double {
            double before = static_cast<double>(pass) / total;
            double after = static_cast<double>(pass + 1) / (total + 1);
            return after - before;
        };

        std::priority_queue<std::pair<double, std::pair<int, int>>> maxHeap;

        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            maxHeap.emplace(gain(pass, total), std::make_pair(pass, total));
        }

        while (extraStudents--) {
            auto [_, pt] = maxHeap.top();
            maxHeap.pop();
            int pass = pt.first + 1;
            int total = pt.second + 1;
            maxHeap.emplace(gain(pass, total), std::make_pair(pass, total));
        }

        double totalRatio = 0.0;

        while (!maxHeap.empty()) {
            auto [_, pt] = maxHeap.top();
            maxHeap.pop();
            totalRatio += static_cast<double>(pt.first) / pt.second;
        }

        return totalRatio / classes.size();
    }
};
