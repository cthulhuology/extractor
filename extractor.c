#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <time.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include "dir.h"


static int callback(void *p, int l, char **v, char **n){
	int i = 0, fd;
	size_t w, wl,tl;

	char buffer[PATH_MAX];
	long long t0;

	struct tm* tmp;
	time_t t;

	// calculate the date of the post
	t0 = atoll(v[0]);
	t = (time_t)(t0/1000);
	tmp = localtime(&t);

	// create a directory Y/M/D for that post
	i = strftime(buffer,PATH_MAX,"./%Y/%m/%d/",tmp);
	mkpath(buffer);
	
	// add the filename
	snprintf(buffer+i, PATH_MAX-i, "%s.md", v[1]);
	fprintf(stderr,"%s\n",buffer);

	fd = open(buffer, O_CREAT | O_WRONLY,0644);
	
	wl = strlen(v[2]);	// length of the markdown

	tl = strlen(v[3]);
	write(fd,v[3],tl);
	write(fd,"\n",1);
	for (i = 0; i < tl; ++i) {
		write(fd,"=",1);
	}	
	write(fd,"\n\n",2);

	w = 0;
	while (w < wl)
		w += write(fd, v[2] + w, wl - w);
	
	close(fd);

	return 0;

}


int main(int argc, char** argv) {
	sqlite3* db;
	int r;
	char* err;

	sqlite3_open("ghost.db",&db);
	r = sqlite3_exec(db,"select created_at, slug, markdown, title from posts",callback,0,&err);
	if (r != SQLITE_OK) {
		fprintf(stderr,"SQL: %s", err);
		sqlite3_free(err);
	}	
	sqlite3_close(db);	
	return 0;	
}
