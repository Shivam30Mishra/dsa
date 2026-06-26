#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int SearchRow(vector<vector<int>>& matrix, int target){
        int low = 0;
        int high= matrix.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1]){
                return mid;
            }else if(target < matrix[mid][0]) high = mid -1;
            else low = mid + 1;
        }
        return -1;
    }
    int  binarySearch(vector<vector<int>>& matrix, int target, int row){
        int low = 0;
        int high= matrix[matrix.size()-1].size() - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[row][mid] < target){
                low = mid + 1;
            }else if(matrix[row][mid] > target){
                high= mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = SearchRow(matrix,target);
        int col = -1;
        if(row > -1){
            col = binarySearch(matrix,target,row);
            if(col > -1) return true;
        }
        return false;
    }
};