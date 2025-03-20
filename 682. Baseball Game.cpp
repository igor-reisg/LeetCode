/*
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x: Record a new score of x.
'+': Record a new score that is the sum of the previous two scores.
'D': Record a new score that is the double of the previous score.
'C': Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying all the operations.
The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;

        for (string c : operations) {
            if (c == "C" && !st.empty()) {
                sum -= st.top();
                st.pop(); 
            }
            else if (c == "D" && !st.empty()) {
                int top = st.top();
                st.push(top * 2);
                sum += top * 2;
            }
            else if (c == "+" && st.size() >= 2) {
                int top = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top);
                st.push(top + top2);
                sum += top + top2;
            }
            else {
                int num = stoi(c);
                st.push(num);
                sum += num;
            }
        }
        return sum;
    }
};