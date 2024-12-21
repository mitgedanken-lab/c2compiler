#ifndef EXTERNAL_H
#define EXTERNAL_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wparentheses-equality"
#  pragma clang diagnostic ignored "-Wsometimes-uninitialized"
#  if (__clang_major__ >= 10)
#    define fallthrough  __attribute__((fallthrough))
#  endif
#elif defined(__GNUC__)
#  if (__GNUC__ >= 11)
#    define fallthrough  [[fallthrough]]
#  elif (__GNUC__ >= 7)
#    define fallthrough  __attribute__((fallthrough))
#  endif
#  pragma GCC diagnostic ignored "-Wmain"
#  if (__GNUC__ >= 10)
#    pragma GCC diagnostic ignored "-Wzero-length-bounds"
#  endif
#  if (__GNUC__ >= 7)
#    pragma GCC diagnostic ignored "-Wformat-overflow"
#    pragma GCC diagnostic ignored "-Wstringop-overflow"
#  endif
#endif

#ifndef fallthrough
#  define fallthrough
#endif

// --- internally added ---
typedef unsigned char bool;
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long int64_t;
typedef unsigned long uint64_t;
typedef long ssize_t;
typedef unsigned long size_t;
#define true 1
#define false 0
#define NULL ((void*)0)
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define offsetof(TYPE, MEMBER) ((unsigned long) &((TYPE *)0)->MEMBER)
#define to_container(type, member, ptr) ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

int dprintf(int fd, const char *format, ...);
void abort(void);

static void c2_assert(bool condition, const char* location, const char* condstr) {
  if (condition) return;
  static const char me[] = "c2c";
  dprintf(2, "%s: %s: Assertion '%s' failed\n", me, location, condstr);
  abort();
}

static bool c2_strequal(const char* s1, const char* s2) {
  while (*s1 == *s2) {
    if (*s1 == 0) return true;
    s1++;
    s2++;
  }
  return false;
}

#endif
