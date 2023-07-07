#ifndef KONSTANTE_H
#define KONSTANTE_H

#define BR_NIVOA 50
#define NIVOI_PATH "nivoi"
#define MAPA_X 19
#define MAPA_Y 16

enum polje {
	PRAZNO,
	ZID,
	KUTIJA,
	KRAJ,
	IGRAC,
	NA_MESTU
};

#define KORAK 0.07f
enum Kretanje {
	LEVO,
	GORE,
	DESNO,
	DOLE,
	STOJI = -1
};

#define V_EKR_X0 1400
#define V_EKR_Y0 800

#define V_SLIKE 256
#define SKALIRANJE 0.25f
#define V_NA_EKRANU 50.0f
#define ZID_TEX "teksture/kocka.png"
#define KUTIJA_TEX "teksture/kutija.png"
#define KRAJ_TEX "teksture/kraj-t256.png"
#define IGRAC_TEX "teksture/igrac.png"
#define NA_MESTU_TEX "teksture/na_mestu.png"

#endif
