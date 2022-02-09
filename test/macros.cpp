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

//#define用法例子：
#define f(x) x*x
int function() {
    int a = 6, b = 2, c;
    c = f(a) / f(b);
    printf("%d\n", c); //36
    return 0;
}