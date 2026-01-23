//Create a C++ program to add two polynomials using a linked list. Each node in the linked list should represent a term in the polynomial, with fields for the coefficient and exponent. The program should read two polynomials from the user, add them, and display the resulting polynomial.

#include <iostream>
using namespace std;

// Node structure to store each term of the polynomial
struct Node {
    int coeff; // Coefficient of the term
    int exp;   // Exponent of the term
    Node* next;
};

// Function to create a new term node
Node* createNode(int coeff, int exp) {
    Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert term into polynomial linked list
void insertTerm(Node*& poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);

    if (poly == nullptr) {
        poly = newNode;
    } else {
        Node* temp = poly;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node *p1 = poly1, *p2 = poly2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exp == p2->exp) {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                insertTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // Add remaining terms of polynomial 1
    while (p1 != nullptr) {
        insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Add remaining terms of polynomial 2
    while (p2 != nullptr) {
        insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    Node* temp = poly;
    while (temp != nullptr) {
        cout << temp->coeff << "x^" << temp->exp;
        temp = temp->next;
        if (temp != nullptr && temp->coeff > 0)
            cout << " + ";
    }
    cout << endl;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // Polynomial 1: 5x^3 + 4x^2 + 2x^1
    insertTerm(poly1, 5, 3);
    insertTerm(poly1, 4, 2);
    insertTerm(poly1, 2, 1);

    // Polynomial 2: 3x^3 + 2x^2 + 3x^0
    insertTerm(poly2, 3, 3);
    insertTerm(poly2, 2, 2);
    insertTerm(poly2, 3, 0);

    cout << "Polynomial 1: ";
    displayPolynomial(poly1);

    cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    // Add the two polynomials
    Node* result = addPolynomials(poly1, poly2);

    cout << "Sum of the two polynomials: ";
    displayPolynomial(result);

    return 0;
}
