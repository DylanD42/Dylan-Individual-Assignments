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
  else{
    return vec_ptr[index];
  }
  
  
}

void Vector::push_back(int element){
  vec_size = size();
  vec_capacity = capacity();
  if(vec_capacity == 0){
    reserve(2);
  } 
  if((vec_capacity > vec_size) && (vec_capacity != 0)){
    cout << vec_size;
    vec_ptr[vec_size] = element;
  }
  if(vec_capacity <= vec_size){
    cout << "reserving more data" << endl;
    reserve(vec_size);
    vec_ptr[vec_size] = element;
    cout << "reserved " << vec_capacity << " slots." << endl;
  }
  
}

void Vector::reserve(int n){
  if(vec_capacity == 0){     
    //cout << "first set vec_capacity: " << vec_capacity << endl;
    vec_capacity = n;
    //cout << "set as n, vec_capacity: " << vec_capacity << endl;
    int *newArray = new int[n];
    delete[] vec_ptr;
    vec_ptr = newArray;
  }
  if(n >= vec_capacity){
    cout << "inside n >= vec_capacity" << endl;
    //cout << "pre ptr adress: " << vec_ptr << endl;
    //cout << "pre ptr size: " << sizeof(&vec_ptr) << endl;
    //cout << "n > vec; vec_capacity: " << vec_capacity << endl;
    //cout << "pre loop ; n: " << n << endl;
    int oldCapacity = capacity();
    for(int i = vec_capacity; i < n*2;){
      cout << "n: " << n << endl;
      cout << "capacity: " << vec_capacity << endl;
      cout << endl;
      i = i*2;
      vec_capacity = i;
    }
    
    int *newArray = new int[vec_capacity];
    for (int i = 0; i <= vec_capacity; i++){
      newArray[i] = vec_ptr[i];
    }
    delete[] vec_ptr;
    vec_ptr = newArray;
    
    for (int i = oldCapacity; i < vec_capacity; i++){
      
      vec_ptr[i] = 0;
    }
    
    //cout << "n>vc !!!! n: " << n << endl;
    //cout << "capacity: " << vec_capacity << endl;
    //cout << "post ptr adress: " << vec_ptr << endl;
    //cout << "post ptr size: " << sizeof(&vec_ptr) << endl;
  }
  if (n <= vec_capacity){
  }
  cout << capacity();
}

int Vector::size(){
  
  //cout << vec_ptr[0] << " " << vec_ptr[1] << " "  << vec_ptr[2] << "inside size "<< endl;
  vec_size = 0;
  if(vec_capacity == 0){
    cout << "Please call the reserve function to reserve memory" << endl;
    return 0;
  }
  if(vec_capacity > 0){
    for(int i = 0; i < vec_capacity; i++){
      //cout << "vec_size: " << vec_size<< endl;
      //cout << vec_ptr[i] <<endl;
      if(vec_ptr[i] != '\0'){
	vec_size++;
	//cout << "vec_size: " << vec_size<< endl;
	//cout << "test" << vec_ptr[i] <<endl;
      }
      
    }  
    
    //cout << "test " << vec_size;
    return vec_size;
  }
  
  
  
  int size = 1;
  return size;
}

int Vector::capacity(){
  return vec_capacity;
  
}
