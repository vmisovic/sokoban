#ifndef LPOTEZA_H
#define LPOTEZA_H

typedef struct potez
{
	int smer;
	bool gurano;
	struct potez *pret;
} Potez;

class lpoteza
{
	Potez *posl;	

public:
	lpoteza();
	~lpoteza();
	void dodaj(int kretanje, bool gurano);
	void vrati();
	int poslKretanje();
	bool jelGurano();
	void ispis();
	void reset();
};

#endif
