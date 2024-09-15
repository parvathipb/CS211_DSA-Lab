#include <stdio.h>
#include <unistd.h>

void pfunc () {
	printf("hello world\n");
}

int main () {
	FILE *fp = fopen("tmp.txt", "w");
	int fd=fileno(fp), copy=dup(1);
	dup2(fd,1);
	pfunc();	/* this one is to tmp.txt */
	fflush(stdout);
      	fclose(fp); 
	dup2(copy,1); /* return stdout to normal */
	pfunc();
	return 0;
}