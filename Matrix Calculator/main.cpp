#include <iostream>
#include "TwoDMatrix.h"
#include <typeinfo>
#include <limits>


// EG_2020_XXXX

using namespace std;
int choice();
void options_1();
void options_2();
void options_3();
void matrix();
void simultaneous_Equation();



int main()
{
    int option;

    cout << endl << "====================================" << endl << endl;
    cout << "please enter the choice" << endl;
    cout << "1) Matrix calculation " << endl;
    cout << "2) solve simultaneous equation " << endl;
    cin >> option;

    if (option == 1)matrix();
    else if (option == 2)simultaneous_Equation();
    else cout << "Invalid Input!!!!" << endl;
    return 0;
}










void matrix() {

    double n;
    int option;

    option = choice();

    cout << "--------------------------------------" << endl << endl;
    TwoDMatrix m1("M1");
    m1.print();
    TwoDMatrix m2("M2");
    m2.print();
    TwoDMatrix m3;
    switch (option) {

    case 1: {
        TwoDMatrix m4;
        cout << "Enter the scalar value to multiply the matrices : ";
        cin >> n;
        cout << endl << "Scalar multiplication ):" << endl << endl;
        m3 = m1 * n;
        m3.print();
        m4 = m2 * n;
        m4.print();
        break;}

    case 2: {
        TwoDMatrix m4;
        cout << "Enter the scalar value to divide the matrices : ";
        cin >> n;
        cout << endl << "Scalar division):" << endl << endl;
        m3 = m1 / n;
        m3.print();
        m4 = m2 / n;
        m4.print();
        break;

    }
    case 3: {
        cout << endl << "TwoDMatrix addition):" << endl << endl;
        m3 = m1 + m2; //m3= m1.operator+(m2);
        m3.print();
        break;

    }
    case 4: {
        cout << endl << "TwoDMatrix subtraction" << endl << endl;
        m3 = m1 - m2;
        m3.print();
        break;

    }
    case 5: {
        cout << endl << "TwoDMatrix multiplication):" << endl << endl;
        m3 = m1 * m2;
        m3.print();
        break;

    }
    case 6: {
        cout << endl << "TwoDMatrix comparison):" << endl << endl;
        if (m1 == m2)cout << "M1 and M2 are Equal Matrices" << endl << endl;
        else cout << "M1 and M2 are Non equal Matrices" << endl << endl;
        break;

    }
    case 7: {
        cout << endl << "TwoDMatrix inverse):" << endl << endl;
        cout << "determinant of the TwoDMatrix M1 is |M1|  : " << m1.det(m1, row) << endl << endl;
        cout << "The Inverse of the TwoDMatrix M1 is : "; if (m1.INV(m1, m3)) m3.print();
        cout << "\n\ndeterminant of the TwoDMatrix M2 is |M2|  : " << m2.det(m2, row) << endl << endl;
        cout << "The Inverse of the TwoDMatrix M2 is : "; if (m2.INV(m2, m3)) m3.print();
        break;

    }


    }





}

void simultaneous_Equation() {

    double A1, A2, B1, B2, C1, C2;
    cout << endl << endl << "---------- Ax + By = C ----------" << endl << endl;

    cout << "Enter the value for A,B,&C for the equation 1 : \n";
    cout << "A = ";
    cin >> A1;
    cout << "B = ";
    cin >> B1;
    cout << "C = ";
    cin >> C1;
    cout << "\n                " << A1 << "x ";
    if (B1 > 0)cout << "+ ";
    cout << B1 << "y = " << C1 << "  -  Equation (1)" << endl << endl;


    cout << "Enter the value for A,B,&C for the equation 2 : \n";
    cout << "A = ";
    cin >> A2;

    cout << "b = ";
    cin >> B2;

    cout << "C = ";
    cin >> C2;
    cout << "\n                " << A2 << "x ";
    if (B2 > 0)cout << "+ ";
    cout << " " << B2 << "y = " << C2 << "   -  Equation (2)" << endl << endl;


    TwoDMatrix M1(A1, B1, A2, B2);
    TwoDMatrix M2(C1, C2);
    TwoDMatrix M3;
    M1.INV(M1, M3);
    TwoDMatrix M4;
    M4 = M3 * M2;

    double x, y;

    M4.simulataneous(x, y);

    cout << "x = " << x << "\ny = " << y << endl << endl;

}



int choice() {

    double opt, opt_sub;
    int temp;
    options_1();

    cin >> opt;
    if (opt == 1) {

        options_2();

        cin >> opt_sub;
        if (opt_sub == 1)temp = 1;
        else if (opt_sub == 2)temp = 2;
        else temp = 0;

        return temp;


    }

    else if (opt == 2) {

        options_3();
        cin >> opt_sub;

        if (opt_sub == 1)temp = 3;
        else if (opt_sub == 2)temp = 4;
        else if (opt_sub == 3)temp = 5;
        else if (opt_sub == 4)temp = 6;
        else if (opt_sub == 5)temp = 7;
        else temp = 0;

        return temp;
    }
    else return 0;






}


void options_1() {


    cout << endl << "----------------------------------------" << endl;
    cout << endl << "Welcome to the TwoDMatrix Calculator" << endl << endl;

    cout << "Please select the option number to proceed" << endl;
    cout << "press 1 for scalar operations  " << endl;
    cout << "press 2 for TwoDMatrix operations  " << endl;

}

void options_2() {


    cout << endl << "Scalar operations" << endl;
    cout << endl << "-----------------------------" << endl << endl;
    cout << "press 1 for scalar multiplication  " << endl;
    cout << "press 2 for scalar division  " << endl;

}

void options_3() {


    cout << endl << "TwoDMatrix operations" << endl;
    cout << endl << "----------------------" << endl << endl;
    cout << "press 1 for TwoDMatrix addition  " << endl;
    cout << "press 2 for TwoDMatrix subtraction  " << endl;
    cout << "press 3 for TwoDMatrix multiplication  " << endl;
    cout << "press 4 for compare the matrices  " << endl;
    cout << "press 5 for inverse of the matrices  " << endl;

}





