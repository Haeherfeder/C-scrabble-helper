#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_is_in_Array(char d, char *current);

// do not change
const int t = 1;
const int f = 0;


int main(int argc, char **argv)
{
	printf("-1\n");
	FILE *wordlist = fopen("ngerman", "r");
	char wordp[64];
	char current[64];
	char *word;
	int wl = 0;
	int i = 0;
	printf("0\n");	
	while(1)
	{	
		//current is the working copy of argv[1];
		int j = f;
		strcpy(current,argv[1]);
		word = fgets(wordp, 64, wordlist);

		if(word == NULL){ break; }
		
		wl = strlen(word)-1;

		for(i = 0; i < wl; i++)
		{
			if(!string_is_in_Array(word[i],current))
			{
				j = t;
				break;	
			}	 
		}
		if(!j)
		{
			printf("%s",word);
		}
//		printf("%s ist :%i lang\n",word,wl);
	}
}

int string_is_in_Array(char d, char *current)
{
	int i = 0;
	int l = strlen(current);
	for(i=0; i<l; i++)
	{
		if(d==current[i])
		{
			return t;
		}
	}
	return f;
}

