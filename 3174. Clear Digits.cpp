/*
You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.
Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
    
            for (int i = 0; i < s.size(); i++) {
                if (!isdigit(s[i])) {
                    st.push(s[i]);
                }
                else if (isdigit(s[i]) && !st.empty()) {
                    st.pop();
                }
            }
    
            string answer;
            while(!st.empty()) {
                answer = st.top() + answer;
                st.pop();
            }
            return answer;
        }
    };