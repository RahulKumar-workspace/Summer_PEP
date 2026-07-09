#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &arr, int k) {
       int low = 0;
       int high = arr.size()-1;

       while(low <= high){
            int mid = (low+high)/2;

            if(arr[mid] == k) return mid;

            if(arr[low] <= arr[mid]){
                if(arr[low] <= k && k <= arr[mid]){
                    high = mid-1;
                }else
                    low = mid+1;
            }
            else{
                if(arr[mid] <= k && k <= arr[high]){
                    low = mid+1;
                }else
                    high = mid-1;
            }
       }
       return -1;
    }
};

int main() {
    vector<int> nums = {39,45,48,52,74,-82,-81,-77,-74,-70,-46,-37,-29,-28,-15,15,19,27,33};
    int target = 52; //expected = 3

    // Create an instance of the Solution class
    Solution sol;

    int result = sol.search(nums, target);

    if (result == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << result << "\n";

    return 0;
}