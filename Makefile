pin-root := `pwd`/`ls -d */ | grep pin- | cut -d "/" -f 1`

.PHONY: build clean

build:
	gcc test_segv.c
	export PIN_ROOT=$(pin-root) && cd src && $(MAKE)

clean:
	rm -rf src/obj-intel64
	rm -f a.out

