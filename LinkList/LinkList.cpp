// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;


template <typename E>class Link{
public:
	E element;
	Link* next;
	//Constructors 
	Link(const E& elemval, Link* nextval = NULl){
		element = elemval;
		next = nextval;
	}
	Link(Link * nextval = NULL){
		next = nextval;
	}
};



template <typename E>class LList {
private:
	Link <E>* head;
	Link <E>* tail;
	Link <E>* curr;
	int cnt;//链表中元素个数
	void init(){
		curr = head = tail = new Link <E>;
		cnt = 0;
	}

	void removeall(){
		//移除所有链表节点
		while (head->next != NULL){
			head->next = head;
			delete head;
			cnt--;
		}
	}

public:
	LList(){
		init();
	}

	~LList(){
		removeall();
	}

	void clear(){
		removeall();
	}

	void insert(const E&it){
		curr->next = new Link <E>(it, curr->next);
		if (tail == curr)
			tail = curr->next;//如果插在末尾了，插入过后把tail结点设置为新建的结点
		cnt++;
	}

	void append(const E&it){
		//在末尾扩展
		tail = tail->next = new Link<E>(it, NULL);//先将新建的结点赋值给tail->next,然后将tail->next赋值给tail
	}

	E remove(){
		//删除当前元素
		if (curr->next == NULL){
			cout << "没有元素" << endl;
		}
		E etemp = curr->next->element;//储存删除元素的值
		Link<E>* ltemp = curr->next;//使用临时变量来保存删除的结点
		curr->next = curr->next->next;
		delete ltemp;
		cnt--;//链表元素个数减一
		return etemp;//返回删除元素的值
	}

	void moveToStart(){
		curr = head;
	}

	void moveToEnd(){
		curr = tail;
	}

	void prev(){
		//当前元素的前一个元素,即为curr

		//如果curr为head，则无前一个元素
		if (curr == head)
			return;

		Link<E> ltemp = head;
		while (ltemp != curr){
			ltemp = itemp->next;
		}
		//找到过后,将ltemp赋值给curr
		curr = ltemp;
	}

	void next(){
		//移动到下一个
		if (curr != tail)
			curr = curr->next;
	}

	int length(){
		return cnt;//返回链表中元素个数
	}

	int currPos() const{
		Link<E> ltemp = head;
		int i = 0;
		while (curr != ltemp){
			ltemp = ; temp->next;
			i++;
		}
		return i;
	}

	void moveToPos(int pos){
		//移动到指定位置
		if (pos < 0 || pos > cnt)
			cout << "不在范围内" << endl;
		curr = head;
		for (int i = 0; i < pos; i++)
			curr = curr->next;
	}

	const E& getValue() const{
		if (curr->next == NULL)
			cout << "没有这个元素" << endl;
		return curr->next->element;
	}
};


int main(void){

	LList<int> list;
	list.insert(10);
	list.append(20);

	list.moveToPos(1);
	list.insert(13);
	int i = list.getValue();
	cout << i;
	system("pause");

	return 0;

}

