SDL=/usr/local
CONSTANTS=../SDL2_generated_constants.h

all: $(CONSTANTS)
	
$(CONSTANTS): constants.c
	gcc -I$(SDL)/include -o constants constants.c
	./constants > $@
	rm constants

constants.c: gen.rb
	ruby gen.rb $(SDL) > constants.c

clean:
	rm -f $(CONSTANTS) constants.c

.PHONY: all clean