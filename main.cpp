//Iker Guerrero González A00830026
//Aldo Mauricio Cruz Lozada A01732372
//Francisco Rocha Juárez A01730560
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

//Asignamos nuestro documento bitacora.txt a la variable in de tipo ifstream
ifstream in("bitacora.txt");
//Creamos diferentes vectores para almacenar los registros, días, meses, horas y segundos
vector<string> registros;
vector<int> dias;
vector<int> meses;
vector<int> horas;
vector<int> minutos;
vector<int> segundos;

//Creamos una función que nos de el mes númericamente
int MesInt(string mes){
    if (mes == "Jan"){
        return 1;
    }
    else if (mes == "Feb"){
        return 2;
    }
    else if (mes == "Mar"){
        return 3;
    }
    else if (mes == "Apr"){
        return 4;
    }
    else if (mes == "May"){
        return 5;
    }
    else if (mes == "Jun"){
        return 6;
    }
    else if (mes == "Jul"){
        return 7;
    }
    else if (mes == "Aug"){
        return 8;
    }
    else if (mes == "Sep"){
        return 9;
    }
    else if (mes == "Oct"){
        return 10;
    }
    else if (mes == "Nov"){
        return 11;
    }
    else if (mes == "Dec"){
        return 12;
    }
    else {
        return 0;
    }
}

//Creamos una función switch para cambiar de posición en el arreglo a los valores de tiempo
void Switch (int x, int y) {
    int tempi;
    string temps;


    temps = registros[x];
    registros[x] = registros[y];
    registros[y] = temps;

    tempi = meses[x];
    meses[x] = meses[y];
    meses[y] = tempi;

    tempi = dias[x];
    dias[x] = dias[y];
    dias[y] = tempi;

    tempi = horas[x];
    horas[x] = horas[y];
    horas[y] = tempi;

    tempi = minutos[x];
    minutos[x] = minutos[y];
    minutos[y] = tempi;

    tempi = segundos[x];
    segundos[x] = segundos[y];
    segundos[y] = tempi;

}


//Creamos la función Sort que es un algoritmo de ordenamiento por intercambio, para ordenar nuestros vectores
//Complejidad de O(n^2)
void Sort(){
    for (int i = 0; i < registros.size(); i++)
    {
        for (int j = i; j < registros.size(); j++)
        {
            if (meses[i] > meses[j])
            {
                Switch(i, j);
            }
            else if (meses[i] == meses[j])
            {
                if (dias[i] > dias[j])
                {
                    Switch(i, j);
                }
                else if (dias[i] == dias[j])
                {
                    if (horas[i] > horas[j])
                    {
                        Switch(i, j);
                    }
                    else if (horas[i] == horas[j])
                    {
                        if (minutos[i] > minutos[j])
                        {
                            Switch(i, j);
                        }
                        else if (minutos[i] == minutos[j])
                        {
                            if (segundos[i] > segundos[j])
                            {
                                Switch(i, j);
                            }
                        }
                    }
                }
            }

        }

    }


}

int main(){

    string linea;

    //Inicializamos un contador un 0 para contar las líneas de nuestro documento bitacora.txt
    int counter = 0;
    while(getline(in,linea)){
        registros.push_back(linea);
        counter++;
    }

    string palabra;
    for (int i = 0; i < registros.size(); i++){
        stringstream temp(registros[i]);

        getline(temp, palabra, ' ');
        meses.push_back(MesInt(palabra));

        getline(temp, palabra, ' ');
        dias.push_back(stoi(palabra));

        getline(temp, palabra, ':');
        horas.push_back(stoi(palabra));

        getline(temp, palabra, ':');
        minutos.push_back(stoi(palabra));

        getline(temp, palabra, ' ');
        segundos.push_back(stoi(palabra));


    }

//Llamamos a nuestra función de ordenamiento
    Sort();

    fstream sorted;
	sorted.open("sorted.txt", ios::out);
    for (int i = 0; i < registros.size(); i++){
        sorted << registros[i] << endl;
    }

    int mesi;
    int diai;
    int mesf;
    int diaf;
    //Preguntamos al usuario por el mes y día inicial de la búsqueda
    cin >> mesi;
    cin >> diai;
    //Preguntamos al usuario por el mes y día final de la búsqueda
    cin >> mesf;
    cin >> diaf;

//Este es nuestro algoritmo de búsqueda direta
//Complejidad O(n)
    for (int i = 0; i < registros.size(); i++){
        if (meses[i] >= mesi && meses[i] <= mesf){
            if (meses[i] == mesi && dias[i] >= diai)
            {
                cout << registros[i] << endl;
            }
            else if (meses[i] == mesf && dias[i] <= diaf)
            {
                cout << registros[i] << endl;
            }
            else if (meses[i] != mesf && meses[i] != mesi)
            {
                cout << registros[i] << endl;
            }

        }
    }


    return 1;
}
