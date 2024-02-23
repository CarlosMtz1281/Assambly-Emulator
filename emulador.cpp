#include <iostream>
using namespace std;

// librerias para leer archivo
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

#include "Line.h"

// VARIABLES GLOBALES
int AC = 0;
int MAR = 0;
int  MDR = 0;
string FR = "000";
int PC = 0;
int IR;

map <string, int> memoria{
    {"000", 0}, {"001", 0}, {"002", 0}, {"003", 0}, {"004", 0}, {"005", 0},
    {"006", 0}, {"007", 0}, {"008", 0}, {"009", 0}, {"010", 0}, {"011", 0},
    {"012", 0}, {"013", 0}, {"014", 0}, {"015", 0}, {"016", 0}, {"017", 0},
    {"018", 0}, {"019", 0}, {"020", 0}, {"021", 0}, {"022", 0}, {"023", 0},
    {"024", 0}, {"025", 0}, {"026", 0}, {"027", 0}, {"028", 0}, {"029", 0},
    {"030", 0}, {"031", 0}, {"032", 0}, {"033", 0}, {"034", 0}, {"035", 0},
    {"036", 0}, {"037", 0}, {"038", 0}, {"039", 0}, {"040", 0}, {"041", 0},
    {"042", 0}, {"043", 0}, {"044", 0}, {"045", 0}, {"046", 0}, {"047", 0},
    {"048", 0}, {"049", 0}};

void printMemory() {
  cout<<"MEMORIA"<<endl;
  int count = 0;
  for (auto pair : memoria) {
      cout << " '"<<pair.first <<"' : " << pair.second << "\t";

      count++;
      if (count % 10 == 0) {
          cout << endl;
      }
  }
  cout<<endl<<endl;
}

// FUCIONES BASICAS

void executeCLA() {
  AC = 0;
  return;
}

void executeNEG() {
  AC = -AC;
  return;
}

void executeLDA(string direccion, string relacion) {

  if (relacion == "A") {
    AC = memoria[direccion];
    MAR = stoi(direccion);
    MDR = memoria[direccion];
  } else if (relacion == "Inm") {
    AC = stoi(direccion);

  } else if (relacion == "Ind") {
    MAR = stoi(direccion);
    AC = memoria[to_string(MAR)];
    MDR = memoria[to_string(MAR)];
  }else{
    MAR = MAR + stoi(direccion);
    AC = memoria[to_string(MAR)];
    MDR = memoria[to_string(MAR)];
  }
  return;
}

void executeSTA(string direccion, string relacion) {
  if (relacion == "A") {
    memoria[direccion] = AC;
    MAR = stoi(direccion);
    MDR = memoria[direccion];
  } else if (relacion == "Inm") {
    memoria[direccion] = AC;
  } else if (relacion == "Ind") {
    MAR = stoi(direccion);
    memoria[to_string(MAR)] = AC;
    MDR = memoria[to_string(MAR)];
  }else{
    MAR = MAR + stoi(direccion);
    memoria[to_string(MAR)] = AC;
    MDR = memoria[to_string(MAR)];
  }
  return;
}



void executeADD(string direccion, string relacion) {
  if (relacion == "A") {
    AC = AC + memoria[direccion];
    MAR = stoi(direccion);
    MDR = memoria[direccion];
  } else if (relacion == "Inm") {
    AC = AC + stoi(direccion);
  } else if (relacion == "Ind") {
    MAR = memoria[direccion];
    AC = AC + memoria["0"+to_string(MAR)];
    MDR = memoria["0"+to_string(MAR)];
  }else{
    MAR = MAR + stoi(direccion);
    AC = AC + memoria[to_string(MAR)];
    MDR = memoria[to_string(MAR)];
  }
   return;

}

void executeSUB(string direccion, string relacion) {
  if (relacion == "A") {
    AC = AC - memoria[direccion];
    MAR = stoi(direccion);
    MDR = memoria[direccion];
  } else if (relacion == "Inm") {
    AC = AC - stoi(direccion);
  } else if (relacion == "Ind") {
    MAR = stoi(direccion);
    AC = AC - memoria[to_string(MAR)];
    MDR = memoria[to_string(MAR)];
  }else{
    MAR = MAR + stoi(direccion);
    AC = AC - memoria[to_string(MAR)];
    MDR = memoria[to_string(MAR)];
  }
  return;
}

void executeJMP(string direccion, string relacion) {
  if(stoi(direccion) > PC ){
    if(relacion == "A"){
    PC = stoi(direccion)-1;
  }else if(relacion == "Ind"){
    MAR = stoi(direccion);
    MDR = memoria[to_string(MAR)];
    PC = MDR-1;
  }else if(relacion == "R"){
    PC = PC + stoi(direccion)-1;
  }
  return;
  }else{
  if(relacion == "A"){
    PC = stoi(direccion)-1;
  }else if(relacion == "Ind"){
    MAR = stoi(direccion);
    MDR = memoria[to_string(MAR)];
    PC = MDR -1;
  }else if(relacion == "R"){
    PC = PC + stoi(direccion)-1;
  }
  return;
  }
}

