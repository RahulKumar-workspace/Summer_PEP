#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int> &arr, int k)  {
      int low = 0;
      int high = arr.size()-1;

      while(low <= high){
        int mid = low+(high-low)/2;

        if(arr[mid] == k) return true;

        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }

        if(arr[low] <= arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high = mid-1;
            }else low = mid+1;
        }
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low = mid+1;
            }else high = mid-1;
        }
      }
      return false;
    }
};

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3; 

    // Create an instance of the Solution class
    Solution sol;

    bool result = sol.searchInARotatedSortedArrayII(arr, target);

    if (!result)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}