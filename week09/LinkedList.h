#pragma once
#include <iostream>
#include "Node.h"
using std::cin;
using std::cout;

template<typename T>
class LinkedList
{
private:
	Node<T>* first;

	void copy(const LinkedList<T>& other);
	void destroy();
public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	LinkedList<T>& operator=(const LinkedList<T>& other);
	~LinkedList();

	LinkedList& push_back(const T& newData);
	LinkedList& push_front(const T& newData);

	void print() const;
};

template<typename T>
LinkedList<T>::LinkedList() {
	this->first = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
	this->copy(other);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {

}

template<typename T>
LinkedList<T>::~LinkedList() {

}


template<typename T>
void LinkedList<T>::copy(const LinkedList<T>& other) {
	/*
	Node<T>* nodeToBeCopied = other.first;

	while (nodeToBeCopied != nullptr) {
		this->push_back(nodeToBeCopied->data);
		nodeToBeCopied = nodeToBeCopied->next;
	}
	*/

	Node<T>* nodeToBeCopied = other.first;

	this->first = new Node<T>(nodeToBeCopied->data, nullptr);

	Node<T>* destinationNode = this->first;
	
	while (nodeToBeCopied != nullptr) {
		destinationNode->next = new Node<T>(nodeToBeCopied->data, nullptr);

		nodeToBeCopied = nodeToBeCopied->next;
		destinationNode = destinationNode->next;
	}
}





template<typename T>
LinkedList<T>& LinkedList<T>::push_back(const T& newData) {
	if (this->first == nullptr) {
		this->first = new Node<T>(newData, nullptr);
		return *this;
	}

	Node<T>* current = this->first;

	while (current->next != nullptr) {
		current = current->next;
	}
	
	current->next = new Node<T>(newData, nullptr);
	return *this;
}


template<typename T>
LinkedList<T>& LinkedList<T>::push_front(const T& newData) {
	this->first = new Node<T>(newData, this->first);

	/*
	Node<T>* newNode = new Node(newData, this->first);
	this->first = newNode;
	*/
	return *this;
}

template<typename T>
void LinkedList<T>::print() const {
	Node<T>* current = this->first;

	while (current != nullptr) {
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "nullptr\n";
}
