#include "trie.h"

size_t char_to_index(char c)
{
// 	if (c == '\0')
// 		return NUM_CHARS;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 'a');
// 	if (c >= 'A' && c <= 'Z')
// 		return ((size_t)c - (size_t)'A');
// 	if (c == ' ')
// 		return 26;
// 	return 27;
// }
	switch(c) {
		case '\0':
			return NUM_CHARS;
		case ' ':
			return 26;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
			return c - 'a';
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			return c - 'A';
		default:
			return 27;
	}
}
