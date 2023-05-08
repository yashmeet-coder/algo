#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Knapsack {
public:
    int total;
    vector<pair<int, int>> items;
    Knapsack(int n){
        total=n;
    }

    void addItem(int w, int v) {
        items.push_back(make_pair(w,v));
    }

    int maximum() {
        cout<<items.size()<<endl ;
        int n = items.size();
        vector<vector<int>> dp(n+1, vector<int>(total+1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= total; j++) {
                if (items[i-1].first >= j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], items[i-1].second + dp[i-1][j-items[i-1].first]);
                }
            }
        }

        return dp[n][total];
    }
};
int main() {
    Knapsack obj(7);
    obj.addItem(1, 1);
    obj.addItem(3, 4);
    obj.addItem(4, 5);
    obj.addItem(5, 7);
    int max=obj.maximum();
    cout<<"Maximum value: "<<max<<endl;

    return 0;
}
