#include <bits/stdc++.h>
using namespace std;
//leet num 29
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        long long result = 0;
        long long a = abs((long long)dividend);  
        long long b = abs((long long)divisor);
        bool negative = ((dividend<0)^(divisor<0)); 
        
        //forexample if we eventually land on 0 => that means value is non negative for MSB
        //and if 0 xor 0 = 0 and 1 1 = 0 so likely xor works perfectly here 
        
        for (int i = 31; i>=0; i--) {
        //with i = 31 so like, 2^31 is the max value for both sides negative and positive, a bit off for the positive but work

            long long shifted_value = b << i; //2^i * b
            if (a - shifted_value < 0) continue;
            a = a - shifted_value;
            

            result += (1LL << i); //LL : long long helps expand the bits no overflow if divisor ever be 2^31 
            
            

        }    
        
        

        

        return negative ? -result : result;
    }
};

int main() {
    Solution sol;
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;
    cout << dividend << " / " << divisor << " = " << sol.divide(dividend, divisor) << endl;
    return 0;
}
