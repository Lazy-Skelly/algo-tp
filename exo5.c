#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int value;
	struct cell* next;

}cell;

void Add(cell* head, int value){
	while(head->next ){
		head = head->next;
	}
	head->next = (cell*)malloc(sizeof(cell));
	head->next->next = NULL;
	head->next->value = value;
}

cell* Create(int num, int size){
	if( size > 0){
	cell* a;
	a =  (cell*)malloc(sizeof(cell));
	a->value = num;
	a->next = NULL;	
	
	for(int i = 2;i<=size;i++){
		Add(a,num*i);
	}
	return a;
	}
	return NULL;
}

void Show(cell* head){
	while(head){
		printf("%d\t",head->value);
		head = head->next;
	}
	printf("\n");	
}

void OddEven(cell* head, int* odd, int* even){
	*odd = *even = 0; 
	while(head){
		if(head->value%2 ==1){
			(*even)++;
		}else{
			(*odd)++;
		}
		head = head->next;
	}

}

void Delete(cell** Head, int num){
	cell* before = NULL;
	cell* head = *Head;
	cell* temp = head;
	printf("before deleting:\n");
	Show(head);
	while(head){
		if(head->value == num){
			if(before){
				before->next = head->next;
				free(head);
				break;
			}else{
				before = head->next;
				free(head);
				temp = before;
				break;
			}
		}
		
		before = head;
		head = head->next;
	}
	printf("after deleting:\n");
	Show(temp);
	*Head = temp;
}

cell* Merge(cell* one, cell* two){
	cell* final;
	cell* current;
	if(!one && !two){
		return NULL;
	}
	if(!one && two){
		return two;
	}
	if(one  && !two){
		return one;
	}
	
	if(one->value > two->value){
		final = two;
		two = two->next;		
	}else{
		final = one;
		one = one->next;
	}
	current = final;
	while(one  && two){
		if(one->value > two->value){
			current->next = two;
			two = two->next;	
		}else{
			current->next = one;
			one = one->next;	
		}
		current = current->next;
	}
	if(one){
		current->next = one;
	}
	if(two){
		current->next = two;	
	}
	return final;
}
int main(){
	int e,c;

	cell* a,*b;
	a =  Create(5,5);
	b =  Create(3,3);
	Show(a);
	OddEven(a,&e,&c);
	printf("%d : %d\n", e,c);
	Delete(&a,5);
	Show(Merge(a,b));
	
	return 0;	
}
