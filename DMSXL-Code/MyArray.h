#pragma once

template<class T>
class MyArray {
public:
	// 1. ���캯����s��������Ԫ�صĸ���
	MyArray(int s = 0);

	// 2. ���ƹ��캯��
	MyArray(const MyArray& a);

	// 3. ��������
	~MyArray();

	// 4. ���ظ�ֵ=�����������������������ĸ�ֵ
	MyArray& operator=(const MyArray& a);

	// 5. ����[]��������������ڻ�ȡ�����±���ڵ�ֵ
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
	T* m_ptr;  // ָ��̬���������
};
