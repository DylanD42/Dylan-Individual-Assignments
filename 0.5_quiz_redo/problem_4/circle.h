/**
 * @file circle.h
 * @author Dylan Daniels
 * @date 2024-09-12
 * @brief Class to hold data of a circle
 * 
 * reads in imputs from a user and loads it into the circle class
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class circle{
 private:
  int x;
  int y;
  float radius;

 public:

/**
 * prompts the user for data to put into the data of the circle
 *
 * @pre 
 * @return void 
 * @post loads data into the variables
 * 
 */
  void read();
  

/**
 * changes the value stored in the radius variable
 *
 * @param float radius is the new size for radius
 * @pre the cirlce is already created
 * @return void 
 * @post sets the variable to the new radius
 * 
 */
  void resize(float radius);


/**
 * prints the data loaded
 *
 * @pre the data is properly loaded
 * @return void 
 * @post prints to the terminal 
 * 
 */
  void print();


/**
 * swaps the x and y with new x's and y's 
 *
 * @param int x is a new x value
 * @param int y is a new y value
 * @pre 
 * @return void 
 * @post replaces x and y 
 * 
 */
  void move(int x, int y);
};
#endif //CIRCLE_H
