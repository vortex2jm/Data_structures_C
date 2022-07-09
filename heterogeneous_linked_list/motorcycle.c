#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motorcycle.h"

struct moto {

    char * name;
    char * color;
    int year;
    int id;
};

Motocycle * CreateMotorcycle(char * name, char * color, int year, int id){

    Motocycle * moto = malloc(sizeof(Motocycle));

    moto->name = strdup(name);
    moto->color = strdup(color);
    moto->year = year;
    moto->id = id;

    return moto;
}

void PrintMotorcyle(Motocycle * moto){

    printf("Moto -> %s - %s - ano %d\n", moto->name, moto->color, moto->year);
}

void DestructMotorcyle(Motocycle * moto){

    if(moto){

        if(moto->name)free(moto->name);
        if(moto->color)free(moto->color);
        free(moto);
    }
}

int MotoId(Motocycle * moto){

    return moto->id;
}