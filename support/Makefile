SDL=/usr/local
EXTENSIONS=../SDL2_swift_extensions.dylib
CONSTANTS=../SDL2_generated_constants.h

all: $(EXTENSIONS) $(CONSTANTS)

$(EXTENSIONS): SDL2_swift_extensions.c
	gcc -c \
		-o extensions.o \
		-I$(SDL)/include \
		$<
	gcc -dynamiclib \
		-undefined suppress \
		-flat_namespace \
		-o $@ \
		extensions.o
	rm -f extensions.o

$(CONSTANTS): constants.c
	gcc -I$(SDL)/include -o constants constants.c
	./constants > $@
	rm constants

constants.c: gen.rb
	ruby gen.rb $(SDL) > constants.c

clean:
	rm -f $(EXTENSIONS) $(CONSTANTS) constants.c

.PHONY: all clean