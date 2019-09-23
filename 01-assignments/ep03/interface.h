#define MAX 100

typedef struct node *link;

struct node {
	int size;
	link child;
	link sibling;
	char name[100];
};

void inicializaRaiz();
void criaDiretorio(char*);
void criaArquivo(char*, int);
int imprimeFilhos();
int mudaDiretorio(int);
void retornaRaiz();
void imprimeHierarquia();
void imprimeArvoreRecursivamente(link, int);
void calculaTamanho();
int calculaTamanhoRecursivamente(link);
void apagaArquivos();
void apagaArquivosRecursivamente(link);

void prompt();

void imprimeStringDiretorioAtual();
void imprimeDiretorioAtual();
void imprimeOperacoes(int);
void imprimeNomeDiretorio(int);
void imprimeNomeArquivo(int);
void imprimeTamanho(int);
void imprimeMudaDiretorio(int);
void leInt(int*);
void leString(char*);
