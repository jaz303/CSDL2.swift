SDL=/usr/local
LIBBASE=../libSDL2_swift_extensions
STATICLIB=$(LIBBASE).a
DYNAMICLIB=$(LIBBASE).dylib
CONSTANTS=../SDL2_generated_constants.h

all: extensions $(CONSTANTS)

extensions: $(STATICLIB) $(DYNAMICLIB)

$(STATICLIB): extensions.o
	ar rcs $@ extensions.o

$(DYNAMICLIB): extensions.o
	gcc -dynamiclib -undefined suppress -flat_namespace -o $@ extensions.o

$(EXTENSIONS): SDL2_swift_extensions.c
	
$(CONSTANTS): constants.c
	gcc -I$(SDL)/include -o constants constants.c
	./constants > $@
	rm constants

extensions.o: SDL2_swift_extensions.c
	gcc -c -o extensions.o -I$(SDL)/include $<

constants.c: gen.rb
	ruby gen.rb $(SDL) > constants.c

clean:
	rm -f $(STATICLIB) $(DYNAMICLIB) $(CONSTANTS) constants.c extensions.o

.PHONY: all extensions clean