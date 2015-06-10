#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaPrimeiro(char* c1, char* c2)
{
	int cmpc1, cmpc2, i, z, a1 = 0, a2 = 0;
	cmpc1 = strlen(c1);
	cmpc2 = strlen(c2);
	if (cmpc1 <= cmpc2)
		z = cmpc1;
	else
		z = cmpc2;
	printf("Comp1 = %d = %s\t Comp2 = %d = %s\n", cmpc1, c1, cmpc2, c2);
	for (i = 0; i < z; i++)
	{
		if (c1[i] < c2[i])
			a1++;
		else
			a2++;
		printf("a1 = %d\t a2 = %d\n", a1, a2);
	}
}

int main()
{
	char *c1, *c2;
	c1 = (char*) malloc(sizeof(char));
	c2 = (char*) malloc(sizeof(char));
	
	printf("Digite a primeira: ");
	fflush(stdin);
	scanf("%s", c1);
	
	printf("Digite a segunda: ");
	fflush(stdin);
	scanf("%s", c2);
	//printf("%s\t %s\n", c1, c2);
	verificaPrimeiro(c1, c2);
	return 0;
}