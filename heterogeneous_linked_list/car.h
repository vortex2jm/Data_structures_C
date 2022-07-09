#ifndef car_h
#define car_h

typedef struct car Car;

Car * CreateCar(char * name, char * color, int year, int id);

void PrintCar(Car * car);

void DestructCar(Car * car);

int CarId(Car * car);

#endif