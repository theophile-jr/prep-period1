# include <stdio.h>

int main()
{
	int i, num, j = 1;
	printf ("Entrer le nombre : \n");
	scanf ("%d", &num );

	for (i=1; i<num; i++)
		j=j*i;    

	printf("La factorielle de %d est %d\n",num,j);
}
