/*
 * @author 			鍾詠年
 * @ID 				b06505025
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 *  A DListNode is a node in a DList (doubly-linked list).
 */

#include "DListNode.h"

/**
 *  DListNode() constructor.
 *  @param i the item to store in the node.
 *  @param p the node previous to this node.
 *  @param n the node following this node.
 */
template<typename T>
DListNode<T>::DListNode(const T& i, DListNode<T>* p, DListNode<T>* n) {
	item = i;
	prev = p;
	next = n;
}
