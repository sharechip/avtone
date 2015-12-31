#ifndef _CR_FEATURE_H__
#define _CR_FEATURE_H__

typedef enum CR_FEATURE_INDEX {
    CR_FEATURE_BASE = 1000,
    CR_FEATURE_AA   = CR_FEATURE_BASE + 1, /*Dolby*/
    CR_FEATURE_AB   = CR_FEATURE_BASE + 2, /*DTS*/
    CR_FEATURE_VA   = CR_FEATURE_BASE + 3, /*DIVX*/
    CR_FEATURE_VB   = CR_FEATURE_BASE + 4, /*RMVB*/
    CR_FEATURE_VC   = CR_FEATURE_BASE + 5, /*VP6*/
    CR_FEATURE_MAX,
} CR_FEATURE_INDEX;

/**
*   Output:  <=0: paremeter exception; >=1: ok
**/
int cr_prop_get(const CR_FEATURE_INDEX feature, const char *default_value);

/**
*   Output:  <=0: paremeter exception; >=1: ok
**/
int cr_prop_set(const CR_FEATURE_INDEX feature, const char *value);

#endif