void executeJMZ(string direccion, string relacion) {
  if(stoi(direccion)> PC){
    if(AC == 0){
      if(relacion == "A"){
        PC = stoi(direccion)-1;
      }else if(relacion == "Ind"){
        MAR = stoi(direccion);
        MDR = memoria[to_string(MAR)];
        PC = MDR-1;
      }else if(relacion == "R"){
        PC = PC + stoi(direccion)-1;
      }
    }
    return;
  }else{
  if(AC == 0){
    if(relacion == "A"){
      PC = stoi(direccion)-1;
    }else if(relacion == "Ind"){
      MAR = stoi(direccion);
      MDR = memoria[to_string(MAR)];
      PC = MDR -1;
    }else if(relacion == "R"){
      PC = PC + stoi(direccion)-1;
    }
  }
  return;
  }
}

void executeJMN(string direccion, string relacion) {
  if(stoi(direccion)> PC){
    if(AC < 0){
      if(relacion == "A"){
        PC = stoi(direccion)-1;
      }else if(relacion == "Ind"){
        MAR = stoi(direccion);
        MDR = memoria[to_string(MAR)];
        PC = MDR-1;
      }else if(relacion == "R"){
        PC = PC + stoi(direccion)-1;
      }
    }
    return;
  }else{
  if(AC < 0){
    if(relacion == "A"){
      PC = stoi(direccion)-1;
    }else if(relacion == "Ind"){
      MAR = stoi(direccion);
      MDR = memoria[to_string(MAR)];
      PC = MDR -1;
    }else if(relacion == "R"){
      PC = PC + stoi(direccion)-1;
    }
  }
  return;
  }
}

void executeJMV(string direccion, string relacion) {
  if(stoi(direccion)> PC){
    if(FR[2] == '1'){
      if(relacion == "A"){
        PC = stoi(direccion)-1;
      }else if(relacion == "Ind"){
        MAR = stoi(direccion);
        MDR = memoria[to_string(MAR)];
        PC = MDR-1;
      }else if(relacion == "R"){
        PC = PC + stoi(direccion)-1;
      }
    }
    return;
  }else{
  if(FR[2] == '1'){
    if(relacion == "A"){
      PC = stoi(direccion)-1;
    }else if(relacion == "Ind"){
      MAR = stoi(direccion);
      MDR = memoria[to_string(MAR)];
      PC = MDR -1;
    }else if(relacion == "R"){
      PC = PC + stoi(direccion)-1;
    }
  }

  return;
  }
}

int main() {
  printMemory();
      // menu de bienvendia

      cout
      << "//////////////////////////////////////////" << endl;
  cout << "           EMULADOR DE ASSAMBLY" << endl << endl;
  cout
      << "Ingrese el codigo en el archivo input.txt Presione enter para empezar"
      << endl
      << endl;


  cout << "Presiona enter para continuar...";
  cin.get();

  // setup de archivo
  ifstream fileIn("input.txt");
  string line;
  string word;

  // variables para seudoensablador
  string id;
  string comando;
  string relacion;
  string memoria;

  int cont = 0;

  // vector para guardar datos
  vector<Line> lista;

  while (getline(fileIn, line)) {

    // funcion para saltar lineas vacias
    if (line.empty()) {
      continue;
    }

    stringstream ss(line);

    ss >> id >> comando >> relacion >> memoria;

    // guardamos los datos en un objetp
    if(id == "ORG"){
      continue;
    }
    Line L(id, comando, relacion, memoria);

    lista.push_back(L);

    // VECTOR DE OBJETOS
    cont++;

    relacion = "";
    memoria = "";
  }

  // setup de micro-operacinones

  // ejecucion

  int index = 0;
  int cmdNum;
  cmdNum = lista[index].cmdType;

  while (true) {


    // FETCH

    // EXECUTE
    index = PC;
    cmdNum = lista[index].cmdType;


    // ejecuta funciones
    if (cmdNum == 0) {
      // sigue
    } else if (cmdNum == 1) {
      executeCLA();
    } else if (cmdNum == 2) {
      executeNEG();
    } else if (cmdNum == 10) {
      executeLDA(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 11) {
      executeSTA(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 20) {
      executeADD(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 21) {
      executeSUB(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 30) {
      executeJMP(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 31) {
      executeJMZ(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 32) {
      executeJMN(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 33) {
      executeJMV(lista[index].direcion, lista[index].relacion);
    } else if (cmdNum == 99) {
      cout<<"Instruccion: ";
        lista[index].printLn();
      cout<<"Programa terminado"<<endl;
      printMemory();
      break;
    }

    if(AC == 0){
      FR[0] = '1';
    }else if(AC < 0){
      FR[1] = '1';
    }

    cout<<"Info del Ciclo"<<endl<<endl;
    cout<<"Instruccion: ";
    lista[index].printLn();

    cout<<"Registros del CPU"<<endl<<endl;
    cout<<"PC: "<<PC<<endl;
    cout<<"IR: "<<IR<<endl;

    cout<<"FR: "<<FR<<endl;
    cout<<"MAR: "<<MAR<<endl;
    cout<<"MDR: "<<MDR<<endl<<endl;

    cout<<"AC: "<<AC<<endl<<endl;

    printMemory();
    cout<<endl<<endl;


    FR = "000";

    cout << "Presiona enter para continuar...";
    cin.get();
    PC++;

  }

  // acaba el programa
}