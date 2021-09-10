#include <stdio.h>

int main(){
	
	printf("This is a number guessing game.\n");
	printf("You think of a number between 1 and 100, and I'll try to guess it.\n");
	printf("Type y for yes and n for no.\n");
	printf("Type c if I guess your number.\n");
	int r;
	r = 50;
	int lower = 0;
	int higher = 100;
	char c;
	int count = 0;
	
	printf("Is it greater than %d?", r);
	scanf("%c", &c);
	
	while (c!= 'c'){
		
		if (c=='n'){
			higher = r;
			r = lower + (r-lower)/2;
		}else if (c=='y'){
			lower = r;
			r = r+(higher-r)/2;
		}
	
		printf("Is it greater than %d?", r);
		scanf("%c", &c);
	}
	
	return 0;
}
