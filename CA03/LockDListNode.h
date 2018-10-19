/*
 * @author 			鍾詠年
 * @ID 				b06505025
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 */ 

#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

#include"DListNode.h"
#include"DList.h"

template<typename T>
class LockDListNode: public DListNode<T>{
protected:
    bool lock = false;
public:
	LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n): DListNode<T>(i, p, n){lock = false;}
    void lockOn(){lock = true;}
    void lockOff(){lock = false;}
    bool isLocked(){return lock;}
};

#endif
