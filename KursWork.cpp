#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <bitset>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <sys/stat.h>
using namespace std;
void clear(void);
bool GROWTH = true;
int COUNT = 0;
int VR = 1;
int HR = 1;
bool h=true;
struct library
{
	int num;
	char name[32];
	char street[18];
	short int home;
	short int flat;
	char data[10];
	library* next;
};
struct library1
{
	char name[32];
	char street[18];
	short int home;
	short int flat;
	char data[10];

};

struct Queue {
	library* head;
	library* tail;
	bool b;
};
struct vertex
{
	library1 base;
	int balance;
	vertex* left;
	vertex* right;
	vertex* dubl;
};
void print(library*& head);
void GBM(vector<pair<char, double>> p, vector<vector<int>>& c);
void Code();
void DigitalSort(library*& head);
void DigitalSortStreet(library*& head);
void DigitalSortFlat(library*& head);
void Delete(library** head);
void BSearch2(library1 arr[], int n, library*& head);
void Pool(library*& head, library1 arr[], int m, char KEY[]);
void B2INSERT(library*& head, vertex*& p);
void DBD(vertex*& root, library*& head);
void obhodLR(vertex* p);
void searchElem(vertex* root);


int main()
{
	vertex* root = NULL;
	int count = 0, code, i = 0;
	FILE* f;
	library* head, * tail;
	head = NULL;
	tail = (library*)&head;
	library1* arr = new library1[4000];
	if (arr == NULL) {
		cout << "Trouble with memory!";
		system("PAUSE");
		return -1;
	}
	f = fopen("testBase4.dat", "rb");
	count = fread(arr, sizeof(library1), 4000, f);
	fclose(f);
	library* p;
	head = NULL;
	char _button;
	
	while(h){clear();
		cout<<"1.Struct unsorted(20)"<<endl<<"2.Struct unsorted"<<endl<<"3.Struct sorted(20)"<<endl<<"4.Struct sorted"<<endl<<"5.Search"<<endl;
		cout<<"6.Tree (DBD)"<<endl<<"7.Code"<<endl<<"8.Exit"<<endl;
	cin>>_button;
	switch(_button){
		case'1':{i=0;
		f = fopen("testBase4.dat", "rb");
	count = fread(arr, sizeof(library1), 4000, f);
	fclose(f);
			int countMax = count / 20;
			count = 1;
				while (i < 4000) {
			int temp = i;
			cout << setw(20) << "Name" << setw(25) << "Street" << setw(17) << "Home" << setw(15) << "Flat" << setw(14) << "Date " << endl;
			for (i = temp; i < temp + 20; i++) {
				cout << setw(4) << i + 1 << ' ' << setw(15) << arr[i].name << ' ' << setw(14) << arr[i].street << setw(6) << arr[i].home << setw(14) << ' ' << arr[i].flat << setw(18) << arr[i].data;
				cout << endl;
			}
			cout << "Page " << count << ' ' << "of " << "200" << endl << "To view the next page press n, previous press p, exit - esc" << endl;
			code = _getche();
			clear();
			if (code == 'n') {
				if (count == 200)i = temp;
				else count++;
			}
			else if (code == 27) {
				break;
			}
			else if (code == 'p' && i >= 40) {
				count--;
				i -= 40;
			}
			else if ( code != 'n' || code != 'p') i = temp;
			}break;}
			
		case'2':{
		i=0;
		f = fopen("testBase4.dat", "rb");
		count = fread(arr, sizeof(library1), 4000, f);
		fclose(f);
		cout << setw(20) << "Name" << setw(25) << "Street" << setw(17) << "Home" << setw(15) << "Flat" << setw(14) << "Date " << endl;
			while (i < 4000) {
			
			
				cout << setw(4) << i + 1 << ' ' << setw(15) << arr[i].name << ' ' << setw(14) << arr[i].street << setw(6) << arr[i].home << setw(14) << ' ' << arr[i].flat << setw(18) << arr[i].data;
				cout << endl;
			
			i++;
			
			}
			cout<<endl<<"END!!!!!!!!!!!!!!!!!!!!!!!";
			code = _getche();
			if (code == 27) {
			clear();	break;
				}
				break;}
				////////////////////////////////////////////////////////////////////////////////////////////
		case'3':
		{
			for (i = 3999; i >= 0; i--) {
		p = new library;
		if (p == NULL) {
			cout << "Trouble with memory!";
			system("PAUSE");
			return -1;
		}
		strcpy(p->name, arr[i].name);
		strcpy(p->street, arr[i].street);
		p->home = arr[i].home;
		p->flat = arr[i].flat;
		strcpy(p->data, arr[i].data);
		p->next = head;
		head = p;
	}
	cout << endl;
	int countMax = count / 20;
	count = 1;
	p = head;
	DigitalSortFlat(head);
	DigitalSort(head);

	DigitalSortStreet(head);
	p = head;
	for (i = 0; i < 4000; i++) {

		strcpy(arr[i].name, p->name);
		strcpy(arr[i].street, p->street);
		arr[i].home = p->home;
		arr[i].flat = p->flat;
		strcpy(arr[i].data, p->data);
		p = p->next;
	}i=0;
		while (i < 4000) {
			int temp = i;
			cout << setw(20) << "Name" << setw(25) << "Street" << setw(17) << "Home" << setw(15) << "Flat" << setw(14) << "Date " << endl;
			for (i = temp; i < temp + 20; i++) {
				cout << setw(4) << i + 1 << ' ' << setw(15) << arr[i].name << ' ' << setw(14) << arr[i].street << setw(6) << arr[i].home << setw(14) << ' ' << arr[i].flat << setw(18) << arr[i].data;
				cout << endl;
			}
			cout << "Page " << count << ' ' << "of " << countMax << endl << "To view the next page press n, previous press p, exit - esc" << endl;
			code = _getche();
			clear();
			if (code == 'n') {
				if (count == 200)i = temp;
				else count++;
			}
			else if (code == 27) {
				break;
			}
			else if (code == 'p' && i >= 40) {
				count--;
				i -= 40;
			}
			else if ( code != 'n' || code != 'p') i = temp;
			}
		clear();Delete(&head);break;	
		}	
		case'4':{for (i = 3999; i >= 0; i--) {
		p = new library;
		if (p == NULL) {
			cout << "Trouble with memory!";
			system("PAUSE");
			return -1;
		}
		strcpy(p->name, arr[i].name);
		strcpy(p->street, arr[i].street);
		p->home = arr[i].home;
		p->flat = arr[i].flat;
		strcpy(p->data, arr[i].data);
		p->next = head;
		head = p;
	}
	cout << endl;
	int countMax = count / 20;
	count = 1;
	p = head;
	DigitalSortFlat(head);
	DigitalSort(head);

	DigitalSortStreet(head);
	p = head;
	for (i = 0; i < 4000; i++) {

		strcpy(arr[i].name, p->name);
		strcpy(arr[i].street, p->street);
		arr[i].home = p->home;
		arr[i].flat = p->flat;
		strcpy(arr[i].data, p->data);
		p = p->next;
	}
		i=0;	cout << setw(20) << "Name" << setw(25) << "Street" << setw(17) << "Home" << setw(15) << "Flat" << setw(14) << "Date " << endl;
			while (i < 4000) {
				cout << setw(4) << i + 1 << ' ' << setw(15) << arr[i].name << ' ' << setw(14) << arr[i].street << setw(6) << arr[i].home << setw(14) << ' ' << arr[i].flat << setw(18) << arr[i].data;
				cout << endl;
				i++;
			}
			cout<<endl<<"END!!!!!!!!!!!!!!!!!!!!!!!";
			code = _getche();
			if (code == 27) {
			clear();	break;
				}
		Delete(&head);break;}
		/////////////////////////////////////////////////////////	
		case'5':{
			for (i = 3999; i >= 0; i--) {
		p = new library;
		if (p == NULL) {
			cout << "Trouble with memory!";
			system("PAUSE");
			return -1;
		}
		strcpy(p->name, arr[i].name);
		strcpy(p->street, arr[i].street);
		p->home = arr[i].home;
		p->flat = arr[i].flat;
		strcpy(p->data, arr[i].data);
		p->next = head;
		head = p;
	}
	cout << endl;
	int countMax = count / 20;
	count = 1;
	p = head;
	DigitalSortFlat(head);
	DigitalSort(head);

	DigitalSortStreet(head);
	p = head;
	for (i = 0; i < 4000; i++) {

		strcpy(arr[i].name, p->name);
		strcpy(arr[i].street, p->street);
		arr[i].home = p->home;
		arr[i].flat = p->flat;
		strcpy(arr[i].data, p->data);
		p = p->next;
	}i=0;
	Delete(&head);
			BSearch2(arr, 4000, head);	
			code = _getche();
			if (code == 27) {
			clear();	break;
				}
			break;
		}
		case'6':{
			
		if(head!=NULL){
			DBD(root, head);
	searchElem(root);
	}
			else cout<<"sozdayte ochered";
		code = _getche();
			if (code == 27) {
			clear();	break;
				}
				break;}
		
		case'7':{
		Code();
		code = _getche();
			if (code == 27) {
			clear();	break;
				}
			break;
		}
		case'8':{
		h=false;	break;
		}
}}

	return 0;
}

