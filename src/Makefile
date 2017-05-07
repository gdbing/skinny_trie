init: trie.o init.o cli/init_cli.o
	gcc -o init trie.o init.o cli/init_cli.o -ggdb

lookup: trie.o lookup.o cli/lookup_cli.o
	gcc -o lookup trie.o lookup.o cli/lookup_cli.o -ggdb

trie.o: trie.h trie.c
	gcc -c trie.c -ggdb

init.o: init.h init.c trie.h
	gcc -c init.c -ggdb

lookup.o: lookup.h lookup.c trie.h baked_data.c
	gcc -c lookup.c baked_data.c -ggdb

init_cli.o: cli/init_cli.c trie.h init.h
	gcc -c cli/init_cli.c -ggdb

lookup_cli.o: cli/lookup_cli.c trie.h lookup.h
	gcc -c cli/lookup_cli.c -ggdb

binaries=init lookup

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o cli/*.o
