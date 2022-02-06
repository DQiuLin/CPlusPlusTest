#include "common.h"

#define PR_DEBUG 1

#ifdef PR_DEBUG
//#if PR_DEBUG == 1
#define LOG(x) cout << x << endl
#elif defined(PR_RELEASE)
#define LOG(x)
#endif

#define MAIN int main() \
{                       \
    return 0;           \
}

MAIN

//int main() {
//    LOG("Hello!");
//    return 0;
//}