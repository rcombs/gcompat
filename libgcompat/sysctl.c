#include <sys/auxv.h>		/* getauxval */
#include <sys/syscall.h>
#include <unistd.h>		/* size_t */


unsigned long __getauxval(unsigned long type)
{
	return getauxval(type);
}


#ifdef SYS__sysctl

struct __sysctl_args {
	int *name;
	int nlen;
	void *oldval;
	size_t *oldlenp;
	void *newval;
	size_t newlen;
};

int sysctl(int *name, int nlen, void *oldval, size_t *oldlenp, void *newval,
           size_t newlen)
{
	struct __sysctl_args args = { .name = name,
		                      .nlen = nlen,
		                      .oldval = oldval,
		                      .oldlenp = oldlenp,
		                      .newval = newval,
		                      .newlen = newlen };

	return syscall(SYS__sysctl, &args);
}

#endif /* SYS__sysctl */
