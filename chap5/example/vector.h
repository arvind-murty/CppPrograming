#ifndef VECTOR_H_
#define VECTOR_H_

#include <ostream>
#include <cstdlib>

template <typename T>
class Vector
{
public:
    Vector();
    Vector (const Vector & v);

    int size() const;
    bool isEmpty();

    void add(T x);

    Vector & operator=(const Vector & v);

    T & operator[] (int idx);
    T   operator[] (int idx) const;

private:
    T *x;
    int sz;
    int capacity;
};

template <typename T>
std::ostream & operator<<(std::ostream & os, const Vector<T> & v)
{
    os << "[";
    for (int i = 0; i < v.size(); i++) 
        os << (i ? ", " : "") << v[i];
    return os << "]";
}

template <typename T>
Vector<T>::Vector()
{
    x = nullptr;
    sz = 0;
    capacity = 0;
}

template <typename T>
Vector<T>::Vector (const Vector<T> & v)
{
    sz = v.sz;
    capacity = v.capacity;
    x = (T *) malloc(sizeof (T) * capacity);
    for (int i = 0; i < sz; i++)
    {
        x[i] = v.x[i];
    }
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
    free (x);
    new (this) Vector<T> (v);
    return *this;
}

template <typename T>
int Vector<T>::size() const
{
    return sz;
}

template <typename T>
bool Vector<T>::isEmpty()
{
    return sz == 0;
}

template <typename T>
void Vector<T>::add(T a)
{
    if (capacity == sz)
    {
        capacity = capacity ? capacity : 1;
        capacity *= 2;

        T *copy = x;
        x = (T *) malloc (sizeof(T) * capacity);
        for (int i = 0; i < sz; i++)
        {
            x[i] = copy[i];
        }
        free(copy);
    }
    x[sz] = a;
    ++sz;
}

template <typename T>
T &  Vector<T>::operator[](int idx)
{
    return x[idx];
}

template <typename T>
T   Vector<T>::operator[](int idx) const
{
    return x[idx];
}

#endif
