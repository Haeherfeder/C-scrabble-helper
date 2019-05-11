#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int string_is_in_Array(char d, char *current);
void string_to_lower_case(char *str);
// do not change
const int t = 1;
const int f = 0;

int main(int argc, char **argv)
{
	FILE *wordlist = fopen("ngerman", "r");
	char wordp[64];
	char current[64];
	char *word;
	int wl = 0;
	int i = 0;
	if(argc==1)
	{
		printf("gib hinter den Befehl die Buchstaben ein\n");
		return 0;
	}
	if(argc>2)
	{
		printf("keine Leerzeichen in dem Programmaufruf nach der Trennung zum Befehl.\n");
	}
	if(strlen(argv[1])>63)
	{
		argv[1][63]=0;
	}
	string_to_lower_case(argv[1]);
	while(1)
	{	
		//current is the working copy of argv[1];
		int j = f;
		strncpy(current,argv[1],64);
		word = fgets(wordp, 64, wordlist);

		if(word == NULL){ break; }

		wl = strlen(word)-1;
		string_to_lower_case(word);

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
	}
}

int string_is_in_Array(char letter, char *current)
{
	int i = 0;
	int l = strlen(current);
	for(i=0; i<l; i++)
	{
		if(letter==current[i])
		{
			//use Ascii byte 1 as invalid
			current[i]=1;
			return t;
		}
	}
	return f;
}
void string_to_lower_case(char *str)
{
	for(int i = 0; str[i]; i++)
	{
		  str[i] = tolower(str[i]);
	}

}
