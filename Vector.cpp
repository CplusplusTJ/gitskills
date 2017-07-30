
#include"Vector.h"

template<typename Object>
explicit Vector::Vector(int n){
	
	theSize=theCapacity=n;
	object=new Object[n];
}

Vector::Vector(const Vector &v){
	
	theSize=v.theSize;
	theCapacity=v.theCapacity;
	for(int i=0;i<v.size();++i){
		object[i]=v.object[i];
	}
	
	
}

Vector &Vector::operator=(const Vector &v){
		
	if(this==&v)
	return *this;

	theSize=v.theSize;
	theCapacity=v.theCapacity;
	for(int i=0;i<v.size();++i){
		
		object[i]=v.object[i];
		
	}
	return *this;
}

Vector::Vector(Vector &&v):theSize{v.theSize},
		theCapacity{v.theCapacity},object{v.object}{
		
	v.theSize=0;
	v.theCapacity=0;
	v.object=nullptr;
		
}

Vector& operator=(Vector &&v){
	
	std::swap(theSize,v.theSize);
	std::swap(theCapacity,v.theCapacity);
	std::swap(object,v.object);
	
	return *this;
}

void Vector::resize(int newSize){  // resize(100)
	
	if(newSize>theCapacity){
		
		reserve(2*newSize);
		theSize=newSize;
		theCapacity=theSize;
	}
	
	
}

void Vector::reserve(int newCapacity){ 
	
	if(newCapacity<theSize){
		return;
	}
	
	Object *newArray=new Object[newCapacity];
	for(int i=0;i<theSize;++i){
		
		newArray[i]=std::move( object[i]);
		
	}
	theCapacity=newCapacity;
	std::swap(newArray,object);
	
	delete newArray;

}










