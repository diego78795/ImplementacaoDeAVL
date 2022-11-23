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

};