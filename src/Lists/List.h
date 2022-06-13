#pragma once

#include <iostream>

namespace Lists {
    template<class TL>
    class List
    {
    private:
        template<class TE>
        class Element
        {
        private:
            Element<TE> *pNext;
            TE *pData;

        public:
            Element(TE *_pData = NULL, Element<TE> *_pNext = NULL)
            {
                pData = _pData;
                pNext = _pNext;
            }

            ~Element()
            {
                pData = NULL;
                pNext = NULL;
            }

            TE* getData() const { return pData; }
            void setData(TE *pd) { pData = pd; }

            Element<TE>* getNext() const { return pNext; }
            void setNext(Element<TE> *pn) { pNext = pn; }
        };

        Element<TL> *pFirst, *pLast;
        unsigned int _size;

    public:
        List() : _size(0) { pFirst = pLast = NULL; }

        ~List() { clear(); }

        bool addElement(Element<TL> *e)
        {
            if(!e)
                return false;

            if(pFirst)
            {
                pLast->setNext(e);
                pLast = e;
            }
            else
                pFirst = pLast = e;

            _size++;

            return true;
        }

        void removeElement(TL *e)
        {
            if(size() == 0)
                return;

            int i = 0;
            bool found = false;
            Element<TL> *predecessor, *toRemove = pFirst;

            while(toRemove)
            {
                if(toRemove->getData() == e)
                {
                    found = true;
                    break;
                }

                i++;
                toRemove = toRemove->getNext();
            }

            if(!found)
                return;

            if(toRemove == pFirst)
            {
                pFirst = toRemove->getNext();
                delete toRemove;
            }
            else
            {
                predecessor = pFirst;

                while(--i)
                    predecessor = predecessor->getNext();

                if(toRemove == pLast)
                    pLast = predecessor;

                predecessor->setNext(toRemove->getNext());
                delete toRemove;
            }
            _size--;
        }

        bool addData(TL *d)
        {
            if(!d)
                return false;

            Element<TL> *newElement = new Element<TL>(d);
            return addElement(newElement);
        }

        void clear()
        {
            Element<TL> *aux;
            aux = pFirst;

            while(aux)
            {
                pFirst = aux->getNext();
                delete aux;
                aux = pFirst;
            }

            pFirst = pLast = NULL;
            _size = 0;
        }

        const int size() const { return _size; }

        TL* operator[](int index)
        {
            if(index < 0 || index > (size() - 1))
            {
                std::cout << "Invalid index!" << std::endl;
                exit(1);
            }

            Element<TL> *aux = pFirst;

            while(index--)
                aux = aux->getNext();

            return aux->getData();
        }
    };
}
