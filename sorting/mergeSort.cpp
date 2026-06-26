#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& a, int& low, int& mid, int& high){
  int pointer = low;
  int p1 = 0;
  int p2 = 0;
  vector<int>L;
  vector<int>R;
  for(int i=low; i<=mid; ++i){
    L.push_back(a[i]);
  }
  for(int i=mid+1; i<=high; ++i){
    R.push_back(a[i]);    
  }
  int n1 = L.size()-1;
  int n2 = R.size()-1;
  while(p1<=n1 && p2<=n2){
    if(L[p1] <= R[p2]){
      a[pointer] = L[p1];
      ++pointer;
      ++p1;
    }else{
      a[pointer] = R[p2];
      ++p2;
      ++pointer;
    }
  }
  while(p1<=n1){
    a[pointer] = L[p1]; ++p1; ++pointer;
  }
  while(p2<=n2){
    a[pointer] = R[p2]; ++p2; ++pointer;
  }
}

void mergeSort(vector<int>& a, int& low, int& high){
  if(low==high)return; //base condition
  int mid = (low+high)/2;
  mergeSort(a,low,mid);
  int mid2 = mid+1;
  mergeSort(a,mid2,high);
  merge(a,low,mid,high);
}

int main(){
  int n; cin >> n;
  vector<int> a;
  for(int i=0; i<n; ++i){
    int x; cin >> x;
    a.push_back(x);
  }
  cout << "The unsorted array is : ";
  for(auto el : a){
    cout << el << " ";
  }
  int low = 0;
  int high= n-1;
  mergeSort(a,low,high);

  cout << "After Sorting : ";
  for(auto el : a){
      cout << el << " ";
    }
}
