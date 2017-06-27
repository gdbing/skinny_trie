trie.o: trie.c trie.h
	gcc -c trie.c -ggdb

init.o: init.c init.h trie.h
	gcc -c init.c -ggdb

baked_data.c: init
	./init ../data/dictionary

lookup.o: baked_data.c lookup.c trie.h lookup.h
	gcc -c lookup.c baked_data.c -ggdb


#### CLI ####

init_cli.o: cli/init_cli.c trie.h init.h
	gcc -c cli/init_cli.c -ggdb

init: trie.o init.o cli/init_cli.o
	gcc -o init trie.o init.o cli/init_cli.o -ggdb


lookup_cli.o: cli/lookup_cli.c trie.h lookup.h
	gcc -c cli/lookup_cli.c -ggdb

lookup: trie.o lookup.o cli/lookup_cli.o
	gcc -o lookup trie.o lookup.o cli/lookup_cli.o -ggdb


#### Test ####

lookup_umap.cpp: tests/init_umap.c data/dictionary
	cd tests && \
	gcc init_umap.c -o init_umap && \
	./init_umap ../../data/dictionary && \
	rm init_umap

lookup_umap.o: tests/lookup_umap.cpp tests/lookup_umap.h
	g++ -c tests/lookup_umap.cpp -ggdb

main_test.o: tests/main_test.c tests/lookup_umap.h lookup.h
	gcc -c tests/main_test.c -ggdb

main_test: main_test.o lookup_umap.o lookup.o trie.o
	g++ -o main_test main_test.o lookup_umap.o lookup.o trie.o -ggdb


binaries=init lookup main_test

all: clean $(binaries)

clean:
	rm -f $(binaries) *.o cli/*.o tests/*.o
