  class No{
  public:
    int valor;
    No* esq;
    No* dir;
    int altura;
  };
  
  class Arvore{
  public:
    No* raiz;

  void cria (int valor) {
    No* novoNo = new No{.valor = valor, .esq = NULL, .dir = NULL, .altura = 0};
    this->raiz = novoNo;
  };

  int maior (int a, int b) {
    if(a>b)
      return a;
    else
      return b;
  };

  int calcAltura (No* no) {
    if(no)
      return no->altura;
    else
      return 0;
  };

  int calcFatorBalanceamento (No* no) {
    if(no)
      return (calcAltura(no->esq) - calcAltura(no->dir));
    else
      return 0;
  };

};