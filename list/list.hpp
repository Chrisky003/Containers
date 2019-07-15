#ifndef _H_LIST_
#include <cstdlib>
#include <iostream>
using namespace std;
template<typename _T>
class list {
public:
	class node {
		friend class list<_T>;
	public:
		node(): head(NULL), isHead(false) {
			next = prev = this;
		}
		node(node *const next, node *const prev): head(NULL), isHead(false) {
			this->next = next;
			this->prev = prev;
		}
		node(const _T &_data): data(_data), head(NULL), isHead(false) {
			next = prev = this;
		}
		node(const _T &_data, node *const next, node *const prev): data(_data), head(NULL), isHead(false) {
			this->next = next;
			this->prev = prev;
		}
		~node() { }
	public:
		_T &setData(const _T &data) {
			return this->data = data;
		}
		_T &getData() {
			return data;
		}
		node *setNext(node *const next) {
			return this->next = next;
		}
		node *getNext() {
			return next;
		}
		node *setPrev(node *const prev) {
			return this->prev = prev;
		}
		node *getPrev() {
			return prev;
		}
	protected:
		_T data;
		node *next, *prev;
	private:
		list<_T> *head;
		bool isHead;
	};
	class iterator {
		friend class list<_T>;
	public:
		iterator(node *const p = NULL) {
			pnode = p;
		}
		iterator(const iterator &iter) {
			this->pnode = iter.pnode;
		}
		~iterator() { }
	public:	
		iterator operator++(int) {
			iterator temp(*this);
			if (pnode != NULL)
				pnode = pnode->getNext();
			return temp;
		}
		iterator &operator++() {
			if (pnode != NULL)
				pnode = pnode->getNext();
			return *this;
		}
		iterator operator--(int) {
			iterator temp(*this);
			if (pnode != NULL)
				pnode = pnode->getPrev();
			return temp;
		}
		iterator &operator--() {
			if (pnode != NULL)
				pnode = pnode->getPrev();
			return *this;
		}
		_T &operator*() {
			//if (pnode != NULL)
				return pnode->getData();
		}
		node &operator=(const node &node) {
			pnode = &node;
		}
		iterator &operator=(const iterator &iter) {
			pnode = iter.pnode;
			return *this;
		}
		bool operator==(const node &node) {
			return pnode == &node;
		}
		bool operator==(const iterator &iter) {
			return pnode == iter.pnode;
		}
		bool operator!=(const node &node) {
			return !(*this == node);
		}
		bool operator!=(const iterator &iter) {
			return !(*this == iter);
		}
	protected:
		node *pnode;
	};
public:
	list(): len(0) {
		phead = new node;
		phead->isHead = true;
		phead->head = this;
	}
	~list() {
		while (len != 0) {
			erase(begin());
		}
		delete phead;
	}
public:
	iterator begin() {
		return ++(iterator(phead));
	}
	iterator end() {
		return iterator(phead);
	}
	bool empty() {
		return len == 0 ? true : false;
	}
	int size() {
		return len;
	}
	void insert(const /*list<_T>::*/iterator &_pos, const _T &_data) {
		node *newNode = new node(_data);
		newNode->isHead = false;
		node *pos = _pos.pnode;
		newNode->head = pos->head;
		(pos->getPrev())->setNext(newNode);
		newNode->setPrev(pos->getPrev());
		newNode->setNext(pos);
		pos->setPrev(newNode);
		pos->head->len++;
	}
	bool erase(const /*list<_T>::*/iterator &_pos) {
		node *pos = _pos.pnode;
		if (pos->isHead) {
			return false;
		}
		pos->getPrev()->setNext(pos->getNext());
		pos->getNext()->setPrev(pos->getPrev());
		pos->head->len--;
		delete pos;
		return true;
	}
	void erase(const /*list<_T>::*/iterator &_start, const /*list<_T>::*/iterator &_end) {
		for (list<_T>::iterator pos = _start; pos != _end;) {
			erase(pos++);
		}
		erase(_end);
	}
protected:
	node *phead;
	int len;
};
#define _H_LIST_
#endif
