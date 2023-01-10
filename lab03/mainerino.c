#include "functioncalls.h"
int main()
{
	Objekt3D* tijelo = citaj();
	pisi(tijelo);
	pisitxt(tijelo);
	brisiObjekt3D(tijelo);
	return 0;
}
