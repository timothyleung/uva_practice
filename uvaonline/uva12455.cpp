#include <iostream>

using namespace std;

int main(){
  int t,n,p,sum;
  bool success;
  scanf("%d", &t);
  while(t--){
    success = false;
    scanf("%d", &n);
    scanf("%d", &p);
    int arr[p];
    for(int i=0; i < p ; i++){
      scanf("%d", &arr[i]);
    }

    for(int i=0; i < (1<<p);i++){
      sum = 0;
      for(int j=0 ; j < p; j++){
	if(i & (1 << j)){
	  sum += arr[j];
	}
      }
      if(sum == n){
	success = true;
	break;
      }
    }
    if(success){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}
