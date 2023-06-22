#ifndef KONSTANTE_H
#define KONSTANTE_H

#define BR_NIVOA 50
#define NIVOI_PATH "resource/nivoi"
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

enum kretanje {
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
#define ZID_TEX "resource/kocka.png"
#define KUTIJA_TEX "resource/kutija.png"
#define KRAJ_TEX "resource/kraj-t256.png"
#define IGRAC_TEX "resource/igrac.png"
#define NA_MESTU_TEX "resource/na_mestu.png"

#endif
