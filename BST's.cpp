// main.cpp
// Number of BST given n nodes
// This program gives the number of possibles
// BST that can be formed given n Nodes using
// Dynamic Programming
// Leetcode Problem:
// https://leetcode.com/problems/unique-binary-search-trees/
//  Created by Alex Vasquez on 4/22/20.
//  Copyright © 2020 Alex Vasquez. All rights reserved.
//
#include <iostream>
#include <climits>
using namespace std;

#define MAX 100
/*////////////////////////////////////////////////
// calc
//
// The function creates a 2d Array that stores the
// number of BST's that can be formed depending on
// the values of i and j, meaning, if 5 trees can
// be formed for n = 3 then the array will store
// the value of 5 on the cells where j - i = 2
// For example [1][3] and [2][4] will be storing 5
//
// Parameters:
// n = number of nodes
// D[][] = array that will store the values
//
// Return:
// Number of BST's given n nodes
/////////////////////////////////////////////////
*/
int calc(int n, int D[MAX][MAX]){
    int j, ans;
    for (int i = 1; i<=n+1; i++){
        // [i][i] = 1 because only one tree can be formed when n = 1
        D[i][i] = 1;
        D[i][i-1] = 1;
        // The matrix will be traverse diagonally
        for (int diag=1; diag<=n; diag++){
            for (int i = 1; i<=(n+1)-diag; i++){
                j = i + diag;
                ans = 0;
                for (int k = i; k<=j; k++){
                    // This formula allows us to calculate the number of
                    // BST's given i and j
                    ans += (D[i][k-1]*D[k+1][j]);
                }
                D[i][j] = ans;
            }
        }
    }
    // Value with the number of BST's for n nodes
    return D[1][n];
}

/*
////////////////////////////////////////////////
// numTrees
//
// The function will only call the previous
// function to get the result
//
// Parameters:
// n = number of nodes
//
// Return:
// Result (Number of BST's)
///////////////////////////////////////////////
*/
int numTrees(int n) {
    int D[MAX][MAX];
    return calc(n,D);
   }

int main(){
    int n;
    cin >> n;
    
    cout << numTrees(n) << endl;
}

