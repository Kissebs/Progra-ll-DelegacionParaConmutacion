#include <iostream>

using namespace std;

class Antena {//clese base /clase abtracta
private:

	//tarea moral
public:
	virtual void f() = 0;// MVP

 

};

class AntenaRemotaA :public Antena {
public:

	void f() { cout << "AR*A::f() Conectada y transmitiendo por AR->A"<<endl; }

};

class AntenaRemotaB :public Antena {
public:
	void f() { cout << "AR->B::f() Conectada y transmitiendo por AR->B"<<endl; }

};

class AntenaRemota : public Antena {//Esta es la que da la CARA
private:
	Antena* antena;//UpCasting //aqui va "chip"
public:
	AntenaRemota(){
	antena = new AntenaRemotaA;//aqui se inicializa

	}

	void f() { antena->f(); }

	void conmutacionHaciaA() {
		delete antena;
		antena = new AntenaRemotaA;
	}
	void conmutacionHaciaAntenaB() {
		delete antena;
		antena = new AntenaRemotaB();
	}

};

int main() {//En el main se trabaja con lo que da la cara
					//El resto esta escondido

	AntenaRemota* remota = new AntenaRemota();

	remota->f();
	remota->conmutacionHaciaAntenaB();
	remota->f();
	remota->conmutacionHaciaA();

	system("pause");

	return 0;
}