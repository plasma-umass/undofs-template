COMPILER = gcc
FILESYSTEM_FILES = undofs.c

undofs: $(FILESYSTEM_FILES)
	$(COMPILER) $< -o $@ `pkg-config fuse --cflags --libs`

clean:
	rm undofs
