#ifndef ARRAYLIST_H
#define ARRAYLIST_H

const int INITIAL_SIZE = 10;

template <class Type>
class ArrayList{
public:
	ArrayList();
	ArrayList(const ArrayList<Type>&);
	ArrayList(ArrayList<Type>&&);
	ArrayList<Type>& operator=(const ArrayList<Type>&);
	ArrayList<Type>& operator=(ArrayList<Type>&&);
	~ArrayList();
	int size() const;
	int getCapacity() const;
	Type * getArrayPointer() const;
	void setSize(int);
	void setCapacity(int);
	void setNullPtr();
	void insertItem(const Type&);

private:
	int sizeOfArray;
	int capacity;
	Type * Array_List;
};

template <class Type>
ArrayList<Type>::ArrayList(){ //default constructor
	sizeOfArray = 0;
	capacity = INITIAL_SIZE;
	Array_List = new Type[INITIAL_SIZE];
}

template <class Type>
ArrayList<Type>::ArrayList(const ArrayList<Type>& other){ //overloaded copy constructor
	sizeOfArray = other.size();
	Array_List = new Type[other.getCapacity()];
	for(int i=0;i<sizeOfArray;++i){
		Array_List[i] = other.getArrayPointer()[i];
	}
}

template <class Type>
ArrayList<Type>::ArrayList(ArrayList<Type>&& other){ //overloaded move constructor
	sizeOfArray = other.size();
	capacity = other.getCapacity();
	Array_List = other.getArrayPointer();
	other.setNullPtr();
}

template <class Type>
ArrayList<Type>& ArrayList<Type>::operator=(const ArrayList<Type>& other){ //overloaded copy assignment operator
	sizeOfArray = other.size();
	capacity = other.getCapacity();
	Type*temp = new Type[other.getCapacity()];
	for(int i=0;i<sizeOfArray;++i){
		temp[i] = other.getArrayPointer()[i];
	}
	delete [] Array_List;
	Array_List = temp;
	return *this;
}

template <class Type>
ArrayList<Type>& ArrayList<Type>::operator=(ArrayList<Type>&& other){ //overloaded move assignment operator
    if(this != &other){
        delete [] Array_List;               					// deallocate old space
        Array_List = other.getArrayPointer();               	// copy rhs’s elements and size, move implies copying element pointer only
        sizeOfArray = other.size();
        capacity = other.getCapacity();
        other.setNullPtr();               				// empty the rhs vector
    }	
	return *this;         									// return a self-reference
}

template <class Type>
ArrayList<Type>::~ArrayList(){
	delete [] Array_List;
}

template <class Type>
int ArrayList<Type>::size() const{
	return sizeOfArray;
}

template <class Type>
int ArrayList<Type>::getCapacity() const{
	return capacity;
}

template <class Type>
Type * ArrayList<Type>::getArrayPointer() const{
	return Array_List;
}

template <class Type>
void ArrayList<Type>::setSize(int size){
	sizeOfArray = size;
}

template <class Type>
void ArrayList<Type>::setCapacity(int capacity){
	this->capacity = capacity;
}

template <class Type>
void ArrayList<Type>::setNullPtr(){
	Array_List = nullptr;
}

template <class Type>
void ArrayList<Type>::insertItem(const Type& item){
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

#endif