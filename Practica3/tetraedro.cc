#include "tetraedro.h"

tetraedro::tetraedro(){
	
}

tetraedro::tetraedro(float t){
	vertice.push_back(_vertex3f(-t,2*t,0.0f));
	vertice.push_back(_vertex3f(-t,0.0f,2*t));
	vertice.push_back(_vertex3f(t,0.0f,0.0f));
	vertice.push_back(_vertex3f(-t,0.0f,0.0f));

	indice.push_back(_vertex3i(0,1,3));
	indice.push_back(_vertex3i(3,2,0));
	indice.push_back(_vertex3i(1,2,3));
	indice.push_back(_vertex3i(0,1,2));

	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));

	ip.push_back(_vertex3i(0,1,3));
	ic.push_back(_vertex3i(3,2,0));
	ip.push_back(_vertex3i(1,2,3));
	ic.push_back(_vertex3i(0,1,2));
	

	setIndiAlternas(indice);

	setColor();

	v=&vertice[0];
	i=&indice[0];
}


