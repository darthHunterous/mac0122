/* define as estruturas utilizadas no armazenamento do labirinto */
typedef struct item Item;
typedef struct room Room;

struct item {
  int id;
  Item* next;
};
struct room {
  Item* adj;
};

/* funcao que recebe um inteiro e o armazena em um novo no criado na
lista ligada */
Item* newNode(int);
