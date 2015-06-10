#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define MAX_STRLEN 80

void sort(char **a, int n);
char *stringArray[N];

int main(int argc, char *argv[]) 
{
	int i;

	printf("\nEnter %d names, one per line:\n",N);	
	for (i = 0; i < N; i++) 
	{
		stringArray[i] = (char *)malloc(MAX_STRLEN);
		strcpy(stringArray[i],"");
		printf("> ");
		fgets(stringArray[i],MAX_STRLEN,stdin);
		*strchr(stringArray[i],'\n') = '\0';
	}
	sort(stringArray,N);
	printf("\nSorted:\n");
	for (i = 0; i < N; i++) 
	{
		puts(stringArray[i]);
		free(stringArray[i]);
	}

	return 0;
}

/* selection sort */
void sort(char **a, int n)
{
	int min,i,j;
	char t[MAX_STRLEN];

	for (i = 0; i < n; i++) 
	{
		min = i;
		for (j = i+1; j < n; j++) 
		{
			if (strcmp(a[j],a[min]) < 0) min = j;
		}
		strcpy(t,a[min]);
		strcpy(a[min],a[i]);
		strcpy(a[i],t);
	}
} 