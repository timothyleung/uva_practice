#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define VISITED 1
#define UNVISITED 0

using namespace std;

typedef pair<int, int> ii; // int pair
typedef vector<ii> vii; // 
typedef vector<int> vi;



vi dfs_num;
vi dfs_num2;
vector<vii> adjList;
int size;

void dfs(int u, int pass){
	if(u==pass)
		return;
	dfs_num[u] = VISITED;
	for(int j=0; j < adjList[u].size(); j++){
		int node = adjList[u][j].first;
		if (dfs_num[node] == UNVISITED) {
			dfs(node, pass);		
		}
		
	}
}



int main(){
	int c;
	scanf("%d", &c);
	for(int p=1; p <=c ; p++) {
		printf("Case %d:\n", p);
		scanf("%d", &size);
		adjList.clear(); // remove all the elem in adjList
		for(int i=0; i < size; i++){
			vii temp ;
			adjList.push_back(temp);
		}
		for(int i=0; i < size; i++){
			for(int j=0; j < size; j++){
				int temp;
				scanf("%d", &temp);
				if(temp!=0)	
					adjList[i].push_back(make_pair(j, 1));
			}
		}
		// adjList initialized 
		for(int i=0;i<size;i++){
			dfs_num.push_back(UNVISITED);
			dfs_num2.push_back(UNVISITED);
		}		
		// dfs_num initialized
		dfs(0, -1); // run and find all the connected node from 0 
		
		for(int i=0; i < size; i++){
			dfs_num2[i] = dfs_num[i]; // dfs_num2 is a reference and will not be changed 
		}
		// here comes the result 
		// double loop and check one by one
		printf("+");
		for( int i=0; i < (size*2)-1; i++){
			printf("-");
		}
		printf("+\n");
		for(int i=0; i < size; i++ ){
			printf("|");
			for(int j=0; j < size; j++){
				// check if dfs_enum[j] is VISITED or not 
				for(int i=0; i< size; i++){
					dfs_num[i] = UNVISITED; // init it again 
				}
				if(dfs_num2[j] == VISITED) {
					// block outgoing from j, run dfs on i
					dfs(0, i); 
					// check if VISITED or not
					// compare dfs_num and dfs_num2 
						if(dfs_num2[j]==VISITED && dfs_num[j] == UNVISITED){
							// then i is a dominator of v.first
							printf("Y|");
						} else {
							// i is not a dominator
							printf("N|");
						}
					
				} else {
					printf("N|");
				}
			}
			printf("\n");
		printf("+");
		for( int i=0; i < (size*2)-1; i++){
			printf("-");
		}
		printf("+\n");
		}	
		dfs_num.clear();
		dfs_num2.clear();	
	}		
	return 0;
}
