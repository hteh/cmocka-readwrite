#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "mytest.h"
 
char *printout(char *data)
{
    int n;
    int m;
    int size = strlen(data);
    n= read(0, data, size);
    m= write(0, data, size);

    if ( n != size && m != size){
                fprintf(stderr,"Error on reading %d, %d in %d\n", n,m,(int)strlen(data));
                data = "error1";
        }
else if ( m != size && n ==size ){
              fprintf(stderr,"Unexpected written %d in %d\n", m,(int)strlen(data));
              data = "error2";
        }
else if ( m == size && n != size){
 		fprintf(stderr,"Error on reading %din %d\n", n,(int)strlen(data));
              	data = "error3";
        }
else if (m==size && n == size){
        	printf("success.return:%d,%d. size:%d\n", n,m, (int)strlen(data));
		data= "success";
}
    return data;
     
}


