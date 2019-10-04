CFLAGS = -g -Wall -fPIC -std=c11

OBJS = \
  circ.o \
  rect.o

all:		libgeom.a libgeom.so testgeom-static testgeom-dynamic


libgeom.a:	$(OBJS)
		ar rcs $@ $(OBJS)

libgeom.so:	$(OBJS)
		$(CC) -shared $(OBJS) -o $@

testgeom-static: testgeom.o
		 $(CC)  -static testgeom.o -L. -lgeom -o $@

testgeom-dynamic: testgeom.o
		 $(CC) testgeom.o -L. -lgeom -o $@

.PHONY:		clean
clean:
		rm -f *.o *.so *.a testgeom-*
