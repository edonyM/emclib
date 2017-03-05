AM_CFLAGS        = -I$(srcdir)/include -std=c99
ACLOCAL_AMFLAGS  = -I m4
AUTOMAKE_OPTIONS = foreign -Wall -Werror

lib_LIBRARIES            = lib/libcolor.a
lib_libcolor_a_SOURCES   = colorprint/color.c
include_HEADERS          = include/color.h

# test modula
check_PROGRAMS      = test/colorprint
test_colorprint_SOURCES  = test/test_colorprint.c
test_colorprint_CFLAGS   = -I$(srcdir)/include -std=c99 -coverage
test_colorprint_LDADD    = lib/libcolor.a
