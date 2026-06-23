class Solution {
public:
    int requiredStations(vector<int>& stations, long double dist) {
        int cnt = 0;

        for (int i = 0; i < stations.size() - 1; i++) {
            long double gap = stations[i + 1] - stations[i];

            int stationsNeeded = gap / dist;

            if ((long double)stationsNeeded * dist == gap)
                stationsNeeded--;

            cnt += stationsNeeded;
        }

        return cnt;
    }

    double minMaxDist(vector<int> &stations, int k) {
        long double low = 0;
        long double high = 0;

        for (int i = 0; i < stations.size() - 1; i++) {
            high = max(high,
                       (long double)(stations[i + 1] - stations[i]));
        }

        while (high - low > 1e-6) {
            long double mid = (low + high) / 2.0;

            if (requiredStations(stations, mid) > k)
                low = mid;
            else
                high = mid;
        }

        return (double)high;
    }
};