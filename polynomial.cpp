#include<iostream>
#include<cmath>
using namespace std;

class node {
	int exp;
	int coef;
	node *next;
	friend class poly;
};

class poly {
	node *head;
public:
	poly() {
		head = new node();
		head->next = head;
	}

	void create_poly();
	void display_poly();
	void add_poly(poly p1, poly p2);
	void eval_poly();
};

void poly::create_poly() {
	node *ptr;
	int deg;
	cout << "Enter degree of the polynomial: ";
	cin >> deg;
	node *last;
	last = head;

	for (int i = deg; i >= 0; i--) {
		ptr = new node();
		cout << "Enter coefficient of x^" << i << ": ";
		cin >> ptr->coef;
		ptr->exp = i;

		last->next = ptr;
		ptr->next = head;
		last = ptr;
	}
}

void poly::display_poly() {
	node *temp;
	temp = head->next;
	while (temp != head) {
		cout << temp->coef;
		if (temp->exp > 0) {
			cout << "x^" << temp->exp;
		}
		if (temp->next != head && temp->next->coef > 0) {
			cout << " + ";
		}
		temp = temp->next;
	}
	cout << endl;
}

void poly::add_poly(poly p1, poly p2) {
	node *t1;
	node *t2;
	node *t3;

	t1 = p1.head->next;
	t2 = p2.head->next;
	t3 = this->head;

	while (t1 != p1.head || t2 != p2.head) {
		node *ptr = new node();
		if (t1->exp == t2->exp) {
			ptr->coef = t1->coef + t2->coef;
			ptr->exp = t1->exp;
			t1 = t1->next;
			t2 = t2->next;
		}
		else if (t1->exp > t2->exp) {
			ptr->coef = t1->coef;
			ptr->exp = t1->exp;
			t1 = t1->next;
		}
		else {
			ptr->coef = t2->coef;
			ptr->exp = t2->exp;
			t2 = t2->next;
		}

		t3->next = ptr;
		t3 = t3->next;
	}
	t3->next = head; // Connect the last term to the head.
}

void poly::eval_poly() {
	int x;
	int sum = 0;
	node *temp = head->next;

	cout << "Enter value of x: ";
	cin >> x;

	while (temp != head) {
		sum += temp->coef * pow(x, temp->exp);
		temp = temp->next;
	}

	cout << "Result of sum of polynomials is: " << sum << endl;
}

int main() {
	poly p1, p2, p3;
	int choice;

	do {
		cout << "\nMenu:\n";
		cout << "1. Enter polynomials\n";
		cout << "2. Display polynomials\n";
		cout << "3. Add polynomials\n";
		cout << "4. Evaluate polynomial\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter 1st polynomial" << endl;
				p1.create_poly();
				cout << "Enter 2nd polynomial" << endl;
				p2.create_poly();
				break;
			case 2:
				cout << "1st polynomial: ";
				p1.display_poly();
				cout << "2nd polynomial: ";
				p2.display_poly();
				break;
			case 3:
				p3.add_poly(p1, p2);
				cout << "Addition of polynomials: ";
				p3.display_poly();
				break;
			case 4:
				p3.eval_poly();
				break;
			case 5:
				cout << "Exiting program." << endl;
				break;
			default:
				cout << "Invalid choice. Please enter a valid option." << endl;
		}
	} while (choice != 5);

	return 0;
}
