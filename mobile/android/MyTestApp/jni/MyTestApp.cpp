#include "MyTestApp.h"
#include <android/log.h>

JNIEXPORT void JNICALL Java_com_normalhy_mytestapp_MainActivity_OnMyNativeClick(JNIEnv *, jobject)
{
	__android_log_write(ANDROID_LOG_INFO, "test_app", "native_click");
	return;
}
