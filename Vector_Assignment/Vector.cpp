#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;

Vector::Vector(){
  vec_ptr = NULL;  
  vec_size = 0;
  vec_capacity = 0;
}

Vector::Vector(const Vector &other){
  
  vec_ptr = other.vec_ptr;
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  
}

Vector::~Vector(){

  delete[] vec_ptr;

}

Vector& Vector::operator=(const Vector &other){
  
  delete[] vec_ptr;
  return *this;

}

int& Vector::operator[](unsigned int index){
  
  if(index >= size()){
    cout << "array index is out of bounds" << endl;
    
  }
  return vec_ptr[index];
  
}

void Vector::push_back(int element){
  size();
  reserve(vec_size+1);
  //Vector[vec_size];

}

void Vector::reserve(int n){
  
  if(vec_capacity == 0){
    delete[] vec_ptr;
    vec_capacity += n;
    cout << "vec_capacity = 0" << endl;
    cout << "vec_capacity: "<< vec_capacity << endl << "n: " << n << endl;
    vec_ptr = new int[vec_capacity];
  }
  if(n > vec_capacity){
    delete[] vec_ptr;
    vec_capacity = n*2;
    cout << "vec_capacity < n" << endl;
    cout << "vec_capacity: "<< vec_capacity << endl << "n: " << n << endl;
    vec_ptr = new int[vec_capacity*2];
  }
  if (n <= vec_capacity){
  }
  
}

int Vector::size(){
  
  char end = '\0';
  char current = *vec_ptr;
  int size = 0;
  while(end != current){
    current = (*vec_ptr + size);
    size++;
  }
  return size;
}
