#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(emclib, 1.0, edonyzpc@yahoo.com)
AC_CONFIG_SRCDIR([colorprint/color.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])
AC_CONFIG_MACRO_DIR([m4])
AM_PROG_AR

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

# Checks for libraries.
LT_INIT

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h color.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT([Makefile])
