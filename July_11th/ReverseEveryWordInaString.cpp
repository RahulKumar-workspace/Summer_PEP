#include <iostream>
#include <vector>
using namespace std;

// class Solution {
//    public:
//     string reverseWords(string s) {
//         int n = s.size();
//         int leng = 0;
//         int i = 0;
//         vector<string> words;

//         while (i < n) {
//             while (i < n && s[i] == ' ') {  // iterate will we find any character.
//                 i++;
//             };
//             if (i == n)
//                 break;  //(end of string) -> if we don't write this then the
//                         // next loop will run andwe'll get an extra space in our
//                         // array.

//             int start = i;  // start index of a word

//             while (i < n && s[i] != ' ') {
//                 i++;
//                 leng++;  // length of the word
//             }

//             words.push_back(s.substr(start, leng));  // or we can do 'i-start' instead of 'leng' as that will also tell the length of the word.
//             leng = 0;           // reinitialize length to 0. For the next word.
//         }

//         string result = "";
//         for (int i = words.size() - 1; i >= 0; i--) {
//             result += words[i];  // add each word to resultant string.

//             if (i > 0) {
//                 result += " ";  // add spaces between them except for the end of string'
//             }
//         }

//         return result;
//     }
// };

class Solution {
public:
    void reverseString(string& s, int start, int end){
        while(start < end){
            swap(s[start++], s[end--]);
        }
    }

    string reverseWords(string s) {
       int i=0, j=0, n = s.length(), end=0, start = 0;
        reverseString(s, 0, n-1);

       while(j < n){
            while(j < n && s[j] == ' ') j++;
            if(j == n) break;

            start = i;
            while(j < n && s[j] != ' '){
                s[i] = s[j];
                i++;
                j++;
            }
            end = i-1;

            reverseString(s,start, end);
            if(j<n) s[i++] = ' ';
       }

        if(i>0 && s[i-1] == ' ') i--;
        return s.substr(0, i);
    } 
};

int main(){
    string s =  " amazing coding skills ";
    
    // Creating an instance of Solution class
    Solution sol; 
    
    // Function call to reverse every word in the given string
    string ans = sol.reverseWords(s);
    
    // Output
    cout << "Input string: " << s << endl;
    cout << "After reversing every word: " << ans << endl;
}