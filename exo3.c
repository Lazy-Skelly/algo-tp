#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	
	char test[256];
	scanf("%[^\n]s",test);
	printf("{");
	for(int i=0;i<strlen(test);i++){
		for(int j = 0;j<=i;j++){
			printf("%c",test[j]);	
		}
		printf(",");		
	}
	printf("}\n{");
	for(int i=0;i<strlen(test);i++){
		for(int j = strlen(test)-i;j<=strlen(test);j++){
			printf("%c",test[j-1]);	
		}
		printf(",");
	}
	printf("}");
}
