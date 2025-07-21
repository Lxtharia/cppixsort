bin_PROGRAMS = cppixsort.out
AM_CXXFLAGS = -I $(top_srcdir) -Dcimg_display=0 `Magick++-config --cppflags --cxxflags` -DMAGICKCORE_QUANTUM_DEPTH=8
AM_LDFLAGS = `Magick++-config --ldflags --libs`
cppixsort_out_SOURCES = main.cpp cmdline.h cmdline.cpp
LDADD = $(top_srcdir)/lib/libcppixsort.a
