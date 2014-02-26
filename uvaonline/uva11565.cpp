#include <iostream>

using namespace std;

#define limit 10000

int main(){
  int n,x,y,z,A,B,C, count;
  scanf("%d", &n);
  while(n--){
    count = 0;
    scanf("%d %d %d", &A, &B, &C);
    for(int x=-100; x <= 100&&count==0; x++){
      for(int y=-100; y<= 100&&count==0; y++){
	for(int z=-100; z<=100 && count==0; z++){
	  if(x!=y && y!=z && x!=z){
	    if((x*x + y*y + z * z) == C){
	      if((x*y*z)==B){
		if((x+y+z)==A){
		  printf("%d %d %d\n", x, y, z);
		  count++;
		}
	      }
	    }
	  }
	}
      }
    }
    if(count==0){
      printf("No solution.\n");
    }
  }
}
