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
	Object operator[](int){}
	const Object operator[](int)const{}
	bool empty()const{}
	int size()const{}
	int capacity()const{}
	void push_back(const Object&);
	void push_back(Object&&);
	void pop();
	const Object &back()const{}	
	
	//使用迭代器的函数
	typedef Object *iterator;
	typedef const Object const_iterator;
	
	iterator begin(){}
	const_iterator begin()const{}
	iterator end(){}
	const_iterator end()const{}

	static const int SPARE_CAPACITY=16;
	
	
	
	
private:
	int theSize;
	int theCapacity;
	Object *object;
	
};
