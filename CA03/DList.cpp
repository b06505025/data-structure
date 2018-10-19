/*
 * @author 			鍾詠年
 * @ID 				b06505025
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 */ 

#include <iostream>
#include "DList.h"
#include "LockDListNode.h"
using namespace std;

template<typename T>
DListNode<T>* DList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) {
	return new DListNode<T>(item, prev, next);
}

template<typename T>
DList<T>::DList() {
    DListNode<T> *sentinel = new DListNode<T>(0, NULL, NULL);
    head = sentinel;
    head->next = head;
    head->prev = head;
    size = 0;
}

template<typename T>
bool DList<T>::isEmpty() const{
	return size == 0;
}

template<typename T>
int DList<T>::length() const{
	return size;
}

template<typename T>
void DList<T>::insertFront(const T& item) {
    auto temp = head->next;
    head->next = newNode(item, head, head->next);
    temp->prev = head->next;
    size ++;
}

template<typename T>
void DList<T>::insertBack(const T& item) {
    auto temp = head->prev;
    head->prev = newNode(item, head->prev, head);
    temp->next = head->prev;
    size ++;
}

template<typename T>
DListNode<T>* DList<T>::front() const{
    if(isEmpty())
        return NULL;
    else
        return head->next;
}

template<typename T>
DListNode<T>* DList<T>::back() const{
    if(isEmpty())
        return NULL;
    else
        return head->prev;
}

template<typename T>
DListNode<T>* DList<T>::next(DListNode<T>* node) const{
    if(not node or node->next == head)
        return NULL;
    else
        return node->next;
}

template<typename T>
DListNode<T>* DList<T>::prev(DListNode<T>* node) const{
    if(not node or node->prev == head)
        return NULL;
    else
        return node->prev;
}

template<typename T>
void DList<T>::insertAfter(const T& item, DListNode<T>* node) {
    if(node == NULL)
        return;
    auto temp = node->next;
    node->next = newNode(item, node, temp);
    temp->prev = node->next;
    size ++;
}

template<typename T>
void DList<T>::insertBefore(const T& item, DListNode<T>* node) {
    if(node == NULL)
        return;
    auto temp = node->prev;
    node->prev = newNode(item, temp, node);
    temp->next = node->prev;
    size ++;
}

template<typename T>
void DList<T>::remove(DListNode<T>* node) {
    if(node == NULL)
        return;
    else if(length() == 0)
        return;
    auto tempprev = node->prev;
    auto tempnext = node->next;
    delete node;
    tempprev->next = tempnext;
    tempnext->prev = tempprev;
    size --;
}

template<typename T>
void DList<T>::toString() const{
	cout << "  ListNode     Item   " << endl;
	cout << "----------------------" << endl;
	DListNode < T > *current = head->next;
	int i = 1;
	while (current != head) {
		cout << i++ << "        " << current->item << endl;
		current = current->next;
	}
}
