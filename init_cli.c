#include "trie.h"
#include "init.h"

int main(int argc, char ** argv)
{
	wide_trie * wt = init_trie();

	for (int i = 1; i+1 < argc; i += 2)
		insert(argv[i], argv[i+1], wt);

	skinny_trie * st = pack_trie(wt);

	FILE * fp = fopen("./baked_data.c", "w");
	serialize_trie(st, fp);
}