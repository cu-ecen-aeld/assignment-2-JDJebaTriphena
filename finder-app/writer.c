#include <stdio.h>
#include <syslog.h>
#include <string.h>

int writer(char filename[], char str[]){
	FILE *fptr;
	openlog(NULL,0,LOG_USER);

	
	if((filename == NULL) | (str == NULL)){
		printf("Inv Arg\n");
		syslog(LOG_ERR,"Invalid arguments");
		return 1;	
	}
	
	fptr = fopen(filename, "w");
	
	if(fptr == NULL){
		printf("Unable to create file\n");
		syslog(LOG_DEBUG,"Unable to create file");
		return 1;
	}
	else{
		printf("Writing %s to %s\n", str, filename);
		syslog(LOG_DEBUG,"Writing %s to %s", str, filename);
		fprintf(fptr, "%s", str);
	}
	fclose(fptr);
	return 0;
}

int main(int argc, char *argv[]){
	int exit_status = 0;
	if(argc != 3){
		exit_status = 1;
		printf("End 1");
	}
	else{
		char *filename = argv[1];
		char *str = argv[2];
		exit_status = writer(filename, str);
	}
	return exit_status;
}
