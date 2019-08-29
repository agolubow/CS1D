#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

const int INITIAL_SIZE = 10;

template <class Type>
class ArrayList{
public:
	ArrayList();
	ArrayList(const ArrayList<Type>&);
	ArrayList(ArrayList<Type>&&);
	const ArrayList<Type>& operator=(const ArrayList<Type>&);
	ArrayList<Type>& operator=(ArrayList<Type>&&);
	~ArrayList();
	int size() const;
	int getCapacity() const;
	Type * getArrayPointer() const;
	void setSize(int);
	void setCapacity(int);
	void setNullPtr();
	void insertItem(const Type&);
	void print();

private:
	int sizeOfArray;
	int capacity;
	Type * Array_List;
};

template <class Type>
ArrayList<Type>::ArrayList(){ //default constructor [TIME is O(3), SPACE is 4+4+(size of address)+(INITIAL_SIZE * sizeof(TYPE))]
	sizeOfArray = 0;
	capacity = INITIAL_SIZE;
	Array_List = new Type[INITIAL_SIZE];
}

template <class Type>
ArrayList<Type>::ArrayList(const ArrayList<Type>& other){ //overloaded copy constructor [TIME is O(sizeOfArray*4) + 5, SPACE is 4+4+(size of address)+(capacity * sizeof(TYPE))]
	sizeOfArray = other.size();
	capacity = other.getCapacity();
	Array_List = new Type[other.getCapacity()];
	for(int i=0;i<sizeOfArray;++i){
		Array_List[i] = other.getArrayPointer()[i];
	}
	std::cout << std::endl <<"---Copy constructor invoked---"<< std::endl;
}

template <class Type>
ArrayList<Type>::ArrayList(ArrayList<Type>&& other){ //overloaded move constructor [TIME is O(7), SPACE is 8+(size of address)]
	sizeOfArray = other.size();
	capacity = other.getCapacity();
	Array_List = other.getArrayPointer();
	other.setNullPtr();
	other.setCapacity(0);
	other.setSize(0);
	std::cout << std::endl <<"---Move constructor invoked---"<< std::endl;
}

template <class Type>
const ArrayList<Type>& ArrayList<Type>::operator=(const ArrayList<Type>& other){ //overloaded copy assignment operator [TIME is 8 + O(N), SPACE is 4+4+(size of address)+(capacity * sizeof(TYPE))]
	sizeOfArray = other.size();
	capacity = other.getCapacity();
	Type*temp = new Type[other.getCapacity()];
	for(int i=0;i<sizeOfArray;++i){
		temp[i] = other.getArrayPointer()[i];
	}
	delete [] Array_List;
	Array_List = temp;
	std::cout << std::endl <<"---Copy assignment invoked---"<< std::endl;
	return *this;
}

template <class Type>
ArrayList<Type>& ArrayList<Type>::operator=(ArrayList<Type>&& other){ //overloaded move assignment operator [TIME is O(10), SPACE is 8+(size of address)]
    if(this != &other){
        delete [] Array_List;		
        Array_List = other.getArrayPointer();
        sizeOfArray = other.size();
        capacity = other.getCapacity();
        other.setNullPtr();
        other.setCapacity(0);
		other.setSize(0);
    }
    std::cout << std::endl << "---Move assignment invoked---"<<std::endl;
	return *this;
}

template <class Type>
ArrayList<Type>::~ArrayList(){ //destructor [TIME is O(N), SPACE is -(sizeof(Type) * sizeOfArray)]
	delete [] Array_List;
}

/* ----GETTER FUNCTIONS---- */
template <class Type>
int ArrayList<Type>::size() const{ // [TIME is O(1), SPACE is 4]
	return sizeOfArray;
}

template <class Type>
int ArrayList<Type>::getCapacity() const{ // [TIME is O(1), SPACE is 4]
	return capacity;
}

template <class Type>
Type * ArrayList<Type>::getArrayPointer() const{ // [TIME is O(1), SPACE is (size of address)]
	return Array_List;
}

/* ----SETTER FUNCTIONS---- */
template <class Type>
void ArrayList<Type>::setSize(int size){ // [TIME is O(1), SPACE is 4]
	sizeOfArray = size;
}

template <class Type>
void ArrayList<Type>::setCapacity(int capacity){ // [TIME is O(1), SPACE is 4]
	this->capacity = capacity;
}

template <class Type>
void ArrayList<Type>::setNullPtr(){ // [TIME is O(1), SPACE is ?]
	Array_List = nullptr;
}

/* ----OTHER FUNCTIONS---- */
template <class Type>
void ArrayList<Type>::insertItem(const Type& item){ //add item to array list [TIME is 9 + O(N), SPACE is 0]
	if(sizeOfArray < capacity){
		Array_List[sizeOfArray] = item;
		++sizeOfArray;
	}else{
		capacity *= 2;
		Type * temp = new Type[capacity];
		for(int i=0;i<sizeOfArray;++i){
			temp[i] = Array_List[i];
		}
		delete [] Array_List;
		Array_List = temp;
		Array_List[sizeOfArray] = item;
		++sizeOfArray;
	}
}

template <class Type>
void ArrayList<Type>::print(){ //print array list information
	std::cout << "Size: "<<size()<<"  Capacity: "<<getCapacity()<<std::endl;
	if(size() > 0){
		for(int i=0;i<size();++i){
			std::cout << Array_List[i] <<" ";
		}
	}else{
		std::cout << "The Array List is empty!";
	}
	std::cout << std::endl;
}

#endif //end ARRAYLIST_H