PROJECT = quadr

SRC_FILES = main.c \
	Makefile \
        quadr.c \
	quadr.h \
	README \
	test.data

CFLAGS = -g -Wall -std=c11
LDFLAGS = -lm

$(PROJECT):	quadr.o main.o
		$(CC)  quadr.o main.o $(LDFLAGS)-o $@

	

clean:
		rm -f *.o $(PROJECT) $(PROJECT).tar.gz



depend:
		$(CC) -MM $(CPPFLAGS) *.c



dist:	$(PROJECT).tar.gz


$(PROJECT).tar.gz:	$(SRC_FILES)
			tar -cf $(PROJECT).tar $(SRC_FILES)
			gzip -f $(PROJECT).tar


#generated dependencies by 'make depend'...
main.o:
		main.c quadr.h
quadr.o: 
		quadr.c quadr.h
