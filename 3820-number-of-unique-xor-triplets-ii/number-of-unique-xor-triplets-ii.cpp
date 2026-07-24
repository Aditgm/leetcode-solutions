#include <vector>

using namespace std;

#define ll long long
#define vi vector<int>

class Solution {
public:
    void fwht(vector<ll>& a, bool invert) {
        int n = a.size();

        for (int len = 1; 2 * len <= n; len <<= 1) {
            for (int i = 0; i < n; i += 2 * len) {
                for (int j = 0; j < len; j++) {
                    ll u = a[i + j];
                    ll v = a[i + len + j];

                    a[i + j] = u + v;
                    a[i + len + j] = u - v;
                }
            }
        }

        if (invert) {
            for (int i = 0; i < n; i++) {
                a[i] /= n;
            }
        }
    }

    int uniqueXorTriplets(vi& nums) {
        int N = 2048;
        vector<ll> freq(N, 0);

        for (int x : nums) {
            freq[x] = 1;
        }

        fwht(freq, false);

        for (int i = 0; i < N; i++) {
            freq[i] = freq[i] * freq[i] * freq[i];
        }

        fwht(freq, true);

        int unique_triplets_count = 0;
        for (int i = 0; i < N; i++) {
            if (freq[i] > 0) {
                unique_triplets_count++;
            }
        }

        return unique_triplets_count;
    }
};