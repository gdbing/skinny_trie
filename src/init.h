#ifndef _INIT_TRIE_H_
#define _INIT_TRIE_H_

#include <stdio.h>

#define PACKING_LEEWAY 1 // higher value will produce a less space efficient trie but will pack much faster

wide_trie * init_trie();
int insert(const char *key, const char *val, wide_trie *wt);
/* add key and val */

// int insert_synonym(const char *new_key, const char *old_key, wide_trie *wt);
/* adds new key associated with existing val */

// int insert_homonym(const char * key, const char *val, wide_trie *wt);
/* appends val to existing val. return failure if key does not already exist */

skinny_trie * pack_trie(wide_trie *wt);

void serialize_trie(skinny_trie *st, FILE *fp);

#endif
