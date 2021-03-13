#include <stdio.h>
#include <strings.h>
#define CARS 200 
#define BIKES 40 
int sumcars=0 , sumbikes=0;
int theseis(char arr[][10], char num[10], int type)

{
	int i;
	if (type == 1)
	{
		for (i=0; i<CARS; i++)
		{
			if (strcmp( arr[i] , num)==0)
			{
				return i;
			}
			
		}
	}
	else 
	{
		int i;
		for (i=0; i<BIKES; i++)
		{
			if (strcmp( arr[i] , num)==0)
			{
				return i;
			}
		}
	}
	return -1;
}

int pos(char arr[][10], char num[10], int type)
{
		if (type == 1)
	{
		int i;
		for ( i=0; i<CARS; i++)
		{
			if (strcmp( arr[i] , "")==0)
			{
				return i;
			}
			
		}
	}
	else 
	{
		int i;
		for ( i=0; i<BIKES; i++)
		{
			if (strcmp( arr[i] , "")==0)
			{
				return i;
			}
		}
	}
}


int main ()
{
	int type,free1=0,free2=0;
	char num[10] , cars[CARS][10]={""} , bikes[BIKES][10]={""};
	while (1)
	{
		printf ("Dose arithmo kykloforias: ");
		scanf (" %s", num);
		if (strcmp(num , "end")==0 )
		break;
		printf ("Dose typo oxhmatos: (1= Autokinhto 2= Mhxanh): ");
		scanf ("%d", &type);
		
		while (type<1 || type>2)
		{
			printf ("Dose typo oxhmatos: (1= Autokinhto 2= Mhxanh): ");
		scanf ("%d", &type);
		}
		
		if (type==1)
	{
	 	if (theseis(cars, num, type) ==-1 )
		 {
		 	free1++;
		 	int x = pos(cars, num, type);
		 	strcpy(cars[x] , num);
		  } 
		  else {
		  	printf ("O arithmos kykloforias %s trwwei antitimo 10eyro kai eleytherwnei th thesi\n",num );
		  	int x = theseis(cars, num, type);
		  	strcpy(cars[x] , "0");// goto
		  	sumcars=+10;
		  }
	}
	else
	{
			if (theseis(bikes, num, type) ==-1 )
		 {
		 	free2++;
		 	int x = pos(bikes, num, type);
		 	strcpy(bikes[x] , num);
		 	
		  } 
		  else {
		  	printf ("O arithmos kykloforias %s trwwei antitimo 4euro kai eleytherwnei th thesi\n",num );
		  	int x = theseis(bikes, num, type);
		  	strcpy(bikes[x] , "0");// goto
		  }
	}
	}
	printf("\n| CARS |\n");
	int i;
	for (i=0; i<CARS; i++)
	{
		if (strcmp(cars[i],"")==0) break;
		printf("%d) %s\n" , i+1 , cars[i]);

	}
	printf("\n| BIKES |\n");
	
	for ( i=0; i<BIKES; i++)
	{
		if (strcmp(bikes[i],"")==0) break;
		printf("%d) %s\n" , i+1 , bikes[i]);
	}
	printf ("Synolikes eispraxeis apo amaxia:%d\n", sumcars);
	printf ("Synolikes eispraxeis apo mhxanakia:%d\n", sumbikes);
	printf ("Eleytheres theseis gia amaxia %d\n", CARS-free1);
	printf ("Eleytheres theseis gia mhxanes %d\n", BIKES-free2);
}
