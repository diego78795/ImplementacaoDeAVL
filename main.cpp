#include <iostream>
#include "arvoreAvl.hpp"

int main() {
  Arvore f;
  f.cria(8);
  f.inserir(4, f.raiz);
  f.inserir(12, f.raiz);
  f.inserir(2, f.raiz);
  f.inserir(10, f.raiz);
  f.inserir(6, f.raiz);
  f.inserir(15, f.raiz);
  f.inserir(1, f.raiz);
  f.inserir(9, f.raiz);
  f.inserir(5, f.raiz);
  f.inserir(14, f.raiz);
  f.inserir(3, f.raiz);
  f.inserir(11, f.raiz);
  f.inserir(7, f.raiz);
  f.inserir(16, f.raiz);
  f.ler(f.raiz, 0, 'r');
  f.remover(4, f.raiz);
  f.ler(f.raiz, 0, 'r');
  f.remover(3, f.raiz); 
  f.ler(f.raiz, 0, 'r');
  return 0;
}