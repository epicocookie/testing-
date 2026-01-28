#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";
        for (auto &a : roman) {
            int val = a.first;
            string letter = a.second;
            int count = num / val; 
            while (count--) result+=a.second; 
            num = num%val;
        }

        

        return result;
    }
};

int main() {
    Solution sol;
    int num;
    cin >> num;
    cout << sol.intToRoman(num) << endl;
    return 0;
}
