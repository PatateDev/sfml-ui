LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := sfml-ui
LOCAL_SRC_FILES := lib/$(TARGET_ARCH_ABI)/libsfml-ui.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_SHARED_LIBRARIES += sfml-system sfml-window sfml-graphics
include $(PREBUILT_STATIC_LIBRARY)

$(call import-module,sfml)
