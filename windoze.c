#ifdef _WIN32
#include "windoze.h"
#include <errno.h>
void timeradd(struct timeval* a, struct timeval* b, struct timeval* res)
{
	res->tv_sec=a->tv_sec+b->tv_sec;
	res->tv_usec=(a->tv_usec+b->tv_usec)%1000;
	res->tv_sec+=(a->tv_usec+b->tv_usec)/1000;
}
int inet_pton(int af, char* src, void* dst)
{
	if(af!=AF_INET || af!=AF_INET6) {
		_set_errno(EAFNOSUPPORT);
		return -1;
	}
	int size=(af==AF_INET6?sizeof(struct sockaddr_in6):sizeof(struct sockaddr_in));
	if(src && *src && !WSAStringToAddress(src,af,NULL,(struct sockaddr*)dst,&size))
		return 1;
	return 0;
}
int fcntl(int socket, int cmd, long arg)
{
	if(cmd==F_SETFL && arg==O_NONBLOCK) {
		unsigned long arg=1;
		ioctlsocket(socket,FIONBIO,&arg);
		return 0;
	}
	return -1;
}
#endif
