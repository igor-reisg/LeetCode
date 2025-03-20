/*
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxDepth(string s) {
            stack<char> st;
            int qtd = 0, qtdmax = 0;
    
            for (int i = 0; i < s.size(); i++) {
                if(s[i] == '(') {
                    st.push(s[i]);
                    qtd++;
                }
                else if (s[i] == ')') {
                    qtdmax = max(qtd, qtdmax);
                    st.pop();
                    qtd--;
                }
            }
            return qtdmax;
        }
    };