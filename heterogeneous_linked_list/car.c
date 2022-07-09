#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"

struct car {

    char * name;
    char * color;
    int year;
    int id;
};

Car * CreateCar(char * name, char * color, int year, int id){

    Car * car = malloc(sizeof(Car));
    car->name = strdup(name);
    car->color = strdup(color);
    car->year = year;
    car->id = id;

    return car;
}

void PrintCar(Car * car){

    printf("Carro -> %s - %s - ano %d\n", car->name, car->color, car->year);
}

void DestructCar(Car * car){

    if(car){

        if(car->color)free(car->color);
        if(car->name)free(car->name);
        free(car);
    }
}

int CarId(Car * car){

    return car->id;
}