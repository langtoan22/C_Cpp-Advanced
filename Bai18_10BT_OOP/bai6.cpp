#include <iostream>

using namespace std;
class fraction{
    private:
    //tu so, mau so
        int NUMERATOR;
        int DENOMINATOR;
    public:
        fraction();
        fraction(int A, int B);
        void setNumerator(int A);
        int getNumerator();
        void setDenominator(int B);
        int getDenominator();
};

    fraction :: fraction(){
        int NUMERATOR = 0;
        int DENOMINATOR = 1;
    }

    fraction :: fraction(int A, int B){
        NUMERATOR = A;
        DENOMINATOR = B;
    }
    void fraction :: setNumerator(int A){
        NUMERATOR = A;
    }
    int fraction :: getNumerator(){
        return NUMERATOR;
    }
    void fraction :: setDenominator(int B){
        DENOMINATOR = B;
    }
    int fraction :: getDenominator(){
        return DENOMINATOR;
    }

class operation{
    private:
        fraction fraction1;
        fraction fraction2;
    public:
        operation (fraction f1, fraction f2);
        fraction getAddition();
        fraction getSubtraction();
        fraction getMultiplication();
        fraction getDivide();
        
};

    operation :: operation(fraction f1, fraction f2){
        fraction1 = f1;
        fraction2 = f2;
    }

    fraction operation :: getAddition(){
        int tu = (fraction1.getNumerator() * fraction2.getDenominator()) + (fraction1.getDenominator() * fraction2.getNumerator());
        int mau = (fraction1.getDenominator() * fraction2.getDenominator());
        return fraction(tu, mau);
    }
    fraction operation :: getSubtraction(){
        int tu = (fraction1.getNumerator() * fraction2.getDenominator()) - (fraction1.getDenominator() * fraction2.getNumerator());
        int mau = (fraction1.getDenominator() * fraction2.getDenominator());
        return fraction(tu, mau);
    }
    fraction operation :: getMultiplication(){
        int tu = (fraction1.getNumerator() * fraction2.getNumerator());
        int mau = (fraction1.getDenominator() * fraction2.getDenominator());
        return fraction(tu, mau);
    }
    fraction operation :: getDivide(){
        int tu = (fraction1.getNumerator() * fraction2.getDenominator());
        int mau = (fraction2.getDenominator() * fraction2.getNumerator());
        return fraction(tu, mau);
    }

    int main(int argc, char const *argv[])
    {
        fraction f1(4, 3);
        fraction f2(7, 8);
        operation op1(f1, f2);
           
        cout << "Ket qua cac phep tinh phan so: " << endl;
        cout << "Phep cong: " << op1.getAddition().getNumerator() << "/" << op1.getAddition().getDenominator() << endl;
        cout << "Phep tru: " << op1.getSubtraction().getNumerator() << "/" << op1.getSubtraction().getDenominator() << endl;
        cout << "Phep nhan: " << op1.getMultiplication().getNumerator() << "/" << op1.getMultiplication().getDenominator() << endl;
        cout << "Phep chia: " << op1.getDivide().getNumerator() << "/" << op1.getDivide().getDenominator() << endl;
        return 0;
    }
    