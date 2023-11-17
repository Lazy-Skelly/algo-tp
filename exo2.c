#include <stdio.h>
#include <stdlib.h>

int** Funky(int** mat,int n, int m){
	for(int i=0;i<n*m-1;i++){
		int j =i;
		while(j>=0 && mat[(j+1)/m][(j+1)%m] <mat[j/m][j%m]){
			int temp;
			temp = mat[(j+1)/m][(j+1)%m];
			mat[(j+1)/m][(j+1)%m] = mat[j/m][j%m];
			mat[j/m][j%m] = temp;
			j--;
		}
	}
	
	return mat;
}

void main(){
	int n,m;
	int** mat;
	scanf("%d",&n);
	scanf("%d",&m);
	
	mat = (int**) malloc((n)*sizeof(int*));	
	for(int j =0;j<m;j++){				
			 mat[j] = (int *) malloc((m)*sizeof(int));				
	}
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){				
			scanf("%d",&mat[i][j]);				
		}
	}
	
	int** matrix = Funky(mat,n,m);
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){				
			printf("%d ",matrix[i][j]);				
		}
		printf("\n");
	}
}
