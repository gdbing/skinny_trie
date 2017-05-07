trie.o:
	gcc -c trie.c -ggdb


init: trie.o init.o cli/init_cli.o
	gcc -o init trie.o init.o cli/init_cli.o -ggdb

init_cli.o:
	gcc -c cli/init_cli.c -ggdb

init.o:
	gcc -c init.c -ggdb


lookup: trie.o lookup.o cli/lookup_cli.o
	gcc -o lookup trie.o lookup.o cli/lookup_cli.o -ggdb

lookup_cli.o:
	gcc -c cli/lookup_cli.c -ggdb

baked_data.c: init
	./init ../data/dictionary

lookup.o: baked_data.c
	gcc -c lookup.c baked_data.c -ggdb


binaries=init lookup

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o cli/*.o
