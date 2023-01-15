//
// Created by Dmitry Morozov on 15/1/23.
//
#include <iostream>
#include <vector>


class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>> &boxTypes, int truckSize) {

        std::sort(boxTypes.begin(), boxTypes.end(), [](auto &lhs, auto &rhs) {
            return lhs[1] > rhs[1];
        });

        int total{0};

        for (auto &item: boxTypes) {

            int nItems = std::min(truckSize, item[0]);
            total += nItems * item[1];

            truckSize -= nItems;
        }

        return total;

    }
};

//int main() {
//
//    std::vector<std::vector<int>> demo = {{1, 3},
//                                          {2, 2},
//                                          {3, 1}};
//
//    int sz = 4;
//
//    Solution s;
//    std::cout  << s.maximumUnits(demo, sz) << std::endl;
//
//
//    return 0;
//}