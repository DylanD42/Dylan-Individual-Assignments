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

  for (int i = 0; i >= vec_capacity; i++){
    vec_ptr[i] = other.vec_ptr[i];
  }
  
  delete[] other.vec_ptr;
}

Vector::~Vector(){

  delete[] vec_ptr;

}

Vector& Vector::operator=(const Vector &other){
  int *newArray = new int[other.vec_size];
  delete[] vec_ptr;
  vec_ptr = newArray;
  return *this;

}

int& Vector::operator[](unsigned int index){
  
  if(index >= size()){
    cout << "array index is out of bounds" << endl;
    
  }
  return vec_ptr[index];
  
}

void Vector::push_back(int element){
  vec_size = size();
  vec_capacity = capacity();
  //if(vec_size == 0 && vec_capacity == 0){
    //cout << "Error must allocate memory first" << endl;
    //}
  //else if(vec_size == 0 && vec_capacity > vec_size){
  vec_ptr[0] = element;
  vec_ptr[1] = element+1;
  vec_ptr[2] = element+2;
  
  cout << "withinin pushback" << endl;
  cout << vec_ptr[0] << " " << vec_ptr[1] << " "  << vec_ptr[2] << endl;
    //}
  
  reserve(vec_size+1);
  vec_ptr[vec_size] = element; 
}

void Vector::reserve(int n){
  if(vec_capacity == 0){
    cout << "vec_capacity: " << vec_capacity << endl;
    vec_capacity = n;
    cout << "set as n, vec_capacity: " << vec_capacity << endl;
    int *newArray = new int[n];
    delete[] vec_ptr;
    cout << "deleted vec_ptr" << endl;
    cout << "vec_capacity = 0" << endl;
    cout << "vec_capacity: "<< vec_capacity << endl << "n: " << n << endl;
    vec_ptr = newArray;
  }
  else if(n > vec_capacity){
    cout << "pre ptr adress: " << vec_ptr << endl;
    cout << "pre ptr size: " << sizeof(&vec_ptr) << endl;

    
    cout << "n > vec; vec_capacity: " << vec_capacity << endl;
    cout << "pre loop ; n: " << n << endl;
    for(int i = vec_capacity; i < n;){
      cout << "n: " << n << endl;
      cout << "capacity: " << vec_capacity << endl;
      cout << endl;
      i = i*2;
      vec_capacity = i;
    }
    cout << "n: " << n << endl;
    cout << "capacity: " << vec_capacity << endl;

    
    int *newArray = new int[vec_capacity];
    for (int i = 0; i < vec_capacity; i++){
      newArray[i] = vec_ptr[i];
    }
    
    delete[] vec_ptr;
    vec_ptr = newArray;
    cout << "post ptr adress: " << vec_ptr << endl;
    cout << "post ptr size: " << sizeof(&vec_ptr) << endl;
  }
  else if (n <= vec_capacity){
  }
  
}

int Vector::size(){
  cout << endl << "size:" << endl << endl;
  char end = '\0';
  char current = *vec_ptr;
  int size = 0;
  while(end != current){
    cout << "size of array: " << size << endl;
    cout << "current char: " << current << endl;
    current = (*vec_ptr + size);
    size++;
    
      
   cout << endl;
  }
  return size;
}

int Vector::capacity(){
  return vec_capacity;
  
}
