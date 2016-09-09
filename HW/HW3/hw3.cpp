//Name: Cory Hutson
//Auburn UserID: ceh0050
//filename: hw3.cpp
//Development Enviroment: vim, g++, Linux
//Compile: g++ -o HW3 hw3.cpp

#include <iostream>
#include <iomanip>
using namespace std;
using std::setw;

int main()
{
	float principal=0 ;
	float loan =0;
	float interestRate=0;
	float payment=0;
	float remaining=0;
	float totalInterest =0;
	float interest =0;
	int month=0;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Loan Amount: " << endl;
	cin >> loan;
	cout <<"Interest Rate: " << endl;
	cin >> interestRate;
	interestRate= interestRate/12;
	cout << "Monthly Payments: " << endl;
	cin >> payment;

	remaining = loan;	

	if(payment < loan*(interestRate/100))
	{
		cout << "Not a high enough payment" << endl;
	}
       	else{
	cout <<"****************************************************************"<< endl;
	cout <<"                Amortization Table              " <<endl;
	cout <<"****************************************************************" <<endl;
	
cout <<" Month"<< setw(8) << "Balance" << setw(10) << "Payment"<<setw(10) << "Rate" << setw(10) << "Interest" << setw(12) << "Principal" << endl;
	cout << month << setw(12)  <<  remaining << setw(10)  <<  payment << setw(10) << interestRate << setw(10) << interest << setw(10)  <<  principal << endl; 

	   	
	while(remaining > 0) {
		month++;
		interest = ((interestRate/100))*remaining;
		totalInterest += interest;
		principal = payment - interest;
		if(principal > remaining){
	        	principal = remaining;
		        payment = principal;
		}
		if(month <10){
		remaining = remaining-principal;
		cout << month << setw(12)  <<  remaining << setw(10)  <<  payment << setw(10) << interestRate << setw(10)  <<  interest << setw(10) << principal << endl; 
	}
		else{
		remaining = remaining-principal;
		cout << month << setw(11) << remaining << setw(10)  <<  payment << setw(10) << interestRate << setw(10)  <<  interest << setw(10) << principal << endl;
	}
	}
	cout << "***************************************************************" << endl;
	cout << "It takes " << month << " months to pay off the loan" << endl;
	cout << "Total interest paid in $" << totalInterest;
    }
	
	return 0;
}
