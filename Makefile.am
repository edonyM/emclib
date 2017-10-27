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
#moddir                           = $(CURRENTPATH)/test
#mod_PROGRAMS                     = colorprint splitstr join
#colorprint_SOURCES               = $(moddir)/test_colorprint.c
#colorprint_CFLAGS                = -I$(CURRENTPATH)/include -std=c99 -coverage
#colorprint_LDADD                 = $(CURRENTPATH)/lib/libcolor.la
#splitstr_SOURCES                 = $(moddir)/test_splitstr.c
#splitstr_CFLAGS                  = -I$(CURRENTPATH)/include -std=gnu99 -coverage
#splitstr_LDADD                   = $(CURRENTPATH)/lib/libemstr.la
#join_SOURCES                     = $(moddir)/test_join.c
#join_CFLAGS                      = -I$(CURRENTPATH)/include -std=c99 -coverage
#join_LDADD                       = $(CURRENTPATH)/lib/libemstr.la

# Process this file with automake to produce Makefile.in
TESTS                            = tests/unittest
check_PROGRAMS                   = tests/unittest
tests_unittest_SOURCES           = tests/unittest.c tests/check_split.c tests/check_join.c tests/check_colorprint.c
tests_unittest_CFLAGS            = @CHECK_CFLAGS@ -I$(CURRENTPATH) -coverage
tests_unittest_LDADD             = $(CURRENTPATH)/lib/libemstr.la $(CURRENTPATH)/lib/libcolor.la @CHECK_LIBS@

bin_PROGRAMS					 = base64/b64
base64_b64_SOURCES				 = base64/base64.c
base64_b64_CFLAGS				 = @CHECK_CFLAGS@ -I/usr/local/include
base64_b64_LDADD				 = @CHECK_LIBS@ -L/usr/local/lib -lssl -lcrypto