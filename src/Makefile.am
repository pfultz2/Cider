

bin_PROGRAMS = cider
cider_SOURCES = main.cpp

AM_CPPFLAGS = \
    -DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
    -DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
    -DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
    $(GTKSOURCEVIEW_CFLAGS)

cider_LDADD = \
    $(GTKSOURCEVIEWMM_LIBS)

AM_CXXFLAGS = -std=gnu++0x 