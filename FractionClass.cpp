#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den; 
public:
    Fraction()                                  //Default constructor
    {
        num = 1;
        den = 1;
    }
    Fraction(int n, int d)
    {
        num = n;
        den = d;
    }

    int GCD(int G, int temp) {                         //Recursive function
        return temp == 0 ? G : GCD(temp, G % temp);          //When temp=0, GCD is G. Until then, swap G and temp, replace temp with remainder.
    }

    void Display()
    {
        if(num == 0){
            cout << "0" << endl;
        }
        else if(num == den){
            cout << "1" << endl;
        }
        else if(den == 1){
            cout << num << endl;
        }
        else
        cout << num << "/" << den << endl;
    } 

// Fraction1 parameters are 'num' and 'den', while Fraction2 parameters are 'Fraction2.num' and 'Fraction2.den'
// Calculated GCD will be stored locally as 'G'. Results of arithmetic operations will be 'n' and 'd'

    Fraction Addition(Fraction Fraction2)          
    {
        int n = num*Fraction2.den+Fraction2.num*den;
        int d = den*Fraction2.den;
        int G = GCD(n,d);
        n=n/G, d=d/G;
        return Fraction(n,d);
    }

    Fraction Subtraction(Fraction Fraction2)
    {
        int n = num*Fraction2.den-Fraction2.num*den;
        int d = den*Fraction2.den;
        int G = GCD(n,d);
        n=n/G, d=d/G;
        return Fraction(n,d);
    }

    Fraction Multiplication(Fraction Fraction2)
    {
        int n = num*Fraction2.num;
        int d = den*Fraction2.den;
        int G = GCD(n,d);
        n=n/G, d=d/G;
        return Fraction(n,d);
    }

    Fraction Division(Fraction Fraction2)
    {
        int n = num*Fraction2.den;
        int d = den*Fraction2.num;
        int G = GCD(n,d);
        n=n/G, d=d/G;
        return Fraction(n,d);
    }

    Fraction& operator=(const Fraction &Fraction2)                  //Copies contents of RHS fraction to private members of returned object
    {
        num = Fraction2.num;
        den = Fraction2.den;
        return *this;
    }

    const Fraction operator+(const Fraction &Fraction2)             // 'this' points to the implicitly passed fraction on left of operator
    {
        Fraction Result;
        Result.num = this->num*Fraction2.den + this->den*Fraction2.num;
        Result.den = this->den*Fraction2.den;
        int G = GCD (Result.num,Result.den);
        Result.num=Result.num/G; Result.den=Result.den/G;
        return Result;
    }

    const Fraction operator-(const Fraction &Fraction2)
    {
        Fraction Result;
        Result.num = this->num*Fraction2.den - this->den*Fraction2.num;
        Result.den = this->den*Fraction2.den;
        int G = GCD (Result.num,Result.den);
        Result.num=Result.num/G; Result.den=Result.den/G;
        return Result;
    }

    const Fraction operator*(const Fraction &Fraction2)
    {
        Fraction Result;
        Result.num = this->num*Fraction2.num;
        Result.den = this->den*Fraction2.den;
        int G = GCD (Result.num,Result.den);
        Result.num=Result.num/G; Result.den=Result.den/G;
        return Result;
    }

    const Fraction operator/(const Fraction &Fraction2)
    {
        Fraction Result;
        Result.num = this->num*Fraction2.den;
        Result.den = this->den*Fraction2.num;
        int G = GCD (Result.num,Result.den);
        Result.num=Result.num/G; Result.den=Result.den/G;
        return Result;
    }

    void Equal_Check(Fraction Fraction2)
    {
        float n1 = num/GCD(num,den);                             //Float used to handle post-decimal values
        float d1 = den/GCD(num,den);
        float n2 = Fraction2.num/GCD(Fraction2.num,Fraction2.den);
        float d2 = Fraction2.den/GCD(Fraction2.num,Fraction2.den);
        if(n1/d1 > n2/d2){
            cout << num << "/" << den << " is greater than " << Fraction2.num << "/" << Fraction2.den << endl;
        }        
        else if(n1/d1 < n2/d2){
            cout << num << "/" << den << " is lesser than " << Fraction2.num << "/" << Fraction2.den << endl;
        }
        else{
            cout << "Fractions are equal" << endl;
        }
    }
};

int Validate_Input(){                                   //This function ensures that input is numeric
        int input;
        do{
            if(!cin){                                   //Checks if std::cin ran into an error, then resets error flag, asks for input again
                cin.clear();
                cin.ignore();
                cout << "Enter valid number " << endl;
            }
            cin>>input;
        }while(!cin);
        return input;
    }

int Denominator_Check(int den){                         //To check divide-by-zero conditions
    while(den == 0){
        cout << "Denominator cannot be zero. Enter again: " <<endl;
        den = Validate_Input();
    }
    return den;
}

int main()
{
    int num1,den1,num2,den2, user_action;

    cout << "Enter two fractions \n" << "Enter first fraction's numerator" << endl;
    num1 = Validate_Input(); 
    cout << "Enter first fraction's denominator" << endl;
    den1 = Validate_Input();
    den1 = Denominator_Check(den1);
    cout<<"Enter second fraction's numerator"<<endl;
    num2 = Validate_Input();
    cout<<"Enter second fraction's denominator"<<endl;
    den2 = Validate_Input();
    den2 = Denominator_Check(den2);

    Fraction Fraction1(num1,den1);
    Fraction Fraction2(num2,den2);
    Fraction Fraction3;
    
    cout << "Your fractions are: \n"; Fraction1.Display(); Fraction2.Display();
    cout << "\nWhat would you like to perform?" << endl;
    cout << " 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division" << endl;
    cout << " 5. Equality/Inequality Check \n 6. All of the above \n" << endl;
    
    user_action = Validate_Input();
    while (user_action < 1 || user_action > 6){
        cout << "Invalid choice. Enter again: " << endl;
        user_action = Validate_Input();
    }
    cout << "\n";

    switch(user_action){
        case 1:
            Fraction3 = Fraction1.Addition(Fraction2);
            cout << "Addition result is "; Fraction3.Display();
            break;
        case 2:
            Fraction3 = Fraction1.Subtraction(Fraction2);
            cout << "Subtraction result is "; Fraction3.Display();
            break;
        case 3:
            Fraction3 = Fraction1.Multiplication(Fraction2);
            cout << "Multiplication result is "; Fraction3.Display();
            break;
        case 4:
            Fraction3 = Fraction1.Division(Fraction2);
            cout << "Division result is "; Fraction3.Display();
            break;
        case 5:
            Fraction1.Equal_Check(Fraction2);
            break;
        case 6:                                                 //All arithmetic operations repeated here using Overloaded Operators
            Fraction3 = Fraction1 + Fraction2;
            cout << "Addition result is "; Fraction3.Display();
            Fraction3 = Fraction1 - Fraction2;
            cout << "Subtraction result is "; Fraction3.Display();
            Fraction3 = Fraction1 * Fraction2;
            cout << "Multiplication result is "; Fraction3.Display();
            Fraction3 = Fraction1 / Fraction2;
            cout << "Division result is "; Fraction3.Display();
            Fraction1.Equal_Check(Fraction2);
            break;
    }
    return 0;
}