void clear(void)
{
	system("cls");
}
void DigitalSortStreet(library*& head) {
	library* p; library* t=NULL;
	int j, i, l = sizeof(p->street);
	int d;
	Queue Q[256];
	bool b;
	for (j = l - 1; j >= 0; j--) {
		for (i = 0; i < 256; i++) Q[i].b = false;
		p = head;
		while (p != NULL) {
			d = int(p->street[j]) + 128;
			if (!Q[d].b) {
				Q[d].head = Q[d].tail = p;
				Q[d].b = true;
			}
			else {
				Q[d].tail->next = p;
				Q[d].tail = p;
			}
			p = p->next;
		}
		b = false;
		for (i = 0; i < 256; i++) {
			if (Q[i].b) {
				if (!b) {
					t = Q[i].head;
					b = true;
				}
				else p->next = Q[i].head;
				p = Q[i].tail;
			}
		}

		head = t;
		p->next = NULL;
	}
}

void DigitalSort(library*& head)
{
	library* p;
	library* t=NULL;
	int j, i, l = sizeof(p->home);
	int d;
	Queue Q[256];
	bool b;
	for (j = l - 1; j >= 0; j--) {
		for (i = 0; i < 256; i++) Q[i].b = false;
		p = head;
		while (p != NULL) {
			d = ((int)(p->home));
			if (!Q[d].b) {
				Q[d].head = Q[d].tail = p;
				Q[d].b = true;
			}
			else {
				Q[d].tail->next = p;
				Q[d].tail = p;
			}
			p = p->next;
		}
		b = false;
		for (i = 0; i < 256; i++) {
			if (Q[i].b) {
				if (!b) {
					t = Q[i].head;
					b = true;
				}
				else p->next = Q[i].head;
				p = Q[i].tail;
			}
		}
		head = t;
		p->next = NULL;

	}
}

