all : extractor

extractor: extractor.c dir.c
	gcc -ggdb -o extractor extractor.c dir.c -lsqlite3


dir: dir.c
	gcc -DDIR -o dir dir.c
