/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vet;

        for (int i = 0; i < nums.size(); i++) {
            vet.push_back({nums[i], i});
        }
        
        sort(vet.begin(), vet.end());
        
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int sum = vet[right].first + vet[left].first;

            if (sum > target) {
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else
                return {vet[left].second, vet[right].second};
        }
        return {};
    }
};