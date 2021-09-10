#include <stdio.h>
 
int main()
{
 	int array[100];
	int swap;
	int count = 0;
	int i = 0;
	int j = 0;
 
  	printf("Enter some numbers to sort, enter -1 when finished\n");
  	
	  while(1){
	  	scanf("%d", &array[i]);
	  	if (array[i]==-1){
	  		break;
		  }
  		i++;
  		count++;
	  }
	 
	for (i = 0 ; i < ( count - 1 ); i++)
	  	{
    	for (j = 0 ; j < count - i - 1; j++)
    	{
     		if (array[j] > array[j+1]){
     		  	swap       = array[j];
        		array[j]   = array[j+1];
        		array[j+1] = swap;
      }
    }
  }
 
  printf("Sorted list in ascending order:\n");
 
  for ( i = 0 ; i < count ; i++ )
     printf("%d\n", array[i]);
 
  return 0;
}
