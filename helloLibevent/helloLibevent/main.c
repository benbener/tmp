#include <stdio.h>
#include <WinSock2.h>
#include <event.h>

int main(int argc,char *argv[])
{
	WSADATA wsaData;
	struct event_base *b;

	WSAStartup(MAKEWORD(2,2),&wsaData);

	//init libevent
	b = event_base_new();
	if (!b)
	{
		puts("Create an event_base error!");
	}
	else
	{
		printf("Using libevent <%s>\n",event_base_get_method(b));
	}

	WSACleanup();

	event_base_free(b);
	return 0;
}
