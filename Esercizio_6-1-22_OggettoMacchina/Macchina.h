#pragma once
#include <iostream>
#include <string>
using namespace std;

class Macchina
{
private:
	//Variabili di base
	string modello;
	string targa;
	int cilindrata;
	string colore;
	float serbatoioMax;
	float consumoPerChilometro;

	//Variabili relative al funzionamento
	bool isOn = false;
	float chilometri;
	float serbatoio;

public:
	Macchina(string, string, int, string, float, float, float, float);	//Costruttore 

	void accenditi();
	void spegniti();
	void muoviti();
	void rifornimento();

};

