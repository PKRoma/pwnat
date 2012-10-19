#pragma once
#ifndef INC_PWNAT_WINDOZE_H
#define INC_PWNAT_WINDOZE_H
#ifdef _WIN32
#	include <winsock2.h>
#	include <ws2tcpip.h>
#	define O_NONBLOCK	04000
#	define F_SETFL	4
#	define IPDEFTTL	64
#	define index(s,c) strchr(s,c)
void timeradd(struct timeval* a, struct timeval* b, struct timeval* res);
int inet_pton(int af, char* src, void* dst);
int fcntl(int socket, int cmd, long arg);
#endif
#endif
