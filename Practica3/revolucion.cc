#include "revolucion.h"


revolucion::revolucion(vector<_vertex3f> perfil,int pasos,bool tapas,float an){
	generaPerfil(perfil,pasos,tapas,an);
}

float revolucion::gradosRadianes(float valor){
		return valor * M_PI / 180.0;
	}

	_vertex3f revolucion::rotarX(_vertex3f v,float angulo){
		_vertex3f punto;
		punto.x=v.x;
		punto.y=cos(angulo)*v.y - sin(angulo)*v.z;
		punto.z=sin(angulo)*v.y + cos(angulo)*v.z;

		return punto;
	}

	_vertex3f revolucion::rotarY(_vertex3f v,float angulo){
		_vertex3f punto;

		punto.x=cos(angulo)*v.x + sin(angulo)*v.z;
		punto.y=v.y;
		punto.z=-sin(angulo)*v.x + cos(angulo)*v.z;

		return punto;
	}

	_vertex3f revolucion::rotarZ(_vertex3f v,float angulo){
		_vertex3f punto;

		punto.x=cos(angulo)*v.x - sin(angulo)*v.y;
		punto.y=sin(angulo)*v.x + cos(angulo)*v.y;
		punto.z=v.z;

	}
	

	void revolucion::generaPerfil(vector<_vertex3f> perfil,int steps,bool tapas,float an){
	double angulo;
    vector<_vertex3i> indices;
    vector<_vertex3f> vertices(perfil);
    an=gradosRadianes(an);

    angulo = an / steps;

    // Generamos la parte principal

    for (int step = 0; step < steps; step++) {
        vector<_vertex3f> sigPer(perfil.size());
        
        for (unsigned int k = 0; k < perfil.size(); k++)
            sigPer[k] = rotarY(perfil[k], angulo);

        // Añadimos los vertices al final del vector
        vertices.insert(vertices.end(), sigPer.begin(), sigPer.end() );
	
        // Generamos indices
        unsigned int inicioPerfil, finPerfil;
        inicioPerfil = step * perfil.size();
        finPerfil = inicioPerfil + perfil.size();

        for (unsigned int i = inicioPerfil+1, k = finPerfil+1; i < finPerfil; i++, k++) {
            indices.push_back(_vertex3i(i-1, k-1, k));
            indices.push_back(_vertex3i(i-1, k,   i));       
	    }
        perfil = sigPer;
    }
	

    // Generamos las tapas
    if (tapas) {
        // Generamos la tapa de abajo
        if (vertices.front().x) {
            cout << "El modelo no tiene tapa abajo, se la pongo" << endl;
            // Agregamos el punto central, aunque no es necesario porque solo pintamos las indices
            _vertex3f centro(0.0, vertices.front().y, 0.0);
            vertices.push_back(centro);

            for (int step = 0; step < steps; step++) {
                int perfilactual = step * perfil.size();
                int sigPer = perfilactual + perfil.size();
                indices.push_back(_vertex3i(vertices.size()-1, sigPer, perfilactual));

            }
        } else {
            // x == 0 para el 1er punto. Miramos si además el segundo punto tiene x == 0
            if ( vertices[1].x ) {
               cout << "El modelo no tiene tapa abajo, tiene un punto de cierre" << endl;
            } else {
                cout << "El modelo tiene la tapa de abajo" << endl;
            }
        }

        // Generamos la tapa de arriba
        if (vertices[perfil.size() - 1].x) {
            cout << "El modelo no tiene tapa arriba, poniendo tapa..." << endl;
            // Agregamos el punto central, aunque no es necesario porque solo pintamos las indices
            _vertex3f centro(0.0, vertices[perfil.size() - 1].y, 0.0);
            vertices.push_back(centro);

            for (int step = 0; step < steps; step++) {
                int perfilactual = (step+1) * perfil.size() -1;
                int sigPer = perfilactual + perfil.size();
                indices.push_back(_vertex3i(vertices.size()-1, perfilactual,sigPer)); // Hay que ponerlos al revés que en la otra tapa para que calcule bien las normales
            }
        } else {
            // x == 0 para el p 1punto. Miramos si además el segundo punto tiene x == 0
            if ( vertices[perfil.size() - 2].x ) {
               cout << "El modelo no tiene tapa arriba, tiene un punto de cierre" << endl;
            } else {
                cout << "El modelo tiene la tapa de arriba" << endl;
            }
        }
    }
    
    setVertices(vertices);
    setIndices(indices);
    setIndiAlternas(indices);
    setColor(150.0);

	}