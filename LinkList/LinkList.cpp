// LinkList.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int cnt;//������Ԫ�ظ���
	void init(){
		curr = head = tail = new Link <E>;
		cnt = 0;
	}

	void removeall(){
		//�Ƴ���������ڵ�
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
			tail = curr->next;//�������ĩβ�ˣ���������tail�������Ϊ�½��Ľ��
		cnt++;
	}

	void append(const E&it){
		//��ĩβ��չ
		tail = tail->next = new Link<E>(it, NULL);//�Ƚ��½��Ľ�㸳ֵ��tail->next,Ȼ��tail->next��ֵ��tail
	}

	E remove(){
		//ɾ����ǰԪ��
		if (curr->next == NULL){
			cout << "û��Ԫ��" << endl;
		}
		E etemp = curr->next->element;//����ɾ��Ԫ�ص�ֵ
		Link<E>* ltemp = curr->next;//ʹ����ʱ����������ɾ���Ľ��
		curr->next = curr->next->next;
		delete ltemp;
		cnt--;//����Ԫ�ظ�����һ
		return etemp;//����ɾ��Ԫ�ص�ֵ
	}

	void moveToStart(){
		curr = head;
	}

	void moveToEnd(){
		curr = tail;
	}

	void prev(){
		//��ǰԪ�ص�ǰһ��Ԫ��,��Ϊcurr

		//���currΪhead������ǰһ��Ԫ��
		if (curr == head)
			return;

		Link<E> ltemp = head;
		while (ltemp != curr){
			ltemp = itemp->next;
		}
		//�ҵ�����,��ltemp��ֵ��curr
		curr = ltemp;
	}

	void next(){
		//�ƶ�����һ��
		if (curr != tail)
			curr = curr->next;
	}

	int length(){
		return cnt;//����������Ԫ�ظ���
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
		//�ƶ���ָ��λ��
		if (pos < 0 || pos > cnt)
			cout << "���ڷ�Χ��" << endl;
		curr = head;
		for (int i = 0; i < pos; i++)
			curr = curr->next;
	}

	const E& getValue() const{
		if (curr->next == NULL)
			cout << "û�����Ԫ��" << endl;
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

