AM_CFLAGS                        = -I$(srcdir)/include
ACLOCAL_AMFLAGS                  = -I m4
AUTOMAKE_OPTIONS                 = foreign -Wall -Werror

lib_LIBRARIES                    = lib/libcolor.a lib/libemstr.a
lib_libcolor_a_SOURCES           = colorprint/color.c
lib_libcolor_a_CFLAGS            = -I$(srcdir) -std=c99
lib_libemstr_a_SOURCES           = string/split.c string/join.c
lib_libemstr_a_CFLAGS            = -I$(srcdir) -std=gnu99
include_HEADERS                  = include/color.h include/emstr.h


noinst_PROGRAMS                  = lib/libemstr.so lib/libcolor.so
lib_libemstr_so_SOURCES          = string/join.c string/split.c
lib_libemstr_so_LDFLAGS          = -fPIC -shared
lib_libemstr_so_LDADD            = lib/libemstr.a
lib_libcolor_so_SOURCES          = colorprint/color.c
lib_libcolor_so_LDFLAGS          = -fPIC -shared
lib_libcolor_so_LDADD            = lib/libcolor.a

# test modula
check_PROGRAMS                   = test/colorprint test/splitstr test/join
test_colorprint_SOURCES          = test/test_colorprint.c
test_colorprint_CFLAGS           = -I$(srcdir)/include -std=c99 -coverage
test_colorprint_LDADD            = $(srcdir)/lib/libcolor.so
test_splitstr_SOURCES            = test/test_splitstr.c
test_splitstr_CFLAGS             = -I$(srcdir)/include -std=gnu99 -coverage
test_splitstr_LDADD              = $(srcdir)/lib/libemstr.so
test_join_SOURCES                = test/test_join.c
test_join_CFLAGS                 = -I$(srcdir)/include -std=c99 -coverage
test_join_LDADD                  = $(srcdir)/lib/libemstr.so