void DigitalSortFlat(library*& head)
{
	library* p;library *t=NULL;
	int j, i, l = sizeof(p->flat);
	int d;
	Queue Q[256];
	bool b;
	for (j = l - 1; j >= 0; j--) {
		for (i = 0; i < 256; i++) Q[i].b = false;
		p = head;
		while (p != NULL) {
			d = ((int)(p->flat));
			if (!Q[d].b) {
				Q[d].head = Q[d].tail = p;
				Q[d].b = true;
			}
			else {
				Q[d].tail->next = p;
				Q[d].tail = p;
			}
			p = p->next;
		}
		b = false;
		for (i = 0; i < 256; i++) {
			if (Q[i].b) {
				if (!b) {
					t = Q[i].head;
					b = true;
				}
				else p->next = Q[i].head;
				p = Q[i].tail;
			}
		}
		head = t;
		p->next = NULL;

	}
}

void Delete(library** head) {
	library* p = *head;
	while (p != NULL) {
		*head = p->next;
		free(p);
		p = *head;
	}
}



void BSearch2(library1 arr[], int n, library*& head)
{
	char KEY[3];
	cout<<"Input KEY(street) : ";
	cin >> KEY;
	int i = 0;
	int L = 1, R = n, Find = 0, m;
	while (L < R)
	{

		m = (int)((L + R) / 2);
		i = 0;
		if ((arr[m].street[i] < KEY[i])) L = m + 1;
		
		else R = m;

		
		if ((arr[m].street[i] == KEY[i]) && (arr[m].street[i + 1] == KEY[i + 1]) && (arr[m].street[i + 2] == KEY[i + 2])) {
			while ((arr[m].street[i] == KEY[i]) && (arr[m].street[i + 1] == KEY[i + 1]) && (arr[m].street[i + 2] == KEY[i + 2])) {

				m = m + 1;
			}

			Find = 1;
			m = m - 1;
			break;

		}

	}
	if (Find == 1)Pool(head, arr, m, KEY);
	else cout<<"Incorrect KEY";


}

