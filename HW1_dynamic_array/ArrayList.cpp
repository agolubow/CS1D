/************************************************************************************************

ArrayList.cpp: hw1 homework assignment 

Author: Alexander Golubow

Purpose: The purpose of the assignment is to review the rule of the big five and to practice
		 accounting for time and space complexity

modifications:
8/29/2018 initial version

*************************************************************************************************/

#include "ArrayList.h"

int main(){

	ArrayList<int> array_one;
	ArrayList<int> array_three;
	ArrayList<int> array_five;

	for(int i=0;i<10;++i){
		array_one.insertItem(i);
	}

	std::cout << std::endl << "ARRAY ONE INFO: ";
	array_one.print();

	ArrayList<int> array_two = array_one;
	
	std::cout << std::endl << "ARRAY TWO INFO: ";
	array_two.print();

	array_three = std::move(array_two);

	std::cout << std::endl << "ARRAY TWO AFTER MOVE ASSIGNMENT TO ARRAY THREE INFO: ";
	array_two.print();

	std::cout << std::endl << "ARRAY THREE INFO: ";
	array_three.print();

	ArrayList<int> array_four = std::move(array_three);

	std::cout << std::endl << "ARRAY THREE AFTER MOVE CONSTRUCTION OF ARRAY FOUR INFO: ";
	array_three.print();

	std::cout << std::endl << "ARRAY FOUR INFO: ";
	array_four.print();

	array_five = array_four;

	std::cout << std::endl << "ARRAY FIVE INFO: ";
	array_five.print();

	return 0;
}