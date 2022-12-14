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

  No* balancear (No* no) {
    int fatorBalanceamento = calcFatorBalanceamento(no);

    if(fatorBalanceamento < -1)
      if(calcFatorBalanceamento(no->dir) <= 0)
        no= rotEsq(no);
      else
        no= rotDirEsq(no);
    else if(fatorBalanceamento > 1){
      if (calcFatorBalanceamento(no->esq) >= 0)
        no= rotDir(no);
      else
        no= rotEsqDir(no);
    }

    return no;
    
  };

  void inserir (int valor, No* no) {
    
    if(no->valor > valor){
      if(no->esq == NULL){
        No* novoNo = new No{.valor = valor, .esq = NULL, .dir = NULL, .altura = 0};
        no->esq = novoNo;
      } else {
        inserir( valor, no->esq);
      }
    } else {
      if(no->dir == NULL){
        No* novoNo = new No{.valor = valor, .esq = NULL, .dir = NULL, .altura = 0};
        no->dir = novoNo;
      } else {
        inserir( valor, no->dir);
      }
    }
    
    no->altura = maior(calcAltura(no->esq), calcAltura(no->dir)) + 1;

    no = balancear(no);
    
  };

  No* remover(int valor, No *raiz) {
      if(raiz == NULL){
          printf("Valor nao encontrado!\n");
          return NULL;
      } else {
          if(raiz->valor == valor) {
              if(raiz->esq == NULL && raiz->dir == NULL) {
                  free(raiz);
                  printf("Elemento folha removido: %d !\n", valor);
                  return NULL;
              }
              else{
                  if(raiz->esq != NULL && raiz->dir != NULL){
                      No *aux = raiz->esq;
                      while(aux->dir != NULL)
                          aux = aux->dir;
                      raiz->valor = aux->valor;
                      aux->valor = valor;
                      printf("Elemento trocado: %d !\n", valor);
                      raiz->esq = remover(valor, raiz->esq);
                      return raiz;
                  }
                  else{
                      No *aux;
                      if(raiz->esq != NULL)
                          aux = raiz->esq;
                      else
                          aux = raiz->dir;
                      free(raiz);
                      printf("Elemento com 1 filho removido: %d !\n", valor);
                      return aux;
                  }
              }
          } else {
              if(valor < raiz->valor)
                  raiz->esq = remover(valor, raiz->esq);
              else
                  raiz->dir = remover(valor, raiz->dir);
          }
  
          raiz->altura = maior(calcAltura(raiz->esq), calcAltura(raiz->dir)) + 1;
  
          raiz = balancear(raiz);
  
          return raiz;
      }
  };

  void ler(No* no, int profundidade) {
    if(no) {
      ler(no->esq, (profundidade + 1));
      for(int i=0; i < (this->raiz->altura - profundidade); i++){
        printf("    ");
      }
      printf("%d\n", no->valor);
      ler(no->dir, (profundidade + 1));
    }
  };

};