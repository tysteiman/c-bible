SOURCE_FILES=bible.c \
			 parse.c \
			 opts.c \
			 books.c \
			 verse.c

all:
	@gcc -o bible $(SOURCE_FILES)

debug:
	@gcc -g -o bible $(SOURCE_FILES)

gdb:
	@make debug
	gdb bible
