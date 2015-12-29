DEST=../SDL2_generated_constants.h

$(DEST): constants.c
	gcc -I/usr/local -o constants constants.c
	./constants > $@
	rm constants

constants.c: gen.rb
	ruby gen.rb > constants.c

clean:
	rm -f $(DEST) constants.c
