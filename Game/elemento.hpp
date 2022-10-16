#pragma once

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
    const void setProximo() const {
        return pProximo;
    }
    const void setData(TIPO* pDataE) const {
        pData = pDataE;
    }
    Elemento* getProximo() {
        return pProximo;
    }
    TIPO* getData() {
        return pData;
    }
};