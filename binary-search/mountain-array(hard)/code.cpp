/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int peakElement(MountainArray &mountainArr, int &n){
        int low = 0;
        int high = n - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(mountainArr.get(mid) > mountainArr.get(mid + 1)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }

    int binarySearch(MountainArray &mountainArr, int low, int high, int target, bool asc){

        while(low <= high){

            int mid = low + (high - low) / 2;
            int ele = mountainArr.get(mid);

            if(ele == target)
                return mid;

            if(asc){
                if(ele < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else{
                if(ele < target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();

        int peak = peakElement(mountainArr, n);

        int left = binarySearch(mountainArr, 0, peak, target, true);

        if(left != -1)
            return left;

        return binarySearch(mountainArr, peak + 1, n - 1, target, false);
    }
};