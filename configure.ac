AC_INIT(cppixsort, 0.1.0)
AC_CONFIG_SRCDIR([src/main.cpp])

AC_LANG([C++])
AC_PROG_CXX

AM_INIT_AUTOMAKE([foreign])

### Check for installed programs
AC_PROG_RANLIB

### Check for available libraries
AC_CHECK_HEADER([CImg.h], [], [AC_MSG_ERROR([CImg.h needs to be installed])])
AC_CHECK_LIB([png], [main], [], [AC_MSG_ERROR([You need to install libpng (should be pulled in by png++)])])

AC_CONFIG_FILES([Makefile src/Makefile lib/Makefile])
AC_OUTPUT


