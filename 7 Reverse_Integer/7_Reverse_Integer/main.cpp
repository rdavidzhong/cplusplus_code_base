//
//  main.cpp
//  7_Reverse_Integer
//
//  Created by David Zhong on 2015-12-09.
//  Copyright © 2015 David Zhong. All rights reserved.
//

/*
 Reverse digits of an integer.
 
 Example1: x = 123, return 321
 Example2: x = -123, return -321
 
 click to show spoilers.
 
 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 
 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 
 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 
 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 
 Update (2014-11-10):
 Test cases had been added to test the overflow behavior.

 Hide Tags Math
 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int reverse(int x)
{
 
    int result = 0, remainder = 0;
    while(x != 0)
    {
        result = result*10;
        remainder = x%10;
        result = result + remainder;
        x = x/10;
    }
    return result;
}

int main(int argc, const char * argv[]) {

   
    int test1 = -123;
    int test2 = 123;
    cout << reverse(test1) << endl;
    cout << reverse(test2) << endl;
    
    return 0;
}
