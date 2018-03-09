#pragma once

#include "utils.h"
#include "starray.h"

#define EMPTY_OP do{} while(0)

#define ERR(...) tprintf(__VA_ARGS__); exit(1)

#ifdef _VERBOSE

#define DLOG(X) cout << X << endl

#undef ERR(...)

#define ERR(...) tprintf(__VA_ARGS__); system("pause"); exit(1)

#else
#define DLOG(X) EMPTY_OP
#endif // _VERBOSE

#ifdef _ILLEGAL_ACCESS_CATCH
#define TRY_BLOCK_START try {
#define TRY_BLOCK_END } catch(...) {}
#define TRY_BLOCK_END_ERR(...) } catch(...) { ERR(__VA_ARGS__); }
#else
#define TRY_START EMPTY_OP
#define TRY_BLOCK_END EMPTY_OP
#define TRY_BLOCK_END_ERR EMPTY_OP
#endif

typedef unsigned char UChar;
typedef unsigned short UShort;
typedef unsigned long WRD;
typedef unsigned long long DWRD;
typedef float Float;