#include <stdio.h>

int main(int argc, char ** argv)
{
	const char* fileName = argv[1];
	FILE* file = fopen(fileName, "r");
	if (!file) {
		printf("%s is not a valid file\n", fileName);
		return 0;
	}
	char key[256];
	char val[1024];
	FILE * fp = fopen("./lookup_umap.cpp", "w");

	fprintf(fp, "#include <unordered_map>\n");
	fprintf(fp, "#include \"lookup_umap.h\"\n\n");

	fprintf(fp, "std::unordered_map<const char*, const char*> data = {\n");
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
		fprintf(fp, "\t{\"%s\", \"%s\"},\n", key, val);
	}
	fclose(file);
	fprintf(fp, "};\n\n");

	fprintf(fp, "const char* lookup_umap(const char* key) {\n");
	fprintf(fp, "\treturn data[key];\n");
	fprintf(fp, "}\n");

	fclose(fp);
}
