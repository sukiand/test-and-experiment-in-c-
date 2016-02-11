#include <iostream>
#include <malloc.h>
#include <vector>

using namespace std;

struct Node{
	int var;
	Node * next;
	Node(int x) :var(x), next(nullptr){}
};
typedef Node* NodeP;

class sortedList{
public:
	NodeP headp;
	NodeP p;
	sortedList(vector<int> s){
		headp = new Node(-1);
		p = headp;
		vector<int>::iterator i;
		for (i = s.begin(); i != s.end(); i++){
			//p->next = (NodeP)malloc(sizeof(Node));
			//p = p->next;
			//p->var = *i;
			//p->next = NULL;
			p->next = new Node(*i);
			p = p->next;
		}
	}
	void printList(){
		NodeP p = headp->next;
		while (p != NULL){
			cout << p->var;
			cout << " ";
			p = p->next;
		}
		cout << endl;
	}

	/*sortedList operator+(sortedList &k){
		if (headp->next == nullptr){
			return k.headp;
		}
		if (k.headp->next == nullptr){
			return headp;
		}
		NodeP r = new Node(-1);
		NodeP rp = r;
		for (NodeP p1 = headp->next, p2 = k.headp->next;
			p1 != nullptr || p2 != nullptr;rp = rp ->next){
			const int a = p1 == nullptr ? INT_MAX : p1->var;
			const int b = p2 == nullptr ? INT_MAX : p2->var;
			if (a < b){
				rp->next = p1;
				p1 = p1 == nullptr ? nullptr : p1->next;
			}
			else {
				rp->next = p2;
				p2 = p2 == nullptr ? nullptr : p2->next;
			}
		}
		return r;
	}*/
};

NodeP mergeSortedList(NodeP head1, NodeP head2){
	/*NodeP p1 = head1, p2 = head1->next;
	NodeP t1 = head2, t2 = head2->next;
	while (p2 != NULL && t2 != NULL)
	{
	if (t2->var < p2->var){
	t1->next = t2->next;
	p1->next = t2;
	t2->next = p2;
	p1 = t2;
	t2 = t1->next;
	}
	else{
	p1 = p1->next;
	p2 = p2->next;
	}
	}
	if (p2 == NULL)
	{
	p1->next = t2;
	}
	return head1;*/

	if (head1->next == nullptr){
		return head2;
	}
	if (head2->next == nullptr){
		return head1;
	}
	NodeP r = new Node(-1);
	NodeP rp = r;
	for (NodeP p1 = head1->next, p2 = head2->next;
		p1 != nullptr || p2 != nullptr; rp = rp->next){
		const int a = p1 == nullptr ? INT_MAX : p1->var;
		const int b = p2 == nullptr ? INT_MAX : p2->var;
		if (a < b){
			rp->next = p1;
			p1 = p1 == nullptr ? nullptr : p1->next;
		}
		else {
			rp->next = p2;
			p2 = p2 == nullptr ? nullptr : p2->next;
		}
	}
	return r;
}

int main(int argc, char ** argv){
	vector<int> a = { 2, 5, 7, 9 };
	vector<int> b = { 1 };
	sortedList l1 = sortedList(a);
	sortedList l2 = sortedList(b);
	l1.printList();
	l2.printList();
	l1.headp = mergeSortedList(l1.headp, l2.headp);
	l1.printList();
	getchar();
}