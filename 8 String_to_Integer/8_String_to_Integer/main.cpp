//
//  main.cpp
//  8_String_to_Integer
//
//  Created by David Zhong on 2015-12-11.
//  Copyright © 2015 David Zhong. All rights reserve.
//

/*
 Implement atoi to convert a string to an integer.
 
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 
 
 Requirements for atoi:
 The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 
 The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 
 If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 
 If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of represultentable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int myAtoi(string str) {

    //pass the initial space
    int i = 0;
    unsigned long long result = 0;
    while (str[i] == ' ')i++;
    
    //parse the first non space char
    if (str[i] != '+' && str[i] != '-' && isdigit(str[i]) == 0)return 0;
    bool neg = false;
    if (str[i] == '+') { neg = false; i++; }
    else if (str[i] == '-') { neg = true; i++; }
    else neg = false;
    //parse the char followered by + -
    if (isdigit(str[i]) == 0)return 0;
    else {
        while (isdigit(str[i])){
            result = result * 10 + str[i] - '0';
            if (result>INT_MAX)return neg ? INT_MIN : INT_MAX;
            i++;
        }
    }
    return neg ? -result : result;
}

int main(int argc, const char * argv[]) {
    
    string str("    -3432234   ");
    cout << myAtoi(str) << endl;
   
    return 0;
}
