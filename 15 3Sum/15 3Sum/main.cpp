//
//  main.cpp
//  15 3Sum
//
//  Created by David Zhong on 2015-12-13.
//  Copyright © 2015 David Zhong. All rights reserved.
//

/*
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)
 
 Hints: array, two pointers
 */

/*
 Solution:
 Any three number sum up to be zero. Find them all.
 
 steps:
 1: Sort
 2: First two smaller number add up, if sum < 0, the fist number increment. 
                                     If sum > 0, the last number decrement.
 3: Continue the process in the loop till finish
 */

// Debug needed

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    sort(nums.begin(), nums.end());
    
    vector<int> tmp(3); // Vector size 3
    vector<vector<int>> rs;
    int i=0, j=0, k=nums.size()-1;
    
    for (i = 0; i < nums.size()-1 ; j < k)
    {
        for (int j = i+1; j < k; )
        {
            if(nums[i]+nums[j]+nums[k] < 0) j++;
            else if (nums[i]+nums[j]+nums[k] > 0) k--;
            else
            {
                tmp[0] = nums[i];
                tmp[1] = nums[j];
                tmp[2] = nums[k];
                rs.push_back(tmp);
                j++, k--;
                while (j<k && nums[j] == nums[j-1]) j++;
                while (j<k && nums[k] == nums[k+1]) k--;
            }
        }
        while (i<nums.size() && nums[i] == nums[i+1]) i++;
    }
    return rs;
}

// Similar solution

vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;
    
    std::sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;
        
        while (front < back) {
            
            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;
            
            else if (sum > target)
                back--;
            
            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;
                
                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) rear--;
            }
            
        }
        
        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;
        
    }
    
    return res;
    
}


int main(int argc, const char * argv[]) {

    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > result = threeSum(vec);
    
    for (auto x:result)
    {
        cout<<"(";
        for (auto y:x)
            cout<<y<<"\t";
        cout<<")"<<endl;
    }
    
    return 0;
}
