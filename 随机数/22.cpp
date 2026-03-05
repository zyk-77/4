#include<bits/stdc++.h>
using namespace std;
int f[6] = { 0,1,2,3,4,5 };
class Chainnode {
public:
	int x;
	Chainnode* next,*last;
 // Make the constructor accessible
	Chainnode(int i) { x = i; next = nullptr; last = nullptr; }
};
Chainnode* ha, * hb, * hc,*e,*index,*ia,*ib;

void outputa() {
	ia = ha;
	while (1) {
		cout << ia->x << ' ';
		ia = ia->next;
		if (ia == ha) break;
	}
}
void outputb() {
	ib = hb;
	while (1) {
		cout << ib->x << ' ';
		ib = ib->next;
		if (ib == hb) break;
	}
}
void outputc() {
	index = hc;
	while (1) {
		cout << index->x << ' ';
		index = index->next;
		if (index == hc) break;
	}
}

int main() {
	for (int i = 0; i < 6; ++i) {
		e = new Chainnode(f[i]);
		if (i == 0) hc = e,index=hc;
		else {
			index->next = e;
			index->next->last = index;
			index = e;
		}
	}
	index->next = hc;
	hc->last = index;
	index = hc;
	int m = 0;
	while (1) {                 //split方法
		if (m % 2) {
			if (!ha) {
				ha = index;
				ia = ha;
			}
			else {
				ia->next = index;
				ia->next->last = ia;
				ia = ia->next;
			}
		}
		else {
			if (!hb) {
				hb = index;
				ib = hb;
			}
			else {
				ib->next = index;
				ib->next->last = ib;
				ib = ib->next;
			}
		}
		index = index->next;
		m++;
		if (index == hc) break;
	}                           //split方法
	ia->next = ha;
	ha->last = ia;
	ib->next = hb;
	hb->last = ib;
	cout << "a:";
	outputa();
	cout << endl;
	cout << "b:";
	outputb();
	cout << endl;
	cout << "c:";
	outputc();
}