#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
	long lMaxHostNameLen;
	char *pHostName = NULL;
	char *pHostIp = NULL;
	struct hostent *sHost;
	struct in_addr sDotIp;

	lMaxHostNameLen = sysconf(_SC_HOST_NAME_MAX);
	pHostName = (char *)malloc(sizeof(char) * lMaxHostNameLen + 1);
	pHostName[0] = '\0';

	if (gethostname(pHostName, lMaxHostNameLen) != 0)
	{
		printf("Cannot find hostname. err : %s %d\n", pHostName, errno);
		return -1;
	}

	sHost = gethostbyname(pHostName);
	free(pHostName);

	pHostIp = (char *)malloc(sizeof(char) * 15 + 1);
	bzero(pHostIp, sizeof(pHostIp));

	for (int i = 0; i < sizeof(sHost->h_addr_list); i++)
	{
		sDotIp.s_addr = *((long *)(sHost->h_addr_list + i));

		printf("%s\n", inet_ntoa(sDotIp));
	}

	return 0;
}