void Pool(library*& head, library1 arr[], int m, char KEY[]) {

	library* p = head;

	int i = 0;
	while ((arr[m].street[i] == KEY[i]) && (arr[m].street[i + 1] == KEY[i + 1]) && (arr[m].street[i + 2] == KEY[i + 2])) {
		p = new library;
		p->num = (m + 1);
		strcpy(p->name, arr[m].name);
		strcpy(p->street, arr[m].street);
		p->home = arr[m].home;
		p->flat = arr[m].flat;
		strcpy(p->data, arr[m].data);
		p->next = head;
		head = p;
		m = m - 1;

	}

	print(head);
}

void print(library*& head) {
	library* p = head;
	int  c = 0;
	for (; p != NULL; p = p->next, c++) {
		cout << ' '<<p->num << setw(5) << ' ' << setw(15) << p->name << ' ' << setw(14) << p->street << setw(6) << p->home << setw(14) << ' ' << p->flat << setw(18) << p->data;
		cout << endl;


	}
}
void B2INSERT(library *&head, vertex*& p) {
	vertex* q = NULL;
	vertex* k = NULL;
	bool f=true;
	if (!p) {
		p = new vertex;
		strcpy(p->base.data,head->data);
		p->base.flat=head->flat;
		p->base.home=head->home;
		strcpy(p->base.name,head->name);
		
		strcpy(p->base.street,head->street);
		p->left = NULL; p->right = NULL;p->dubl=NULL; p->balance = 0; VR = 1;
	}
	else
		if (p->base.flat > head->flat) {
			B2INSERT(head, p->left);
			if (VR == 1) {
				if (p->balance == 0) {
					q = p->left; p->left = q->right;
					q->right = p; p = q; q->balance = 1; VR = 0; HR = 1;
				}
				else
				{
					p->balance = 0; VR = 1; HR = 0;
				}
			}
			else HR = 0;
		}
		else
			if (p->base.flat < head->flat) {
				B2INSERT(head, p->right);
				if (VR == 1) { p->balance = 1; HR = 1; VR = 0; }
				else if (HR == 1) {
					if (p->balance == 1) {
						q = p->right; p->balance = 0;
						q->balance = 0; p->right = q->left;
						q->left = p; p = q; VR = 1; HR = 0;
					}
					else HR = 0;
				}
			}
			else if(p->base.flat == head->flat){
				k=p;
				while(k->dubl!=NULL){
				k=k->dubl;}
				
				
				k->dubl= new vertex;
				k=k->dubl;
				
				
				
				strcpy(k->base.data,head->data);
				k->base.flat=head->flat;
				k->base.home=head->home;
				strcpy(k->base.name,head->name);
				
				strcpy(k->base.street,head->street);
			
				k->dubl=NULL;
				
				
				
			}
}

