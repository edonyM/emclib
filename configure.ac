#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(emclib, 1.0, edonyzpc@yahoo.com)
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_MACRO_DIR([m4])
AM_PROG_AR

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

# AC_CHECK_HEADERS([stdlib.h string.h color.h emstr.h])
#AX_ADD_COMPILER_FLAG([-Wall])
#AX_ADD_COMPILER_FLAG([-Werror])
#AX_ADD_COMPILER_FLAG([-std=gnu99])
#AX_ADD_COMPILER_FLAG([-Wformat])
#AX_ADD_COMPILER_FLAG([-Wformat-security])
#AX_ADD_COMPILER_FLAG([-fstack-protector-all])
#AX_ADD_COMPILER_FLAG([-fpic])
#AX_ADD_COMPILER_FLAG([-fPIC])
#AX_ADD_PREPROC_FLAG([-D_FORTIFY_SOURCE=2])
#AX_ADD_PREPROC_FLAG([-U_FORTIFY_SOURCE])
#AX_ADD_LINK_FLAG([-Wl,--no-undefined])
#AX_ADD_LINK_FLAG([-Wl,-z,noexecstack])
#AX_ADD_LINK_FLAG([-Wl,-z,now])
#AX_ADD_LINK_FLAG([-Wl,-z,relro])
