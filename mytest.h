//#ifndef IO_TOOLS_H
//#define IO_TOOLS_H

#include <unistd.h>

char *printout(char *data);
const char* errormsg(int error);

extern ssize_t read(int filedes, void *buf, size_t nbytes);
extern ssize_t write(int fildes, const void *buf, size_t nbytes);

//#endif
