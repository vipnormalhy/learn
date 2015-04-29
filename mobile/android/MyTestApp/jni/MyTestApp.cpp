#include "MyTestApp.h"
#include <android/log.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX_NAME_LEN 255

JNIEXPORT void JNICALL Java_com_normalhy_mytestapp_MainActivity_OnMyNativeClick(JNIEnv *, jobject)
{
	char pHostName[MAX_NAME_LEN];
	char pHostIp[MAX_NAME_LEN];
	struct in_addr sHostAdd;
	struct hostent *sHostent;

	if (gethostname(pHostName, sizeof(pHostName)) != 0)
	{
		__android_log_write(ANDROID_LOG_INFO, "test_app", "hostname_err");
		return;
	}

	sHostent = gethostbyname(pHostName);

	if (!sHostent)
	{
		__android_log_print(ANDROID_LOG_INFO, "test_app", "cannot find ip, err:%d herrnu:%d", errno, h_errno);
		return;
	}
	
	for (int i = 0; i < sizeof(sHostent->h_addr_list); i++)
	{
		sHostAdd.s_addr = *((long *)(sHostent->h_addr_list + i));
		__android_log_print(ANDROID_LOG_INFO, "test_app", "%s", inet_ntoa(sHostAdd));
	}

	__android_log_write(ANDROID_LOG_INFO, "test_app", "native_click");
	return;
}
