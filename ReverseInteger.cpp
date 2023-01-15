//
// Created by Dmitry Morozov on 15/1/23.
//

#include <iostream>

class Solution {
public:

    int reverse(int x) {

        long result_number = 0;

        while (x) {
            result_number = result_number * 10 + x % 10;
            x /= 10;
        }

        if (result_number < INT_MIN || result_number > INT_MAX) {
            return 0;
        }

        return static_cast<int>(result_number);
    }


};

//int main() {
//    Solution s;
//    std::cout << s.reverse ( 123 ) << std::endl;
//}