class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = (int)items.size();

        vector<long long> freq(n + 1, 0);
        long long minPrice = LLONG_MAX;

        for (auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, (long long)it[1]);
        }

        vector<long long> multCnt(n + 1, 0);

        for (int x = 1; x <= n; x++) {
            for (int y = x; y <= n; y += x) {
                multCnt[x] += freq[y];
            }
        }

        // Required by the statement
        auto zenquarilo = items;

        vector<long long> deg(n);
        unordered_map<long long, long long> priceCnt;

        long long M = 0; // total number of value-2 units

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            long long price = items[i][1];

            deg[i] = multCnt[factor] - 1;
            M += deg[i];

            if (deg[i] > 0) {
                priceCnt[price] += deg[i];
            }
        }

        vector<pair<long long,long long>> v;
        v.reserve(priceCnt.size());

        for (auto &p : priceCnt) {
            v.push_back(p);
        }

        sort(v.begin(), v.end());

        int m = (int)v.size();

        vector<long long> prefCnt(m + 1, 0);
        vector<long long> prefCost(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefCnt[i + 1] = prefCnt[i] + v[i].second;
            prefCost[i + 1] = prefCost[i] + v[i].first * v[i].second;
        }

        auto cost2 = [&](long long x) -> long long {
            if (x < 0) return (long long)4e18;
            if (x == 0) return 0;
            if (x > M) return (long long)4e18;

            int pos = lower_bound(prefCnt.begin(), prefCnt.end(), x) - prefCnt.begin();

            long long takenBefore = prefCnt[pos - 1];
            long long ans = prefCost[pos - 1];

            ans += (x - takenBefore) * v[pos - 1].first;
            return ans;
        };

        long long threshold = 2 * minPrice;

        long long beneficialCnt = 0;
        long long beneficialSaving = 0;

        for (auto &p : v) {
            long long price = p.first;
            long long cnt = p.second;

            if (price < threshold) {
                beneficialCnt += cnt;
                beneficialSaving += (threshold - price) * cnt;
            } else {
                break;
            }
        }

        auto savingBest = [&](long long x) -> long long {
            if (x <= 0) return 0;

            long long limit = min(x, beneficialCnt);

            int pos = lower_bound(prefCnt.begin(), prefCnt.end(), limit) - prefCnt.begin();

            long long takenBefore = prefCnt[pos - 1];
            long long costChosen = prefCost[pos - 1];
            costChosen += (limit - takenBefore) * v[pos - 1].first;

            return threshold * limit - costChosen;
        };

        auto minCostForValue = [&](long long T) -> long long {
            long long ans = (long long)4e18;

            long long x1 = min(T / 2, beneficialCnt);
            ans = min(ans, T * minPrice - savingBest(x1));

            long long need2 = (T + 1) / 2;
            if (need2 <= M) {
                ans = min(ans, cost2(need2));
            }

            return ans;
        };

        long long low = 0;
        long long high = (long long)budget / minPrice + M;

        while (low < high) {
            long long mid = (low + high + 1) / 2;

            if (minCostForValue(mid) <= budget) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return (int)low;
    }
};