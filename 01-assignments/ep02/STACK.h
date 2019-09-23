/* define a estrututa da pilha como uma lista ligada*/
typedef struct STACKnode* link;

struct STACKnode {
  int value;
  link next;
};

/* prototipo das funcoes que irao manipular a pilha */
void STACKinit();
link STACKnew(int, link);
int STACKpop();
void STACKpush(int);
