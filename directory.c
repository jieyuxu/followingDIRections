#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int is_Dir(char * path){
	struct stat open;
	stat(path, &open);
	return S_ISDIR(open.st_mode);
}


void printdir(char name[]){
	DIR *ptr = opendir(name);
	struct dirent * read;
	struct stat st;
	int buff, size;

	printf("regular files\n");
	size = 0;

	for (read = readdir(ptr); read != NULL; read = readdir(ptr)){
		buff = stat(read->d_name, &st);
		if (! is_Dir(read->d_name))
			printf("\t%s\n", read->d_name);
		size += st.st_size;
	}

	rewinddir(ptr);

	printf("\ndirectories:\n");

	while ((read = readdir(ptr)) != NULL){
		if (is_Dir(read->d_name))
			printf("\t%s\n", read->d_name);
	}

	printf("\ntotal directory size: %d\n", size);
}

int main(){
	printdir(".");
}
