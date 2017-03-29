#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "A.h"
using namespace std;

ELO::ELO() { K = 0;RA = 0;RB = 0; }
ELO::ELO(int init_k,int A,int B,double S) {
	setELO(init_k,A,B,S);
}
void ELO::setELO(int init_k,int A,int B,double S){
	K = init_k;RA = A;RB = B;SA = S;
}
int ELO::getNewA(){
	double EA,nA;
	nA = pow(10,(double)(RB-RA)/400);
	EA = 1/(1+nA);
	return (int)(RA+K*(SA-EA));
}
int ELO::getNewB(){
	double EB,nB,SB;
	nB = pow(10,(double)(RA-RB)/400);
	EB = 1/(1+nB);
	if(SA==1)
		SB = 0;
	else if(SA==0.5)
		SB = 0.5;
	else
		SB = 1;
	return (int)(RB+K*(SB-EB));
}

int main(){
	int K = 0;
	int RA = 0;
	int RB = 0;
	double SA = 0;
	ifstream inFile("file.in",ios::in);
	ofstream outFile("file.out",ios::out);
	if(!inFile){
		cerr<<"Failed opening"<<endl;
		exit(1);
	}
	inFile>>K>>RA>>RB>>SA;
	outFile<<RA<<" "<<RB<<endl;
	ELO ELO1(K,RA,RB,SA);
	RA = ELO1.getNewA();
	RB = ELO1.getNewB();
	outFile<<RA<<" "<<RB<<endl;
	while(inFile>>SA){
		ELO1.setELO(K,RA,RB,SA);
		outFile<<ELO1.getNewA()<<" "<<ELO1.getNewB()<<endl;
		RA = ELO1.getNewA();
		RB = ELO1.getNewB();
	}
}
