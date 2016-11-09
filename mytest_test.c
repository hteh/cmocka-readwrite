#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <unistd.h>
#include "mytest.h"


ssize_t __wrap_read(int filedes, void *buf, size_t nbytes)
{
  //  int buf_size;
//    buf_size = (int)mock();
    //if (buf_size != nbytes){
//	return -2;
  //  }
    return (ssize_t)mock(); 
}

ssize_t __wrap_write(int fildes, const void *buf, size_t nbytes)
{ 
   // int buf_size;
    //buf_size = (int)mock();
    //if (buf_size != nbytes){
    //    return -1;
    //}
    return (ssize_t)mock();
}

static void test_readwrite_success(void **state)
{
    char *ret;   
    (void)state;
    will_return(__wrap_read, 0);
    will_return(__wrap_write, 0);

    ret = printout("");
    assert_string_equal(ret, "success");
}

static void test_readwrite_error1(void **state)
{
    char *ret;
    (void)state;
    will_return(__wrap_read, 4);
    will_return(__wrap_write, 4);

    ret = printout("hot");
    assert_string_equal(ret, "error1");
}

static void test_readwrite_error2(void **state)
{
    char *ret;
    (void)state;
    will_return(__wrap_read, 10);
    will_return (__wrap_write, 9);

    ret = printout("hotdog1234");
    assert_string_equal(ret, "error2");
}

static void test_readwrite_error3(void **state)
{
    char *ret;
    (void)state;
    will_return(__wrap_read, 7);
    will_return (__wrap_write, 6);

    ret = printout("hotdog");
    assert_string_equal(ret, "error3");
}



int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_readwrite_success),
        cmocka_unit_test(test_readwrite_error1),
	cmocka_unit_test(test_readwrite_error2),
	cmocka_unit_test(test_readwrite_error3),
   }; 
 return cmocka_run_group_tests(tests, NULL, NULL);

}
