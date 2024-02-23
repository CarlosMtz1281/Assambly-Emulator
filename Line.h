#pragma once
using namespace std;

#include <string>

struct Line {

  // atributos
  string id;
  string comando;
  string relacion;
  string direcion;
  int cmdType;

  Line(string id, string comando, string relacion, string direcion);
  void setCmdType();
  void printLn();
};

Line::Line(string id, string comando, string relacion, string direcion) {
  this->id = id;
  this->comando = comando;
  this->relacion = relacion;
  this->direcion = direcion;
  setCmdType();
}

void Line::setCmdType() {
  if (comando == "NOP") {
    cmdType = 0;
  } else if (comando == "CLA") {
    cmdType = 1;
  } else if (comando == "NEG") {
    cmdType = 2;
  } else if (comando == "LDA") {
    cmdType = 10;
  } else if (comando == "STA") {
    cmdType = 11;
  } else if (comando == "ADD") {
    cmdType = 20;
  } else if (comando == "SUB") {
    cmdType = 21;
  } else if (comando == "JMP") {
    cmdType = 30;
  } else if (comando == "JMZ") {
    cmdType = 31;
  } else if (comando == "JMN") {
    cmdType = 32;
  } else if (comando == "JMV") {
    cmdType = 33;
  } else if (comando == "HLT") {
    cmdType = 99;
  }
}

void Line::printLn() {
  cout << id << " " << comando << " " << relacion << " " << direcion << endl;
}
