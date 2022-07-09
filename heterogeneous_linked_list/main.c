#include <stdio.h>
#include <stdlib.h>
#include "hetlist.h"
#include "car.h"
#include "motorcycle.h"

int main(){ 

    Car * car1, * car2, * car3; 
    car1 = CreateCar("New Fiesta", "branco", 2018, 1);
    car2 = CreateCar("Creta", "prata", 2021, 2);
    car3 = CreateCar("Volvo XC40", "preto", 2020, 3);

    Motocycle * moto1, * moto2;
    moto1 = CreateMotorcycle("Ducati", "vermelha", 2020, 4);
    moto2 = CreateMotorcycle("R1", "verde", 2019, 5);

    HetList * list = InitHetList();

    Push(list,"car", car1);
    Push(list,"motorcycle", moto1);
    Push(list,"car", car2);
    Push(list,"car", car3);
    Push(list,"motorcycle", moto2);

    PrintHetList(list);

    RemoveById(list, 2);

    PrintHetList(list);

    DestructList(list);

    return 0;
}