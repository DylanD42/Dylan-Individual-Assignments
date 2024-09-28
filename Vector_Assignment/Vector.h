/**
 * @file Vector.h 
 * @author Dylan Daniels
 * @date 2024-09-27
 * @brief is the header file for all of the methods 
 * 
 * is the header file for all of the methods 
 */

#ifndef VECTOR_H
#define VECTOR_H
class Vector{
 private:
  int *vec_ptr;
  int vec_size, vec_capacity;

 public:

/**
 * is the default constructor
 *
 * @post creates a empty Vector
 * 
 */
  Vector();


/**
 * copy constructor
 *
 * @param const Vector &other is a valid loaded Vector that we wish to copy
 * @pre another Vector is already loaded properly
 * @post makes a deep copy of the () Vector 
 * 
 */
  Vector(const Vector &other);


/**
 * destructor
 *
 * @pre there is a properly constructed Vector
 * @post deallocates the memory of the Vector
 * 
 */
  ~Vector();
  

/**
 * assignment operator, allows users to do Vector = Vector
 *
 * @param const Vector &other is a valid loaded Vector that we wish to copy
 * @pre another Vector is already loaded properly
 * @return Vector& returns the Vector on the LHS as a deep copy as the one on the RHS
 * @post makes a deep copy of the () Vector 
 * 
 */
  Vector& operator=(const Vector &other);
  

/**
 * gets the size of a Vector
 *
 * @pre a Vector is properly loaded
 * @return int returns the size of the Vector
 * @post 
 * 
 */
  int size();
  

/**
 * returns the capacity of the function
 *
 * @pre capacity is already loaded from other functions 
 * @return int returns the capacity of the Vector
 * @post capasity is returned
 * 
 */
  int capacity();


/**
 * sets the last element of the Vector to element
 *
 * @param int element is a int that we wish to store at the end of the Vector
 * @pre the Vector is properly constructed
 * @return void 
 * @post the Vector gets resized if needed, and the last position of loaded data is the element passed
 * 
 */
  void push_back(int element);


/**
 * allocates approiate ammount of memory, by making deep copies when needed
 *
 * @param int n is a int we would like to resize to
 * @pre the Vector is properly constructed
 * @return void 
 * @post the Vector is resized and all new allocatd memory is initialized 
 * 
 */
  void reserve(int n);


/**
 * allows the user to accesss the index of a Vector with [], as we would with arrays
 *
 * @param unsigned int index is a valid positon in the Vector we would like to access
 * @pre the Vector is properly initialized
 * @return int& returns the value at that position 
 * @post 
 * 
 */
  int& operator[](unsigned int index);
};

#endif
