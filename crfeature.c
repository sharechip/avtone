#include "crfeature.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#include <android/log.h>
#include <utils/threads.h>
#include <cutils/properties.h>

#define TAG "CrFeatureHelper"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define DEBUG_VERSION 1
#define MAX_KEY_SIZE 64
#define PRE_KEY_NAME "persist.sys.cr."

//using namespace android
//static Mutex rw_lock;


int cr_prop_get(const CR_FEATURE_INDEX feature, const char *default_value)
{
    //Mutex::Autolock autoLock(rw_lock);
    if((feature <= CR_FEATURE_BASE)||(feature >= CR_FEATURE_MAX)) {
        return -1;
    }

#ifdef DEBUG_VERSION
    do {
        return 1;
    } while(0);
#endif



    if(NULL == default_value) {
        default_value = "0";
    }

    char key[PROP_NAME_MAX];
    char value[PROP_VALUE_MAX];
    snprintf(key, PROP_NAME_MAX, "%s%d", PRE_KEY_NAME, feature);

    property_get(key, value, default_value);
    return atoi(value);
}

int cr_prop_set(const CR_FEATURE_INDEX feature, const char *value)
{
    //Mutex::Autolock autoLock(rw_lock);
    if((feature <= CR_FEATURE_BASE)||(feature >= CR_FEATURE_MAX)) {
        return -1;
    }

    char key[PROP_NAME_MAX];
    snprintf(key, PROP_NAME_MAX, "%s%d", PRE_KEY_NAME, feature);
    return property_set(key, value);
}
