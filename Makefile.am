## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

bin_PROGRAMS = cider
cider_SOURCES = src/main.cpp

ciderdocdir = ${prefix}/doc/cider
ciderdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(ciderdoc_DATA)

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(GTKSOURCEVIEW_CFLAGS)

AM_LDFLAGS = \
	$(GTKSOURCEVIEWMM_LIBS)

AM_CXXFLAGS = -std=gnu++0x 



dist_noinst_SCRIPTS = autogen.sh

# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(ciderdocdir)
