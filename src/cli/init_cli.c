#include "../trie.h"
#include "../init.h"

int main(int argc, char ** argv)
{
// 	wide_trie * wt = init_trie();

// 	for (int i = 1; i+1 < argc; i += 2)
// 		insert(argv[i], argv[i+1], wt);

// 	skinny_trie * st = pack_trie(wt);

// 	FILE * fp = fopen("./baked_data.c", "w");
// 	serialize_trie(st, fp);
// 	fclose(fp);
// }

// int file_main(int argc, char ** argv)
// {
	wide_trie * wt = init_trie();

	const char* fileName = argv[1];
	FILE* file = fopen(fileName, "r");
	char key[256];
	char val[1024];

	// for (int i = 0; i < 20000; i++) {
	while (fgets(key,sizeof(key), file) && fgets(val, sizeof(val), file)) {
		for (int i = 0; i < sizeof(key); i++) {
			if (key[i] == '\n') {
				key[i] = '\0';
				break;
			}
		}
		for (int i = 0; i < sizeof(val); i++) {
			if (val[i] == '\n') {
				val[i] = '\0';
				break;
			}
		}
		insert(key, val, wt);
	}
	fclose(file);

	skinny_trie * st = pack_trie(wt);

	FILE * fp = fopen("./baked_data.c", "w");
	serialize_trie(st, fp);
	fclose(fp);
}
