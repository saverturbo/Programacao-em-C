

int top, i, option;

void menu();
void empilhar();
void desempilhar();
void listar_todos();

struct contatos{
    char nome[30];
    int telefone;
    char e_mail[15];
};

struct contatos conta[5];
