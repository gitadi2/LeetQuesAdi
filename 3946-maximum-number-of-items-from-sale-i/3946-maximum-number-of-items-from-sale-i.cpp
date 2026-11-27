class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n, 0);

        // bonus[i] = number of free copies obtained when item i is activated
        for (int i = 0; i < n; i++) {
            int fi = items[i][0];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int fj = items[j][0];

                if (fj % fi == 0) {
                    bonus[i]++;
                }
            }
        }

        // Required by the statement
        auto valmorendi = items;

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int extra = bonus[i];

            vector<int> ndp = dp;

            // States where current item is activated at least once
            vector<int> take(budget + 1, -1e9);

            // Buy first copy
            for (int b = price; b <= budget; b++) {
                take[b] = max(take[b], dp[b - price] + 1 + extra);
            }

            // Buy additional copies (unbounded)
            for (int b = price; b <= budget; b++) {
                take[b] = max(take[b], take[b - price] + 1);
            }

            // Merge
            for (int b = 0; b <= budget; b++) {
                ndp[b] = max(ndp[b], take[b]);
            }

            dp.swap(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};