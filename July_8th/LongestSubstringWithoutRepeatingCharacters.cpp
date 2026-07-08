#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNonRepeatingSubstring(string &s) {
        
        // Length of the input string
        int n = s.size(); 
        
        //Variable to store max length
        int maxLen = 0;    
        
        /* Iterate through all possible 
        starting points of the substring*/
        for (int i = 0; i < n; i++) {
            
            /* Hash to track characters in 
            the current substring window*/
            // Assuming extended ASCII characters
            vector<int> hash(256, 0);  
            
            for (int j = i; j < n; j++) {
                
                /* If s[j] is already in the
                current substring window*/
                if (hash[s[j]] == 1) break;  
                
                /* Update the hash to mark s[j]
                as present in the current window*/
                hash[s[j]] = 1;
                
                /* Calculate the length of
                the current substring*/
                int len = j - i + 1;
                
                /* Update maxLen if the current
                substring length is greater*/
                maxLen = max(maxLen, len);
            }
        }
        
        // Return the maximum length
        return maxLen; 
    }
};

int main() {
    string input = "cadbzabcd";
    
    //Create an instance of Solution class
    Solution sol;
    
    int length = sol.longestNonRepeatingSubstring(input);
    
    //Print the result
    cout << "Length of longest substring without repeating characters: " << length << endl;
    
    return 0;
}
