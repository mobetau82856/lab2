
using namespace std;
class ELO {
public:
	ELO();
	ELO(int init_k,int A,int B,double S);
	void setELO(int init_k,int A,int B,double S);
	int getNewA();
	int getNewB();
private:
	int K,RA,RB;
	double SA;
};
