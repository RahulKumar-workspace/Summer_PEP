#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    // Function to find the majority element in an array
    int majorityElement(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size();
        
        // Hash map to store element counts
        unordered_map<int, int> mp;
        
        // Count occurrences of each element
        for (int num : nums) {
            mp[num]++;
        }
        
        /* Iterate through the map to
        find the majority element*/
        for (auto& pair : mp) {
            if (pair.second > n / 2) {
                return pair.first;
            }
        }
        
        // Return -1 if no majority element is found
        return -1;
    }

    
    
};

    


int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    
    // Create an instance of Solution class
    Solution sol;

    int ans = sol.majorityElement(arr);
    
    // Print the majority element found
    cout << "The majority element is: " << ans << endl;
    
    return 0;
}
