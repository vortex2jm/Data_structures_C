#ifndef motorcycle_h
#define motorcycle_h

typedef struct moto Motocycle;

Motocycle * CreateMotorcycle(char * name, char * color, int year, int id);

void PrintMotorcyle(Motocycle * moto);

void DestructMotorcyle(Motocycle * moto);

int MotoId(Motocycle * moto);

#endif