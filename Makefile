SOURCE_FILES=bible.c \
			 parse.c \
			 opts.c

all:
	@gcc -o bible $(SOURCE_FILES)
