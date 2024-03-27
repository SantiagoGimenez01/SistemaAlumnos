#include "alumno.h"

Alumno::Alumno()
{
    nota[20]={0};
    presente=0;
    ausente=0;
    i=0;

}
Alumno::~Alumno()
{}
void Alumno::CargarNota(float nota_parcial)
{
    nota[i] = nota_parcial;
    i++;
}
float Alumno::ObtenerPromedio()
{
    float promedio=0,suma=0;
    int j;
    for(j=0;j<i;j++)
        suma+=nota[j];
    promedio = suma/j;
    return promedio;
}

void Alumno::CargarAsistencia(bool presencia)
{
    if(presencia)
        presente++;
    else
        ausente++;
}

unsigned char Alumno::ObtenerPresentes()
{
    return presente;
}

unsigned char Alumno::ObtenerAusentes()
{
    return ausente;
}

void Alumno::RemoveAsistencia(bool presencia)
{
    if(presencia)
        presente--;
    else
        ausente--;
}

int Alumno::ContarNotas()
{
    return i;
}

float Alumno::ObtenerNota(int index)
{
    return nota[index];
}

float Alumno::Asistencia(float clases)
{
    float asistencia = 0;

    asistencia = (clases / (presente*100));

    return asistencia;
}
