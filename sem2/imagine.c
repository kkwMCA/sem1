// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class Complex{
    private:
        int real;
        int imagine;
    public :
        string str;
        Complex(){
        }
        
        Complex(int r,int i){
            real=r;
            imagine=i;
        }
        
        
        Complex operator * (Complex a);
        Complex operator / (Complex a);

        //private me jo variable hai vo frnd function se le access kar sakte hai
        friend Complex operator + (Complex a,Complex b);
        friend Complex operator - (Complex a,Complex b);
 
        void add(){
            cout << real << "+ i" << imagine;
        }
         void sub(){
            cout << real << "- i" << imagine;
        }
        
        void mul(){
            cout << real << "- i" << imagine;
        }
        
        void divi(){
            cout << real << "/ i" << imagine;
        }
};

Complex operator +(Complex a,Complex b){
    int r=a.real + b.real;
    int i=b.imagine + b.imagine;
    Complex c(r,i);
    return c;
}

Complex operator -(Complex a,Complex b){
    int r=a.real - b.real;
    int i=b.imagine - b.imagine;
    Complex c(r,i);
    return c;
}


Complex Complex:: operator * (Complex a){
    int r=real * a.real;
    int i=imagine * a.imagine;
    Complex c(r,i);
    return c;
}

Complex Complex:: operator / (Complex a){
    int r=real / a.real;
    int i=imagine / a.imagine;
    Complex c(r,i);
    return c;
}
int main() {
    Complex c1(2,3);
    Complex c2(3,4);
    Complex c3;
    
    c3=c1 + c2;
    c3.add();
    cout << "\n";
    c3=c1 - c2;
    c3.sub();
    
    cout << "\n";
    c3=c1 * c2;
    c3.sub();
    
    cout << "\n";
    c3=c1 / c2;
    c3.divi();
    return 0;
}
