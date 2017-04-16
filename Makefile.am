CURRENTPATH                      = ${PWD}
AM_CFLAGS                        = -I$(CURRENTPATH)/include
ACLOCAL_AMFLAGS                  = -I m4
AUTOMAKE_OPTIONS                 = foreign -Wall -Werror

lib_LTLIBRARIES                  = lib/libcolor.la lib/libemstr.la
lib_libcolor_la_SOURCES          = colorprint/color.c
lib_libcolor_la_CFLAGS           = -I$(CURRENTPATH) -std=c99 -fPIC
lib_libemstr_la_SOURCES          = string/split.c string/join.c
lib_libemstr_la_CFLAGS           = -I$(CURRENTPATH) -std=gnu99 -fPIC
include_HEADERS                  = include/color.h include/emstr.h


# test modula
check_PROGRAMS                   = test/colorprint test/splitstr test/join
test_colorprint_SOURCES          = test/test_colorprint.c
test_colorprint_CFLAGS           = -I$(CURRENTPATH)/include -std=c99 -coverage
test_colorprint_LDADD            = $(CURRENTPATH)/lib/libcolor.la
test_splitstr_SOURCES            = test/test_splitstr.c
test_splitstr_CFLAGS             = -I$(CURRENTPATH)/include -std=gnu99 -coverage
test_splitstr_LDADD              = $(CURRENTPATH)/lib/libemstr.la
test_join_SOURCES                = test/test_join.c
test_join_CFLAGS                 = -I$(CURRENTPATH)/include -std=c99 -coverage
test_join_LDADD                  = $(CURRENTPATH)/lib/libemstr.la
