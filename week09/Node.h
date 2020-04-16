#pragma once
template<typename T>
struct Node
{
public:
	T data;
	Node<T> * next;
	Node();
	Node(const T& _data, Node<T>* _next);
};

template<typename T>
Node<T>::Node() {
	this->next = nullptr;
}

template<typename T>
Node<T>::Node(const T& _data, Node<T>* _next):data(_data) {
	this->next = _next;
}
