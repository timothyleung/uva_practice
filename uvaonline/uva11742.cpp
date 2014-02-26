#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main(){
  int n, m, a, b,c;
  bool first = true;
  while(scanf("%d %d", &n, &m), m||n){
    first = false;
    // create an array from 0..n-1
    int arr[n];
    for(int i=0; i < n; i++) arr[i]=i;
    vector<iii> constraints;
    for(int i=0; i < m; i++){
      scanf("%d %d %d", &a, &b, &c);
      constraints.push_back(make_pair(make_pair(a,b),c));
    }
    int count = 0;
    do{
      // check constraints
      bool valid = true;
      for(int i=0; i<m; i++){
	iii temp = constraints[i];
	if(temp.second < 0){
	  valid = abs(arr[temp.first.second]-arr[temp.first.first]) >= abs(temp.second);
	} else {
	  valid = abs(arr[temp.first.second]-arr[temp.first.first]) <= temp.second;
	}
	if(!valid){
	  break;
	}
      } 

      if(valid){
	count ++;
      }
    }while(next_permutation(arr, arr+n));
    printf("%d\n", count);
  }
}
