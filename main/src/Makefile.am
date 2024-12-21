## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = parky

parky_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
<<<<<<< HEAD
	reservation.c reservation.h \
	parking.c parking.h
=======
	projet.c projet.h \
	window.c window.h \
	reservation.c reservation.h
>>>>>>> client

parky_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

