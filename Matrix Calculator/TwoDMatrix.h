#pragma once

#include <iostream>
#define row 2
#define coloumn 2


using namespace std;


class TwoDMatrix
{
    public:
        TwoDMatrix();
        TwoDMatrix(string index);
        TwoDMatrix(double  a,double b,double c,double d);
        TwoDMatrix(double  a,double b);
        TwoDMatrix & operator =(TwoDMatrix & m);
        TwoDMatrix & operator +(TwoDMatrix & m);
        TwoDMatrix & operator -(TwoDMatrix & m);
        TwoDMatrix & operator *(TwoDMatrix & m);
        TwoDMatrix & operator /(TwoDMatrix & m);

        TwoDMatrix & operator *(int n);
        TwoDMatrix & operator /(int n);

        float det(TwoDMatrix & m,int n);
        void cofactor(TwoDMatrix & m,TwoDMatrix & temp,int p,int q,int n);
        void  ADJ(TwoDMatrix & m,TwoDMatrix & adj);
        bool  INV(TwoDMatrix & M, TwoDMatrix & inv);
        void simulataneous(double& m,double& n);

        bool operator ==(TwoDMatrix & m);
        bool operator !=(TwoDMatrix & m);
        TwoDMatrix(TwoDMatrix & m);

        virtual ~TwoDMatrix();
        void print();

    protected:
    private:
        void killGarbage(TwoDMatrix * ptr);
        bool isDynamic;
        string name;
        double x[2][2];
};


