## Process this file with automake to produce Makefile.in
TESTS = unittest
check_PROGRAMS = unittest
unittest_SOURCES = unittest.c check_split.c check_join.c check_colorprint.c
unittest_CFLAGS = @CHECK_CFLAGS@ -I$(top_builddir) -coverage
unittest_LDADD = $(top_builddir)/lib/libemstr.la $(top_builddir)/lib/libcolor.la @CHECK_LIBS@
