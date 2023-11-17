#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* strninsert(char* S1,char* S2, int k, int i){
	char *out = (char *) malloc((strlen(S1)+strlen(S2))*sizeof(char));
	
	strncpy(out,S1,k-1);
	strncat(out,S2,i);
	strncat(out,S1+k-1,strlen(S1)-k+1);

	
	return out;
}


char* strndel(char* S1, int k, int i){
	char *out = (char *) malloc((strlen(S1)-i)*sizeof(char));

	memmove(out,S1,k-1);
	memmove(out+k-1,&S1[k+i-1],strlen(S1));


	return out;
}

char* replace(char *orig, char *rep, char *with){
	char* temp;
	char* ans; 
	char* result;
	int len_with = strlen(with);
	int len_rep = strlen(rep);
	int len_org = strlen(orig);
	int count = 0;
	temp = orig;
	
	temp = strstr(temp, rep);
	while(temp){
		count++;
		temp += len_rep;
		temp = strstr(temp, rep);
	}

	
	temp = orig;
	result = ans = malloc(len_org+ (len_with-len_rep)*count+1);
	while(count--){
		temp = strstr(orig, rep);
		int before = temp - orig;
		ans = strncpy(ans, orig, before) +before;
		ans = strncpy(ans, with, len_with) +len_with;
		orig +=	 before + len_rep;		
	}
	strcpy(ans, orig);
	
	return result;
}


int main(){
char S1[25]= "fmbctimb";
char S2[25]  = "on";
char S4[25] = "mb";

printf("%s",strninsert(S1,S2,4,6));
printf("\n%s",strndel(S1,4,2));
printf("\n%s",replace(S1,S4,S2));

return 0;
}
