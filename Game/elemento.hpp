#pragma once

#include <iostream>
template <class TIPO>

class Elemento 
{
private:
    TIPO* pData;
public:
    Elemento<TIPO>* pProximo;
    Elemento() {
        pProximo = NULL;
        pData = NULL;
    }
    Elemento(Elemento* pProximoE, TIPO* pDataE) {
        pProximo = pProximoE;
        pData = pDataE;
    }
    ~Elemento() {
        
    }
    const void setProximo(Elemento* pProx) const {
        pProximo = pProx;
    }
    const void setData(TIPO* pDataE) {
        pData = pDataE;
    }
    Elemento* getProximo() const {
        return pProximo;
    }
    TIPO* getData() const {
        return pData;
    }
};