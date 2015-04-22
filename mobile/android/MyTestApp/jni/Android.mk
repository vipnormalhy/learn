LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := MyTestApp
LOCAL_SRC_FILES := MyTestApp.cpp

LOCAL_LDLIBS    += -llog

include $(BUILD_SHARED_LIBRARY)
