#include "TwoDMatrix.h"



//Default Constructor

TwoDMatrix::TwoDMatrix()
{
    isDynamic = false;
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {

            x[i][j] = 0;

        }


    }

}

//overloaded default constructor
TwoDMatrix::TwoDMatrix(double a, double b, double c, double d)
{
    isDynamic = false;
    x[0][0] = a;
    x[0][1] = b;
    x[1][0] = c;
    x[1][1] = d;


}

//overloaded default constructor
TwoDMatrix::TwoDMatrix(double a, double b)
{
    isDynamic = false;
    x[0][0] = a;
    x[1][0] = b;
    x[0][1] = 0;
    x[1][1] = 0;



}

//Overloaded Constructor

TwoDMatrix:: TwoDMatrix(string nm) {

    isDynamic = false;

    name = nm;
    cout << endl << endl;
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {
            cout << "Enter the a" << i + 1 << j + 1 << " element of the TwoDMatrix " << name << " : ";
            // cin >> x[i][j];
            while (!(cin >> x[i][j])) {

                cout << "enter a valid input please" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }

        }


    }


    cout << endl << endl << "TwoDMatrix " << name << " : " << endl << endl;


}



// Overloaded = Operator

TwoDMatrix & TwoDMatrix :: operator =(TwoDMatrix & m) {



    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {

            x[i][j] = m.x[i][j];
        }
    }
    killGarbage(&m);
    return *this;

}


//Copy Constructor
TwoDMatrix :: TwoDMatrix(TwoDMatrix & m) {


    cout << endl << endl;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {

            x[i][j] = m.x[i][j];
        }

    }
    killGarbage(&m);

}

//Overloaded + Operator

TwoDMatrix & TwoDMatrix :: operator +(TwoDMatrix & m) {

    cout << "TwoDMatrix ";
    cout << name << " + " << "TwoDMatrix " << m.name << " : " << endl;

    TwoDMatrix * temp = new TwoDMatrix();
    temp->isDynamic = true;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {

            temp->x[i][j] = x[i][j] + m.x[i][j];
        }
    }

    return *temp;
}

TwoDMatrix & TwoDMatrix :: operator -(TwoDMatrix & m) {

    cout << "TwoDMatrix ";
    cout << name << " - " << "TwoDMatrix " << m.name << " : " << endl;

    TwoDMatrix * temp = new TwoDMatrix();
    temp->isDynamic = true;


    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {

            temp->x[i][j] = x[i][j] - m.x[i][j];
        }
    }

    return *temp;

}

//overloaded * operator

TwoDMatrix & TwoDMatrix :: operator *(TwoDMatrix & m) {



    TwoDMatrix * temp = new TwoDMatrix();
    temp->isDynamic = true;


    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {


            for (int k = 0; k < row; k++) {

                temp->x[i][j] += (x[i][k] * m.x[k][j]);

            }
        }
    }

    return *temp;

}



TwoDMatrix & TwoDMatrix ::operator *(int n) {

    cout << "TwoDMatrix ";
    cout << name << " * " << n << " : " << endl;

    TwoDMatrix * temp = new TwoDMatrix();
    temp->isDynamic = true;


    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {

            temp->x[i][j] = (x[i][j] * n);


        }
    }

    return *temp;



}


TwoDMatrix & TwoDMatrix ::operator /(int n) {

    cout << "TwoDMatrix ";
    cout << name << " / " << n << " : " << endl;

    TwoDMatrix * temp = new TwoDMatrix();
    temp->isDynamic = true;


    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn; j++) {

            temp->x[i][j] = (x[i][j] / n);


        }
    }

    return *temp;



}




bool TwoDMatrix :: operator ==(TwoDMatrix & m) {

    int counting = 0;
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < coloumn;j++) {

            if (x[i][j] != m.x[i][j])counting++;
        }

    }

    if (counting)return false;

    else return true;


}

//overloaded != operator

bool TwoDMatrix :: operator !=(TwoDMatrix & m) {

    return !(*this == m);



}






void TwoDMatrix::print() {



    for (int i = 0; i < row; i++) {
        cout << "\t[ ";

        for (int j = 0;j < coloumn; j++) {

            cout << x[i][j];
            if (j == row - 1)continue;
            cout << "\t\t";

        }
        cout << "]" << endl;


    }


    cout << endl << endl;




}

void TwoDMatrix::killGarbage(TwoDMatrix * ptr) {


    if (ptr->isDynamic == true)delete ptr;

}




void TwoDMatrix::cofactor(TwoDMatrix & m, TwoDMatrix & temp, int p, int q, int n) {

    int i = 0, j = 0;
    for (int rw = 0; rw < n; rw++) {
        for (int column = 0; column < n; column++) {
            if (rw != p && column != q) {
                temp.x[i][j++] = m.x[rw][column];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }






}


float TwoDMatrix::det(TwoDMatrix & m, int n) {

    int Det = 0;
    if (n == 1)
        return m.x[0][0];
    TwoDMatrix cofactorMat;
    int sign = 1;
    for (int firstRow = 0; firstRow < n; firstRow++) {
        cofactor(m, cofactorMat, 0, firstRow, n);
        Det += sign * m.x[0][firstRow] * det(cofactorMat, n - 1);
        sign = -sign;
    }
    return Det;




}
//to find adjoint TwoDMatrix

void TwoDMatrix::ADJ(TwoDMatrix & m, TwoDMatrix & adj)
{
    if (row == 1) {
        adj.x[0][0] = 1; return;
    }
    int s = 1;
    TwoDMatrix t;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {

            cofactor(m, t, i, j, row);
            s = ((i + j) % 2 == 0) ? 1 : -1;
            adj.x[j][i] = (s) * (det(t, row - 1));
        }
    }
}

bool TwoDMatrix::INV(TwoDMatrix & M, TwoDMatrix & inv) {
    int Det = det(M, row);
    if (Det == 0) {
        cout << "can't find its inverse";
        return false;
    }
    cout << endl << endl;
    TwoDMatrix adj; ADJ(M, adj);
    for (int i = 0; i < row; i++) for (int j = 0; j < row; j++) inv.x[i][j] = adj.x[i][j] / float(Det);
    return true;
}

void TwoDMatrix::simulataneous(double& m, double& n) {

    m = x[0][0];
    n = x[1][0];



}

//default destructor

TwoDMatrix::~TwoDMatrix()
{

    //dtor
}

