AM_CFLAGS        = -I$(srcdir)/include
ACLOCAL_AMFLAGS  = -I m4
AUTOMAKE_OPTIONS = foreign -Wall -Werror

lib_LIBRARIES                    = lib/libcolor.a lib/libstrsplit.a
lib_libcolor_a_SOURCES           = colorprint/color.c
lib_libstrsplit_a_SOURCES        = string/split.c
include_HEADERS                  = include/color.h include/split.h

# test modula
check_PROGRAMS           = test/colorprint test/splitstr
test_colorprint_SOURCES  = test/test_colorprint.c
test_colorprint_CFLAGS   = -I$(srcdir)/include -std=c99 -coverage
test_colorprint_LDADD    = lib/libcolor.a
test_splitstr_SOURCES    = test/test_splitstr.c
test_splitstr_CFLAGS     = -I$(srcdir)/include -std=gnu99 -coverage
test_splitstr_LDADD      = lib/libstrsplit.a
