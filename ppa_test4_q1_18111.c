#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int i,n;
	FILE *fp;
	char string[100];
	printf("Enter the number of times the repeat words:");
	scanf("%d",&n);
	fp=fopen("input.txt","r");
	if(!fp)
		printf("File not found\n");
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%s",string);
			if(!feof(fp))
			{
				strcpy(string,strrev(&string));
				for(i=0;i<n;i++)
					printf("%s ",string);
			}
		}		
	}
	return 0;
}
