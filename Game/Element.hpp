#pragma once

#include <iostream>
template <class TIPO>

class Element 
{
private:
    TIPO* pData;
public:
    Element<TIPO>* pNext;
    Element() {
        pNext = NULL;
        pData = NULL;
    }
    Element(Element* pNextE, TIPO* pDataE) {
        pNext = pNextE;
        pData = pDataE;
    }
    ~Element() {
        delete *pData;
    }
    const void setProximo(Element* pN) const {
        pNext = pN;
    }
    const void setData(TIPO* pDataE) {
        pData = pDataE;
    }
    Element* getProximo() const {
        return pNext;
    }
    TIPO* getData() const {
        return pData;
    }
};