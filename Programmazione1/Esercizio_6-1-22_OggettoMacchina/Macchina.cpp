#include "Macchina.h"
#include <iostream>
#include <string>
using namespace std;

Macchina::Macchina(string modello, string targa, int cilindrata, string colore, float serbatoioMax, float chilometri, float serbatoio, float consumoPerChilometro)
{
	this->modello = modello;
	this->targa = targa;
	this->cilindrata = cilindrata;
	this->colore = colore;
	this->serbatoioMax = serbatoioMax;
	this->chilometri = chilometri;
	this->serbatoio = serbatoio;
	this->consumoPerChilometro = consumoPerChilometro;
}

void Macchina::accenditi()
{
	cout << "Macchina accesa" << endl;
	isOn = true;
}

void Macchina::spegniti()
{
	cout << "Macchina spenta" << endl;
	isOn = false;
}

void Macchina::muoviti()
{
	if(isOn && serbatoio > consumoPerChilometro)	//Se la macchina è accesa
	{
		cout << "La macchina si muove avanti di un chilometro..." << endl;
		serbatoio = serbatoio - consumoPerChilometro;
		cout << "Benzina rimasta: "<<serbatoio<<" l." << endl;
	}
	else
	{
		cout << "Impossibile muoversi. La macchina è spenta o senza benzina" << endl;
	}
}

void Macchina::rifornimento()
{
	cout << "Fatto il pieno all'auto" << endl;
	serbatoio = serbatoioMax;
}