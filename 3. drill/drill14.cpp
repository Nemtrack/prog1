#include <iostream>
#include <string>

using namespace std;

class B1{
public:
	virtual void vf(){
		cout << "B1::vf()"<< endl;
	}
	void f()
	{
		cout << "B1::f()"<< endl;
	}
	/* a tisztán virtualitás okán nem példányosítható az osztály a következő sorral,
	ha a leszármaztatott osztályban példányosítani szeretnénk ezzel az osztállyal,
	nem fogunk tudni, hiába különböző a leszármaztatott osztály */
	virtual void pvf() = 0;
};

class D1 : public B1{
	public:
		virtual void vf() {
			cout << "D1::vf()" << endl;
		}
};

class D2 : public D1{
public:
	void pvf() {
		cout << "D2::pvf()" << endl;
	}
};

class B2{
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
public:
	string s;
	void pvf(){
		cout << s << endl;
	}
};

class D22 : public B2 {
public:
	int n;
	void pvf() {
		cout << n << endl;
	}
};

void f(B2& b2){
	b2.pvf();

}

int main(){

	/*B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	B1& b1r = d1;
	b1r.vf();
	b1r.f();*/

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	/*B2 b2;
	b2. pvf();*/

	D21 d21;
	d21.s = "d21.s";
	d21.pvf();

	D22 d22;
	d22.n = 22;
	d22.pvf();

	f(d21);
	f(d22);

}