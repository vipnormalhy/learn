#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_communicate_normal_smallgames_com_communicate_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
