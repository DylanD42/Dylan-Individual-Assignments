/**
 * @file Vector.cpp
 * @author Dylan Daniels
 * @date 2024-09-27
 * @brief is the header cpp file for the Vector assignment
 * 
 * contains the code to the methods
 *   
 */

#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;

Vector::Vector(){// constructor, sets everything to default values
  vec_ptr = NULL;  
  vec_size = 0;
  vec_capacity = 0;
}

Vector::Vector(const Vector &other){ // copy constructor, makes a deep copy of the Vector inside the ()
                                    //  copies it to the new Vector, with its own array address
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity];
  
  for (int i = 0; i < vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i]; //copying it over
  }
  cout << "(v2) vec_ptr: " << vec_ptr << endl;
  cout << "(set2) other.vec_ptr: "<< other.vec_ptr << endl;
}

Vector::~Vector(){ // deallocates the memory for the array when the Vector goes out of scope 

  delete[] vec_ptr;

}

Vector& Vector::operator=(const Vector &other){ // assignment operator, makes a deep copy of the Vector on the right
                                               //  but it replaces what is stored in the Vector on the left.
  if (this != &other){
    delete[] vec_ptr;
    vec_capacity = other.vec_capacity;
      vec_size = other.vec_size;
      vec_ptr = new int[vec_capacity];
      for(int i = 0; i< vec_size; i++){
	vec_ptr[i] = other.vec_ptr[i];
      }
  }
  cout << "(set1) vec_ptr: " << vec_ptr << endl;
  cout << "(set2) other.vec_ptr: "<< other.vec_ptr << endl;
  return *this;

}

int& Vector::operator[](unsigned int index){ // lets you view/modify a singular element of the Vector
  //unsigned int test = size();
  if(index >= static_cast<unsigned int>(size())){ //type cast to compare index to the size function without
    cout << "array index is out of bounds" << endl;// having to make an new variable 
  }
  
  return vec_ptr[index]; // takes the ptr address and adds whats in the [], to get the value at that location
  
  
  
}

void Vector::push_back(int element){ // sets the last position of the array to what is in ()
  vec_size = size(); //gets the size to determine what to do
  vec_capacity = capacity(); // capacity to make sure were still within the limit before having to reserve more memory
  if(vec_capacity == 0){ // if the vector doesn't have reserved memory, it reserves 2 slots by default.
    reserve(2);
  } 
  if((vec_capacity > vec_size) && (vec_capacity != 0)){ // if there is enough room to store data, it does without any problem
    vec_ptr[vec_size] = element;
  }
  if(vec_capacity <= vec_size){ // if the size of the Vector is the same or larger than the capacity
                               //  then it resizes to the vec_size so that it can double the size it currently is at
    reserve(vec_size);
    vec_ptr[vec_size] = element; // after resizing it then sets the position to the element requested.
  }
  
}

void Vector::reserve(int n){ // reserve makes sure that there is enough allocated memory for the data being stored
  if(vec_capacity == 0){     // if needed it makes a new array at the size requested.
    vec_capacity = n;
    int *newArray = new int[n];
    delete[] vec_ptr;
    vec_ptr = newArray;
  }
  if(n >= vec_capacity){ // this is what determines what size to reallocate to, it doubles until it is more than enough reserved memory
    int oldCapacity = capacity();
    for(int i = vec_capacity; i < n*2;){
      i = i*2;
      vec_capacity = i;
    }
    
    int *newArray = new int[vec_capacity];
    for (int i = 0; i <= vec_size; i++){ // once that is over it makes a new array then copies it over
      newArray[i] = vec_ptr[i];
    }
    delete[] vec_ptr; 
    vec_ptr = newArray;
    
    for (int i = oldCapacity; i <= vec_capacity; i++){ // then sets all the new memory slots to 0 
      
      vec_ptr[i] = 0;
    }
  }
  if (n <= vec_capacity){ // if its within bounds it does nothing 
  }
}

int Vector::size(){ // loops through the Vector to count how many characters are not NULL
  vec_size = 0;
  if(vec_capacity == 0){
    return 0;
  }
  if(vec_capacity > 0){
    for(int i = 0; i <= vec_capacity; i++){
      if(vec_ptr[i] != '\0'){
	vec_size++;
      }   
    }
    return vec_size;
  }
  int size = 1;
  return size;
}

int Vector::capacity(){ // just returns the capacity, is set when the constructor is called, or during a resize 
  return vec_capacity;
}
