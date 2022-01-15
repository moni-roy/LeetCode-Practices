class Solution {
public:
    int preimageSizeFZF(int k) {
        return binarySearch(k);
    }
private:
    unordered_map<long long, long long> mp;
    int binarySearch(long long k) {
        long long int l = k, r = 5LL*(k+1);
        while (l < r) {
            long long m = l + (r - l) / 2;
            long long tz = mp.find(m) != mp.end() ? mp[m] : f(m);
            if(tz == k) return 5;
            else if (tz < k) l = m + 1;
            else r = m;
        }
        return 0;
    }
    long long f(long long x) {
        if(x == 0) return 0;
        if(mp.find(x) != mp.end()) return mp[x];
        return mp[x] = x/5 + f(x/5);
    }
};