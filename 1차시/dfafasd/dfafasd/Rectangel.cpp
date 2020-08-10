#include "Rectangel.h"
int main() {
	shape* s = new Rectangel;
	s->scale();
	delete s;
	Rectangel* r = new Rectangel;
	r->draw();
	delete r;
}