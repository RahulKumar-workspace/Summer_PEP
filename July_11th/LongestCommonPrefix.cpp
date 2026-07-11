#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{	
	public:
		string longestCommonPrefix(vector<string>& str){
            if (str.empty()) return "";

			sort(str.begin(), str.end());

            string first = str[0];
            string last = str[str.size()-1];

            int i = 0, j = 0;
            string ans = "";

            while(i < first.size() && j < last.size()){
                if(first[i] != last[j]) break;

                ans += first[i];
                i++;
                j++;
            }
            return ans;
		}
};

int main() {
    Solution solution;
    vector<string> input = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(input);
    cout << "Longest Common Prefix: " << result << endl; // Output: "fl"
    return 0;
}