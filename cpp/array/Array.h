#ifndef DSA_ARRAY_H
#define DSA_ARRAY_H

#include <cassert>
#include <iostream>
#include <initializer_list>

namespace dsa
{
  template <typename T>
  class Array
  {
  public:
    Array(int capacity = 10) : data_(new T[capacity]), capacity_(capacity), size_(0) {}

    Array(std::initializer_list<T> list)
    {
      data_ = new T[list.size()];
      for (auto it = list.begin(), i = 0; it != list.end(); ++it)
        data_[i++] = *it;
      capacity_ = list.size();
      size_ = list.size();
    }

    Array(const Array<T> &src) { copyFrom(src.data_, 0, src.getSize()); }

    T &operator[](int index)
    {
      assert(index >= 0 && index < size_);
      return data_[index];
    }

    Array<T> &operator=(const Array<T> &rhs)
    {
      if (this != &rhs)
      {
        delete[] data_;
        copyFrom(rhs.data_, 0, rhs.getSize());
      }
      return *this;
    }

    void copyFrom(const T *src, int begin, int end)
    {
      data_ = new T[capacity_ = 2 * (end - begin)];
      size_ = 0;
      while (end - begin)
      {
        data_[size_++] = src[begin++];
      }
    }

    int getCapacity() const { return capacity_; }

    int getSize() const { return size_; }

    bool isEmpty() const { return !size_; }

    void add(int index, const T &e)
    {
      assert(index >= 0 && index <= size_);
      expand();
      for (int i = size_ - 1; i >= index; --i)
      {
        data_[i + 1] = data_[i];
      }
      data_[index] = e;
      size_++;
    }

    void addFirst(const T &e) { add(0, e); }

    void addLast(const T &e) { add(size_, e); }

    T get(int index) const
    {
      assert(index >= 0 && index < size_);
      return data_[index];
    }

    void set(int index, const T &e)
    {
      assert(index >= 0 && index < size_);
      data_[index] = e;
    }

    bool contains(const T &e) const
    {
      for (int i = 0; i < size_; ++i)
      {
        if (data_[i] == e)
          return true;
      }
      return false;
    }

    int find(const T &e) const
    {
      for (int i = 0; i < size_; ++i)
      {
        if (data_[i] == e)
          return i;
      }
      return -1;
    }

    T remove(int index)
    {
      assert(index >= 0 && index < size_);
      T ret = data_[index];
      for (int i = index + 1; i < size_; ++i)
      {
        data_[i - 1] = data_[i];
      }
      size_--;
      shrink();
      return ret;
    }

    T removeFirst() { remove(0); }

    T removeLast() { remove(size_ - 1); }

    void removeElement(const T &e)
    {
      int index = find(e);
      if (index != -1)
      {
        remove(index);
      }
    }

    void print() const
    {
      std::cout << "Array: size = " << size_ << ", capacity = " << capacity_
                << std::endl;
      std::cout << "[";
      for (int i = 0; i < size_; ++i)
      {
        std::cout << data_[i];
        if (i != size_ - 1)
        {
          std::cout << ",";
        }
      }
      std::cout << "]";
      std::cout << std::endl;
    }

    void expand()
    {
      if (size_ < capacity_)
        return;
      T *old = data_;
      data_ = new T[capacity_ <<= 1];
      for (int i = 0; i < size_; ++i)
        data_[i] = old[i];
      delete[] old;
    }

    void shrink()
    {
      if (size_ << 2 > capacity_) // 25%为界限
        return;
      T *old = data_;
      data_ = new T[capacity_ >>= 1];
      for (int i = 0; i < size_; ++i)
        data_[i] = old[i];
      delete[] old;
    }
    ~Array()
    {
      if (data_)
        delete[] data_;
    }

  private:
    T *data_;
    int capacity_;
    int size_;
  };
} // namespace dsa

#endif // DSA_ARRAY_H
