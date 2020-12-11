#include <stdio.h>
#include <unistd.h>


void parse_fakefile(FILE* fakefile);

void main(int argc, char* argv[])
{

	FILE* fakefile = fopen("Fakefile", "r");
	parse_fakefile(fakefile);
	execlp("ls", "ls", NULL);
	printf("wew\n");

}


void parse_fakefile(FILE* fakefile)
{
	char buff[4096];
	while(fgets(buff, 4096, fakefile) != NULL)
	{
		printf(">%s", buff);
	}
	
}