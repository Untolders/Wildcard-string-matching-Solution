**********************************************************************************  Question  ********************************************************************************************************************
Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not. * and ? can be converted to another character according to the following rules:

* --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
? --> This character in string wild can be replaced by any one character.
Example 1:

Input: 
wild = ge*ks
pattern = geeks
Output: Yes
Explanation: Replace the '*' in wild string 
with 'e' to obtain pattern "geeks".
Example 2:

Input: 
wild = ge?ks*
pattern = geeksforgeeks
Output: Yes
Explanation: Replace '?' and '*' in wild string with
'e' and 'forgeeks' respectively to obtain pattern 
"geeksforgeeks"
Your Task:
You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

Expected Time Complexity: O(length of wild string * length of pattern string)
Expected Auxiliary Space: O(length of wild string * length of pattern string)

Constraints:
1 <= length of the two string <= 10^3 




***********************************************************************************  Solution  *******************************************************************************************************************
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
     private:
    bool solve(string& pattern, string& wild, int i, int j) {
        // base case
        // if we cross the 0th index of both pattern and wild, means string matched
        if(i<0 and j<0)
            return true;
        // if we have left charachter in pattern but we there is no charachter is left in wild
        if(i >= 0 and j < 0)
            return false;
        // if we have left charachter in wild but there is no char in pattern to match
        // their is a possibility that left char are * and we can replace it with empty, so we return tur
        // other wise return false
        if(i < 0 and j >= 0) {
            for(int k=0; k<=j; k++){
                if(wild[k] != '*')
                    return false;
            }
            return true;
        }
        
        // match case
        // if both index i and j are matched to the same char
        if(pattern[i] == wild[j] || wild[j] == '?') {
            return solve(pattern, wild, i-1, j-1);
        }
        else if(wild[j] == '*') {
            return (solve(pattern, wild, i-1, j) || solve(pattern, wild, i, j-1));
        }
        else 
            return false;
    }

    public:
    bool match(string wild, string pattern)
    {
        // code here
        int i = pattern.length()-1;
        int j = wild.length()-1;
        
        return solve(pattern, wild, i, j);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends

