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
	reservation.c reservation.h \
	parking.c parking.h \
	projet.c projet.h \
	window.c window.h \
	avis.c avis.h \
	agent.c agent.h \
	service.c service.h

parky_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

