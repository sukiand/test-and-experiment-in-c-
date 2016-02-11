#include <iostream>
#include <string>
#include <malloc.h>
#include <vector>

using namespace std;

struct structNode{
	char var;
	struct structNode* next;
};

typedef struct structNode linkNode;
typedef linkNode* Node;

class NodeCal{
public:
	Node headp;
	Node crossp;
	NodeCal(string s);
	bool isLoop();
	int calLoopLength();
	int calBranchLength();
	void printNode();
};

NodeCal::NodeCal(string s){
	headp = (Node)malloc(sizeof(linkNode));
	headp->next = NULL;
	vector<char> temp;
	Node p1 = headp, p2 = headp;
	for (int i = 0; i < s.length(); i++){
		p2 = (Node)malloc(sizeof(linkNode));
		p2->var = s[i];
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	p2->next = headp->next->next;
}

bool NodeCal::isLoop(){
	Node p_slow = headp;
	Node p_fast = headp;
	while (p_fast != NULL){
		p_slow = p_slow->next;
		p_fast = p_fast->next;
		if (p_fast == NULL){
			return false;
		}
		p_fast = p_fast->next;
		if (p_slow == p_fast){
			crossp = p_fast;
			return true;
		}
	}
	return false;
}

int NodeCal::calLoopLength(){
	if (crossp == NULL){
		return -1;
	}
	Node p = headp;
	int length = 0;
	while (p != crossp){
		p = p->next;
		length++;
	}
	return length;
}

int NodeCal::calBranchLength(){

}

void NodeCal::printNode(){
	Node p = headp;
	while (p->next != NULL){
		cout << p->next->var;
		p = p->next;
	}
}

int main(int argc, char **argv){
	NodeCal test = NodeCal("12345");
	if (test.isLoop()){
		cout << "\tyes" << endl;
	}
	else {
		test.printNode();
		cout << "\tNo" << endl;
	}
	getchar();
}