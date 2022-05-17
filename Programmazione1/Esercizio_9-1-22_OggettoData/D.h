#pragma once
class D
{
private:
	int gg, mm, aa;
	bool validate;
public:
	//Costruttore
	D(int, int, int);
	
	
	void out();							//Output
	void mod(int g, int m, int a);		//Modifica data
	void val();							//Validazione data
};

