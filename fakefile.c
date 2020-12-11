#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//store all recipies in recipe struct
//check to see if passed target in recipies
//check to see if passed target exists in wd
//check to see if dependencies exist in wd
//if depenencies don't exist, check to see if recipe exists for them and do that (recursive)
//execute recipe


void fill_targets(FILE* fakefile);
int parse_target(char* line);

struct targets
{
	char*** targets;
	int* offset;
	int n_targets;
};
struct targets* targets;


void main(int argc, char* argv[])
{
	targets->n_targets = 0;
	targets = malloc(sizeof(targets));
	FILE* fakefile = fopen("Fakefile", "r");
	fill_targets(fakefile);
}


void fill_targets(FILE* fakefile)
{
	char line[4096];
	int line_number = 0;
	while(fgets(line, 4096, fakefile) != NULL)
	{
		line_number++;
		if(strlen(line) == 0 | line[0] == '\t' | line[0] == '#')
			continue;
		switch(parse_target(line))
		{
			case 0:
				targets->offset[targets->n_targets];
				targets->n_targets++;
			case 1:
				printf("there is an error on line %i\n", line_number);
				exit(1);
		} 
	}
}

int parse_target(char* line)
{
	if(line[0] == ' ' | line[0] == ':')
		return 1;

	char* tempstring;
	int i = 0;
	while(line[i] != '\n')
	{
		if(line[i] == ':')
			strncpy(targets->targets[targets->n_targets][0], line, i);
		i++;
	}
}