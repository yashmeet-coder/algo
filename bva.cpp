#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int finish;
    int weight;
};

bool compareIntervals(Interval i1, Interval i2) {
    return i1.finish < i2.finish;
}

int findLastNonConflictingInterval(vector<Interval>& intervals, int index) {
    for (int i = index - 1; i >= 0; i--) {
        if (intervals[i].finish <= intervals[index].start) {
            return i;
        }
    }
    return -1;
}

int findMaxWeight(vector<int>& maxWeights, vector<Interval>& intervals, int index) {
    int lastNonConflictingInterval = findLastNonConflictingInterval(intervals, index);
    if (lastNonConflictingInterval == -1) {
        return intervals[index].weight;
    } else {
        return intervals[index].weight + maxWeights[lastNonConflictingInterval];
    }
}

int weightedIntervalScheduling(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compareIntervals);
    vector<int> maxWeights(intervals.size());
    maxWeights[0] = intervals[0].weight;
    for (int i = 1; i < intervals.size(); i++) {
        int maxWeight = findMaxWeight(maxWeights, intervals, i);
        maxWeights[i] = max(maxWeights[i-1], maxWeight);
    }
    return maxWeights[intervals.size()-1];
}

int main() {
    vector<Interval> intervals = {
        {0, 6, 10},
        {1, 4, 5},
        {3, 5, 12},
        {5, 7, 9},
        {6, 9, 15},
        {8, 10, 1},
    };
    int maxWeight = weightedIntervalScheduling(intervals);
    cout << "Maximum weight: " << maxWeight << endl;
    return 0;
}
