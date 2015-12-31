# Copyright (C) 2014 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

BULID_LIBRARY_ACTONE_DEV := true
#
ifeq ($(BULID_LIBRARY_ACTONE_DEV),true)
else
include $(CLEAR_VARS)
LOCAL_MODULE := libavtone
LOCAL_MODULE_SUFFIX := .so
LOCAL_SRC_FILES := libavtone.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_PATH := $(TARGET_OUT)/lib
include $(BUILD_PREBUILT)
endif

include $(CLEAR_VARS)

LOCAL_MODULE    := libavtone
LOCAL_SRC_FILES := crfeature.c

# for logging
LOCAL_LDLIBS    += -llog

LOCAL_C_INCLUDES += \
        $(TOP)/system/core/include

LOCAL_SHARED_LIBRARIES := \
                libcutils \
                libutils
ifeq ($(BULID_LIBRARY_ACTONE_DEV),true)
include $(BUILD_SHARED_LIBRARY)
endif
