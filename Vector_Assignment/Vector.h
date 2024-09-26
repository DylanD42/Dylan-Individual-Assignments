#ifndef VECTOR_H
#define VECTOR_H
class Vector{
 private:
  int *vec_ptr;
  int vec_size;

 public:
  Vector();

  Vector(const Vector &other);

  ~Vector();
  
  Vector& operator=(const Vector &other);
  
  int size();
  
  int capacity();

  void push_back(int element);

  void reserve(int n);

  int& operator[](unsigned int index);
}

#endif
