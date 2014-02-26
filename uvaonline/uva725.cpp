#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
  int N;
  int first_time = 1;
  while(scanf("%d", &N), N){
    if(!first_time){
      printf("\n");
    }
    first_time = 0;
    int abcde, fghij, tmp, used;
    used = 0;
    int count = 0;
    vector<pair<int, int> > result;
    for(fghij= 1234; fghij <=98765/N; fghij++){
      abcde = fghij*N;
      used = (fghij < 10000);
      tmp = abcde; while(tmp){ used |= 1 << (tmp % 10); tmp/=10;}
      tmp = fghij; while(tmp){ used |= 1 << (tmp % 10); tmp/=10;}
      if (used == ((1 << 10)-1)){
	result.push_back(make_pair(abcde, fghij));
	count ++;
      }
    }
    if (count == 0){
      printf("There are no solutions for %d.\n", N);
    } else {
      sort(result.begin(), result.end());
      for(int i=0 ; i < result.size(); i++){
	printf("%.5d / %.5d = %d\n", result[i].first, result[i].second, N);
      }
    }
  }
  
  return 0;
}
