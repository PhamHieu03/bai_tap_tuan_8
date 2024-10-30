#include<bits/stdc++.h>
using namespace std;
struct node {
	int he_so;
	int so_mu;
	node* next;
};

void them(node** head, int he_so, int so_mu) {
	if (he_so == 0) {
		return;
	}
	node* newNode = new node{ he_so, so_mu, NULL };
	if (!(*head) || (*head)->so_mu < so_mu) {
		newNode->next = *head;
		*head = newNode;
	}
	else {
		node* tam = *head;
		node* firt = NULL;
		while (tam && tam->so_mu > so_mu) {
			firt = tam;
			tam = tam->next;
		}
		if (tam && tam->so_mu == so_mu) {
			tam->he_so += he_so;
			delete newNode;
			if (tam->he_so == 0) {
				if (firt) firt->next = tam->next;
				else *head = tam->next;
				delete tam;
			}
		}
		else {
			newNode->next = tam;
			if (firt) firt->next = newNode;
			else *head = newNode;
		}
	}
}
void in(node* head) {
	node* tam = head;
	while (tam) {
		cout << tam->he_so << "x^" << tam->so_mu;
		tam = tam->next;
		if (tam) cout << " + ";
	}
	cout << endl;
}
void giai_phong(node** head) {
	while (head) {
		node* tam = *head;
		tam = (*head)->next;
		delete tam;
	}
}
int main() {
	node* dathuc = nullptr;
	int he_so, so_mu;
	char choice;


	do {
		cout << "nhap he so: ";
		cin >> he_so;
		cout << "nhap so mu: ";
		cin >> so_mu;
		them(&dathuc, he_so, so_mu);
		cout << "them phan tu khac (m/n): ";
		cin >> choice;
	} while (choice == 'm' || choice == 'M');
	cout << "da thuc vua nhap la: ";
	in(dathuc);
	giai_phong(&dathuc);
	return 0;
}