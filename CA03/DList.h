/*
 * @author 			鍾詠年
 * @ID 				b06505025
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * A DList is a mutable doubly-linked list ADT.  Its implementation is
 * circularly-linked and employs a sentinel (dummy) node at the head
 * of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#ifndef DLIST_H
#define DLIST_H

#include "DListNode.h"

template<typename T>
class DList {
protected:
	DListNode<T>* head;
	int size;
	virtual DListNode<T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next);
public:
	DList();
	bool isEmpty() const;
	int length() const;
	void insertFront(const T& item);
	void insertBack(const T& item);
	DListNode<T>* front() const;
	DListNode<T>* back() const;
	DListNode<T>* next(DListNode<T>* node) const;
	DListNode<T>* prev(DListNode<T>* node) const;
	void insertAfter(const T& item, DListNode<T>* node);
	void insertBefore(const T& item, DListNode<T>* node);
	void remove(DListNode<T>* node);
	void toString() const;
};

#endif
