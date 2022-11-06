#pragma once

#include "Element.hpp"
#include <iostream>

template <class TIPO>

class Lista
{
private:
    Elemento<TIPO>* pPrimeiro;
    Elemento<TIPO>* pUltimo;
    int size;
public:
    Lista() {
        pPrimeiro = NULL;
        pUltimo = NULL;
        size = 0;
    }
    ~Lista() { // Desalocando memória
        // Destrutora da lista desaloca todos os elementos
        Elemento<TIPO>* pAtual = pPrimeiro;
        Elemento<TIPO>* pProximo = pPrimeiro->pProximo;
        while(pAtual != NULL) 
        {
            
            delete pAtual;
            pAtual = pProximo;
            pProximo = pAtual->pProximo;
        }
    }

    TIPO* getPos(int pos) {
        Elemento<TIPO>* pAtual = pPrimeiro;
        for (int i = 0; i < pos && pAtual != NULL; i++)
        {
            pAtual = pAtual->pProximo;
        }
        if (pAtual == NULL)
        {
            std::cout << "Erro: Acesso de posição indevida" << std::endl;
            return NULL;
        }
        return pAtual->getData();
    }

    TIPO* operator[](int pos) {
        return getPos(pos);
    }

    Elemento<TIPO>* getPrimeiro() {
        return pPrimeiro;
    }

    Elemento<TIPO>* getUltimo() {
        return pUltimo;
    }

    const int getSize() const {
        return size;
    }

    void addElemento(Elemento<TIPO>* elem) {
        if (elem == NULL)
            return;
        size++;
        if (pPrimeiro == NULL)
        {
            pPrimeiro = elem;
            pUltimo = elem;
        } else 
        {
            pUltimo->pProximo = elem;
            pUltimo = elem;
        }
    }

    void addElemento(TIPO* pTipo) {

        Elemento<TIPO>* elTipo = new Elemento<TIPO>;
        elTipo->setData(pTipo);

        if (elTipo == NULL)
            return;

        size++;

        if (pPrimeiro == NULL)
        {
            pPrimeiro = elTipo;
            pUltimo = elTipo;
        } else 
        {
            pUltimo->pProximo = elTipo;
            pUltimo = elTipo;
        }
    }
};