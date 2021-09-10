#include <stdio.h>


typedef struct {
	int numerator;
	int denomenator;
} rationalT;

rationalT CreateRational (int num, int den);
rationalT AddRational(rationalT r1, rationalT r2);
rationalT MultiplyRational(rationalT r1, rationalT r2);
rationalT GetRational(void);
void PrintRational(rationalT r);
rationalT ReduceRational (rationalT r);

int main(void){
	
	int flag = 0;
	int count=0;
	rationalT rationalList[100];
	
	printf("List some rational numbers, enter 0 to end list. After, you can add or multiply them.\n");
	
	while (1){
		rationalList[count] = GetRational();
		if (rationalList[count].numerator  == 0){
			break;
		}
		if (rationalList[count].denomenator == 0){
			printf("invalid input, you can't have 0 as the denominator!\n");
			printf("please try again!\n");
		}
		else {
			count ++;
		}
	}
	

	int i = 0;
	rationalT total = rationalList[0];
	
	
	printf("This program deals with rational numbers. Select 1 for addition, 2 for multiplication, and anything else to terminate: ");
	scanf("%d", &flag);
	
	switch ( flag ) {
		case 1:
		
  			for (i=1; i<count; i++){
  				total = AddRational(total, rationalList[i]);
			  }
			total = ReduceRational(total);
			PrintRational(total);
			  	
  		break;
		case 2:
  			for (i=1; i<count; i++){
  				total = MultiplyRational(total, rationalList[i]);
			  }
			total = ReduceRational(total);
			PrintRational(total);  	
					
  		break;
  		
		default:
  			printf("Goodbye!");
  	break;
	}
	
	return (0);
}

//functions begin here

rationalT CreateRational (int num, int den){
	
	rationalT x;
	x.numerator = num;
	x.denomenator = den;
	
	return (x);
}

rationalT AddRational(rationalT r1, rationalT r2){
	rationalT x;
	x.numerator = ((r1.numerator*r2.denomenator)+(r2.numerator*r1.denomenator));
	x.denomenator = (r1.denomenator*r2.denomenator);
	
	return (x);
}

rationalT MultiplyRational(rationalT r1, rationalT r2){
	rationalT x;
	x.numerator = (r1.numerator * r2.numerator);
	x.denomenator = (r1.denomenator * r2.denomenator);
	
	return (x);
}

rationalT GetRational(void){
	rationalT r;
	int x, y;
	scanf("%d/%d", &x, &y);
	r = CreateRational(x,y);
	return (r);
}


void PrintRational(rationalT r){
	printf("%d/%d\n", r.numerator, r.denomenator);
}

rationalT ReduceRational (rationalT r)
{
	rationalT reduced;
	int x = r.numerator;
	int y = r.denomenator;
	int i = 0;
	int divnum=0;
	int divdenum=0;
	int largest = 1;
	
	for (i=1; i<=x; i++){
		divnum = x%i;
		divdenum = y%i;
		
		if(divnum == 0 && divdenum == 0){
			largest = i;
		}
	}
	
	reduced.numerator = r.numerator/largest;
	reduced.denomenator = r.denomenator/largest;
	
	return (reduced);
}


