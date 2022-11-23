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

  No* rotEsq(No *raiz){
    No *subDir, *filhoEsq;
  
    subDir = raiz->dir;
    filhoEsq = subDir->esq;
  
    subDir->esq = raiz;
    raiz->dir = filhoEsq;
  
    raiz->altura = maior(calcAltura(raiz->esq), calcAltura(raiz->dir)) + 1;
    subDir->altura = maior(calcAltura(subDir->esq), calcAltura(subDir->dir)) + 1;
  
    if(this->raiz == raiz)
      this->raiz = subDir;
  
    return subDir;
  }

  No* rotDir(No *raiz){
      No *subEsq, *filhoDir;
  
      subEsq = raiz->esq;
      filhoDir = subEsq->dir;
  
      subEsq->dir = raiz;
      raiz->esq = filhoDir;
  
      raiz->altura = maior(calcAltura(raiz->esq), calcAltura(raiz->dir)) + 1;
      subEsq->altura = maior(calcAltura(subEsq->esq), calcAltura(subEsq->dir)) + 1;
    
      if(this->raiz == raiz)
        this->raiz = subEsq;
  
      return subEsq;
  }

  No* rotEsqDir(No *raiz){
      raiz->esq = rotEsq(raiz->esq);
      return rotDir(raiz);
  }

  No* rotDirEsq(No *raiz){
      raiz->dir = rotDir(raiz->dir);
      return rotEsq(raiz);
  }

};