void DBD(vertex*& root,library*& head)
{
	
	for (int i = 0; head!=NULL; head=head->next) {
		B2INSERT(head, root);
	}
	obhodLR(root);
}



void obhodLR(vertex* p)
{	vertex* q = NULL;
	if (p != NULL) {
		obhodLR(p->left);
		cout << ' ' <<  setw(5) << ' ' << setw(15) << p->base.name << ' ' << setw(14) << p->base.street << setw(6) << p->base.home << setw(14) << ' ' << p->base.flat << setw(18) << p->base.data;
		cout << endl;
		q=p;
		while(p->dubl!=NULL){
		cout << ' ' <<  setw(5) << ' ' << setw(15) << p->base.name << ' ' << setw(14) << p->base.street << setw(6) << p->base.home << setw(14) << ' ' << p->base.flat << setw(18) << p->base.data<< endl;
		p=p->dubl;
		}
		p=q;
		cout << endl;
		obhodLR(p->right);
	}
}

void searchElem(vertex* root)
{	int X;
	cout<<"input Key(flat) : ";
	cin>>X;
	while (root != NULL) {
		if (X < root->base.flat) {
			root = root->left;
		}
		else if (X > root->base.flat) {
			root = root->right;
		}
		else {
			break;
		}
	}

	if (root != NULL) {
		while(root!=NULL){
			cout<< ' ' <<  setw(5) << ' ' << setw(15) << root->base.name << ' ' << setw(14) << root->base.street << setw(6) << root->base.home << setw(14) << ' ' << root->base.flat << setw(18) << root->base.data << endl;
			root=root->dubl;
		}
	}
	else {
		cout << "KEY incorrect" << endl;
	}
}

void Code() {
	
    map<char, int> _map;
    ifstream input("testBase4.dat");
    int count = 0;
    double length = 0;
    while (true) {
        char c = input.get();
        if (input.eof()) {
            break;
        }
        count++;
        _map[c]++;
    }
    vector<pair<char, double>> p;
    for (auto i : _map) {
        p.push_back({i.first, i.second / (double)count});
    }
    double entropy = 0;
    for (auto i : p) {
        entropy += i.second * (-log2(i.second));
    }
    vector<vector<int>> c(p.size());
    sort(p.begin(), p.end(), [](pair<char, double> a, pair<char, double> b) {
        return a.first < b.first;
    });
    GBM(p, c);
    int mx = 0;
    for (auto i : c) {
        mx = max(mx, (int)i.size());
    }
    for (int i = 0; i < p.size(); i++) {
        cout << bitset<sizeof(p[i].first) * CHAR_BIT>(p[i].first) <<" "<< setw(8) << p[i].second << " ";
        for (auto j : c[i]) {
            cout << j;
        }
        for (int j = 0; j < mx - c[i].size() + 3; j++) {
            cout << " ";
        }
        cout << setw(5) << c[i].size() << endl;
    }
    for (int i = 0; i < p.size(); i++) {
        length += p[i].second * c[i].size();
    }
    cout << endl << endl << "entropiya: " << entropy << endl << "Sr dlina:  " << length << endl << endl << endl;
	_map.clear();
    p.clear();
    c.clear();
    

}



void GBM(vector<pair<char, double>> p, vector<vector<int>>& c)
{
    double pr = 0;
    vector<double> q(p.size());
    for (int i = 0; i < p.size(); i++) {
        q[i] = pr + p[i].second / 2;
        pr += p[i].second;
    }
    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j < -floor(log2(p[i].second)) + 1; j++) {
            q[i] *= 2;
            c[i].push_back((int)q[i]);
            q[i] = (q[i] > 1 ? q[i] - 1 : q[i]);
        }
    }
}
