/*
	File Database (FDB) - v0.5

	Necessário incluir bilbiotecas: stdlib e string.
*/

#define FDB_MAX_SIZE 1024

#define FDB_EXTENSAO ".txt"

FILE *mfile;
char buffer[FDB_MAX_SIZE];

/* Cria um arquivo e já fica aberto para salvar dados usando fdb_SetString ou fdb_SetInt */
int fdb_create(const char filename[]) {
	/*FILE *file = fopen(filename, "r");
	if(file == NULL) {
		mfile = fopen(filename, "w");
		return 1;
	}
	fclose(file);*/
	mfile = fopen(filename, "w");
	//memset(buffer,0,sizeof(buffer));
	buffer[0] = '\0';
	return 0;
}

/* Abre o arquivo para fazer leitura com fdb_GetString ou fdb_GetInt */
int fdb_open(const char filename[]) {
	mfile = fopen(filename, "r");
	if(mfile != NULL) return 1;
	return 0;
}

/* Fecha o arquivo que abriu com 'fdb_open' */
int fdb_close() {
	if(mfile == NULL) return 0;
	fclose(mfile);
	return 1;
}

/* Apaga o arquivo */
int fdb_remove(const char filename[]) {
	FILE *file = fopen(filename, "r");
	if(file == NULL) return 0;
	fclose(file);
	return (remove(filename) == 0 ? 1 : 0);
}

/* Verifica se o arquivo existe */
int fdb_exist(const char filename[]) {
	FILE *file = fopen(filename, "r");
	if(file == NULL) return 0;
	fclose(file);
	return 1;
}

/* Salva o arquivo que foi criado e fecha */
int fdb_save() {
	if(mfile == NULL) return 0;
	fputs(buffer, mfile);
	fclose(mfile);
	buffer[0] = '\0';
	//memset(buffer,0,sizeof(buffer));
	return 1;
}
/*========================================*/

/* Setters */
int fdb_SetString(char key[], char value[]) {
	snprintf(buffer, FDB_MAX_SIZE, "%s%s=%s;", buffer, key, value);
	return 1;
}
int fdb_SetInt(char key[], int value) {
	snprintf(buffer, FDB_MAX_SIZE, "%s%s=%d;", buffer, key, value);
}

/* Getters */
char *fdb_GetString(char key[]) {
	char value[255];
	fgets(buffer, FDB_MAX_SIZE, mfile);

	char *s = strstr(buffer, key);

	int posicao = (s - buffer) + strlen(key) + 1;

	fseek(mfile, posicao, 0);
	fscanf(mfile, "%[A-Za-z0-9.,- @]", value);
	rewind(mfile);

	return value;
}

int fdb_GetInt(char key[]) {
	int result = strtol(fdb_GetString(key), NULL, 10);
	return result;
}