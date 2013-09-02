## Process this file with automake to produce Makefile.in

SUBDIRS = src


ciderdocdir = ${prefix}/doc/cider
ciderdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(ciderdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(ciderdocdir)
