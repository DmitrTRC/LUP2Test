//
// Created by Dmitry Morozov on 15/1/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int> &nums, int k) {

        int count = 0;
        int sum = 0;

        std::unordered_map<int, int> s_table;
        s_table[0] = 1;

        for (int num : nums) {
            sum += num;

            if (s_table.count(sum - k)) {
                count += s_table[sum - k];

            }

            ++s_table[sum];

        }

        return count;
    }

};

//int main() {
//
//    std::vector<int> nums1{ 1, 1, 1};
//
//    int k1 = 2;
//
//    Solution s;
//
//    std::cout << s.subarraySum(nums1, k1) << std::endl;
//
//
//}