#pragma once

#include "Element.hpp"
#include <iostream>

template <class TIPO>

class Lista
{
private:
    Element<TIPO>* pFirst;
    Element<TIPO>* pLast;
    int size;
public:
    Lista() {
        pFirst = NULL;
        pLast = NULL;
        size = 0;
    }
    ~Lista() { // Desalocando memória
        // Destrutora da lista desaloca todos os elementos
        Element<TIPO>* pCurrent = pFirst;
        Element<TIPO>* pNext = pFirst->pNext;
        while(pCurrent != NULL) 
        {
            
            delete pCurrent;
            pCurrent = pNext;
            pNext = pCurrent->pNext;
        }
    }

    TIPO* getPos(int pos) {
        Element<TIPO>* pCurrent = pFirst;
        for (int i = 0; i < pos && pCurrent != NULL; i++)
        {
            pCurrent = pCurrent->pNext;
        }
        if (pCurrent == NULL)
        {
            std::cout << "Erro: Acesso de posição indevida" << std::endl;
            return NULL;
        }
        return pCurrent->getData();
    }

    TIPO* operator[](int pos) {
        return getPos(pos);
    }

    Element<TIPO>* getPrimeiro() {
        return pFirst;
    }

    Element<TIPO>* getUltimo() {
        return pLast;
    }

    const int getSize() const {
        return size;
    }

    void addElemento(Element<TIPO>* elem) {
        if (elem == NULL)
            return;
        size++;
        if (pFirst == NULL)
        {
            pFirst = elem;
            pLast = elem;
        } else 
        {
            pLast->pNext = elem;
            pLast = elem;
        }
    }

    void addElemento(TIPO* pTipo) {

        Element<TIPO>* elType = new Element<TIPO>;
        elType->setData(pTipo);

        if (elType == NULL)
            return;

        size++;

        if (pFirst == NULL)
        {
            pFirst = elType;
            pLast = elType;
        } else 
        {
            pLast->pNext = elType;
            pLast = elType;
        }
    }
};