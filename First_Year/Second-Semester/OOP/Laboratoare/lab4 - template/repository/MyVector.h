//
// Created by octav on 17.04.2026.
//

#ifndef LAB4___TEMPLATE_MYVECTOR_H
#define LAB4___TEMPLATE_MYVECTOR_H


template<typename T>
class MyVector
{
private:
    T* elems;
    int size;
    int capacity;

    void resize(int newCapacity)
    {
        T* newElems = new T[newCapacity];
        for (int i = 0 ; i < size; ++i)
            newElems[i] = elems[i];
        delete[] elems;
        elems = newElems;
        capacity = newCapacity;
    }

public:
    MyVector() : elems{new T[2]},size{0},capacity{2}{}

    ~MyVector()
    {
        delete[] elems;
    }

    //copy constructor
    MyVector(const MyVector& other)
    {
        size = other.size;
        capacity = other.capacity;

        elems = new T[capacity];

        for (int i = 0 ; i < size ; ++i)
            elems[i] = other.elems[i];
    }

    //operator =
    MyVector& operator=(const MyVector& other)
    {
        if (this != &other) // sa nu aiba aceeasi adresa
        {
            delete[] elems;
            size = other.size;
            capacity = other.capacity;
            elems = new T[capacity];
            for (int i = 0 ; i < size ; ++i)
                elems[i] = other.elems[i];
        }
        return *this; // trb * deoarece tu returnezi o referinta ,cand zici *this el iti da un obuiect ; this simplu este o adresa
    }


    void add(const T& el) //add
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        elems[size++] = el;
    }

    T& operator[](int pos)
    {
        return elems[pos];
    }

    const T& operator[](int pos) const
    {
        return elems[pos];
    }

    T removeLast()
    {
        if (size == 0)
            return T();

        T el = elems[size - 1];
        size--;
        return el;
    }

    int getSize() const
    {
        return size;
    }


    void removeAt(int pos)
    {
        for (int i = pos; i < size - 1; i++)
            elems[i] = elems[i + 1];
        size--;
    }

    T* begin() {
        return elems;
    }

    T* end() {
        return elems + size;
    }

    const T* begin() const {
        return elems;
    }

    const T* end() const {
        return elems + size;
    }
};


#endif //LAB4___TEMPLATE_MYVECTOR_H