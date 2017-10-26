#ifndef CF_ITERATOR_H
#define CF_ITERATOR_H
#include "Object.h"


template<typename T>
class Iterator:public Object{
public:
	Iterator(){ ptr_ = NULL; }

	Iterator(T *p){ ptr = p; }

	Iterator(Iterator<T>& it){ ptr_ = it.get_element(); }

	~Iterator();

	void move_to_next(){ ptr_++; }

	T* get_element (){ return ptr_; }

	Iterator &operator++(){ ++ptr; return *this; }
	Iterator &operator--(){ --ptr; return *this; }
	bool &operator==(T& another){ return (*ptr_) == another; }
	void operator=(T& obj){ ptr = &obj; }
	bool operator!=(T& obj){ return !((*ptr_) == another); }
	bool operator!=(Iterator<T>& obj){
		return !((ptr_) == another.get_element());
	}

private:

	T* ptr_;

};


#endif