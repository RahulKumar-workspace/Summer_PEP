#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // return 1 if == m.
    // return 0 if < m.
    // return 2 if > m.
    int Power(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans = ans * mid;

            if (ans > m) return 2;
        }

        if (ans == m) return 1;
        return 0;
    }

    int NthRoot(int N, int M) {
        int low = 1;
        int high = M;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midN = Power(mid, N, M);

            if (midN == 1)
                return mid;
            else if (midN == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};

int main() {
    int n = 4, m = 81;
    
    Solution sol;
    
    int ans = sol.NthRoot(n, m);
    
    // Print the result
    cout << "The answer is: " << ans << "\n";
    
    return 0;
}
