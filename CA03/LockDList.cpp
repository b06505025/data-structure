/*
 * @author 			鍾詠年
 * @ID 				b06505025
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 */ 

#include"LockDList.h"
#include"DListNode.h"
#include"LockDListNode.h"

template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node){
    static_cast<LockDListNode<T>*>(node)->lockOn();
    return;
}

template<typename T>
void LockDList<T>::remove(DListNode<T>* node){
    if(node == NULL)
        return;
    else{
        LockDListNode<T>* _node = static_cast<LockDListNode<T>*>(node);
        if(_node->isLocked())
            return;
        else{
            DList<T>::remove(node);
            return;
        }
    }
}
