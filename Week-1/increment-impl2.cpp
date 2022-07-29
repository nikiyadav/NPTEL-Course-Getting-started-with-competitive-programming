/***
Problem statement:
You have a collection of n balls. Each one has an integer written on it. 
You also have a magic bag called the incrementor - when you put a ball inside the incrementor and pull it out, the integer written on it increases by one.
The magic bag is big enough to hold any number of balls at once. However, it costs one rupee to use it once.
You want all your balls to have the same number on them. Your task is to figure out what is the minimum cost of making this happen using the magic bag.

Input
The first line of the input contains a single integer t(1≤t≤10^4)
 - the number of test cases in the test.

The following are descriptions of the input test cases.
The first line of the description of each test case contains one integer n(1≤n≤50)
 — the number of balls in your collection.
The second line of the description of each test case contains n
 integers — a1,a2,…,an(1≤ai≤10^9) the numbers on the balls, in an arbitrary order.


Output
For each test case, print one integer — the minimum cost way to use the magic bag to make the numbers on all the balls the same.


Example

Input

3
6
4 4 4 4 4 4
4
1000 1000 1000 1001
2
12 10

Output

0
1
2
***/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; // number of test cases
	cin >> t;
	int n,e;
	while (t--) {
	    cin >> n;
        int min=INT_MAX, max=INT_MIN;
	    for(int i=0;i<n;i++) {
	        cin >> e;  
            if (e < min) min = e;
            if ( e > max) max = e;
	    }
        cout << "\n" << max-min;
    }
    return 0;
}