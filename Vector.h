#include<iostream>
#include<alrorithm>

template<typename Object>
class Vector{

public:
	//拷贝控制流程6个
	explicit Vector(int);
	Vector(const Vector&);
	Vector &operator=(const Vector&);
	~Vector(){delete []object;}
	Vector(Vector&&);
	Vector &operator=(Vector&&);
	
	//管理内存2个
	void resize(int );
	void reserve(int );

	//功能函数9
	Object operator[](int index){return object[index];}
	const Object operator[](int index)const{return object[index];}
	bool empty()const{return 0==theSize;}
	int size()const{return theSize;}
	int capacity()const{return theCapacity;}
	void push_back(const Object&);
	void push_back(Object&&);
	void pop();
	const Object &back()const{return object[back];}	
	
	//使用迭代器的函数
	typedef Object *iterator;
	typedef const Object const_iterator;
	
	iterator begin(){return object[0];}
	const_iterator begin()const{return object[0];}
	iterator end(){return object[size()];}
	const_iterator end()const{return object[size()];}

	static const int SPARE_CAPACITY=16;
	
	
	
	
private:
	int theSize;
	int theCapacity;
	Object *object;
	
};
