/*
 * @author 			鍾詠年
 * @ID 				b06505025
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 */ 

#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include"LockDListNode.h"
#include"DList.h"

template<typename T>
class LockDList: public DList<T> {
public:
    void lockNode(DListNode<T>* node);
    void remove(DListNode<T>* node);
};

#endif
