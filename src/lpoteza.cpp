#include "lpoteza.h"
#include "konstante.h"

lpoteza::lpoteza()
{
	posl = nullptr;
}

lpoteza::~lpoteza()
{
	reset();
}

void lpoteza::dodaj(int kretanje, bool gurano)
{
	Potez *p = new Potez;
	p->smer = kretanje;
	p->gurano = gurano;
	p->pret = posl;
	posl = p;
}

void lpoteza::vrati()
{
 	if (posl)
	{
		Potez *brisi = posl;
		posl = posl->pret;
		delete brisi;
	}
}

int lpoteza::poslKretanje()
{
	if (posl)
		return posl->smer;
	return STOJI;
}

bool lpoteza::jelGurano()
{
	if (posl)
		return posl->gurano;
	return false;
}

void lpoteza::reset()
{
	Potez *brisi;
	while (posl)
	{
		brisi = posl;
		posl = posl->pret;
		delete brisi;
	}
}
