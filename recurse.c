/* recurse.c
This program recursively print out all files inside the 
default directory and all sub directories.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#define PATH_LENGTH 256

void recurse(char* dpath);

int main (int argc, char *argv[]){
	char* dpath = malloc(256);
    getcwd(dpath, PATH_LENGTH);
	
	
	recurse(dpath);

  
  return EXIT_SUCCESS;

}

void recurse(char* dpath){
    DIR* dPtr = opendir(dpath);
	struct dirent* dir_entry = readdir(dPtr);
	struct stat statbuf;
	while (dir_entry != NULL){
		if(strcmp((dir_entry->d_name), ".") == 0 || strcmp((dir_entry->d_name), "..") == 0)
		{
			dir_entry = readdir(dPtr);
			continue;
		}
	    char* tmppath=calloc(256,1);
		strcat(tmppath,dpath);
		strcat(tmppath,"/");
		strcat(tmppath,dir_entry->d_name);
		stat(tmppath,&statbuf);
		printf("file is %s mode %d \n", tmppath, S_ISDIR(statbuf.st_mode));
		
		if (S_ISDIR(statbuf.st_mode)){
			recurse(tmppath);
		}
		
		dir_entry = readdir(dPtr);
	}
    return EXIT_SUCCESS;
  }

  