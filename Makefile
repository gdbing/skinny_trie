init: trie.o init.o init_cli.o
	gcc -o init trie.o init.o init_cli.o -ggdb

lookup: trie.o lookup.o lookup_cli.o
	gcc -o lookup trie.o lookup.o lookup_cli.o -ggdb

trie.o: trie.h trie.c
	gcc -c trie.c -ggdb

init.o: init.h init.c trie.h
	gcc -c init.c -ggdb

lookup.o: lookup.h lookup.c trie.h baked_data.c
	gcc -c lookup.c baked_data.c -ggdb

init_cli.o: init_cli.c trie.h init.h
	gcc -c init_cli.c -ggdb

lookup_cli.o: lookup_cli.c trie.h lookup.h
	gcc -c lookup_cli.c -ggdb

binaries=init lookup

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o
