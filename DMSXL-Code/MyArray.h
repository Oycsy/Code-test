#pragma once

template<class T>
class MyArray {
public:
	// 1. 构造函数，s代表数组元素的个数
	MyArray(int s = 0);

	// 2. 复制构造函数
	MyArray(const MyArray& a);

	// 3. 析构函数
	~MyArray();

	// 4. 重载赋值=运算符函数，用于数组对象间的赋值
	MyArray& operator=(const MyArray& a);

	// 5. 重载[]运算符函数，用于获取数组下标对于的值
	int& operator[](int i);

	int size();
	bool isEmpty();
	bool contains(int element);
	void add(int element);
	void add(int index, int element);
	int remove(int index);
	int get(int index);
	int set(int index, int element);
	int indexOf(int element);
	void clear();
	void outOfBounds(int index);
	void rangeCheck(int index);
	void rangeCheckForAdd(int index);
	void ensureCapacity(int capacity);
private:
	int m_size;
	static int ELEMENT_NOT_FOUND;
	static int DEFAULT_CAPACITY;
	T* m_ptr;  // 指向动态分配的数组
};
