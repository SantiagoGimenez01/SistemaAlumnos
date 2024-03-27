#ifndef ALUMNO_H
#define ALUMNO_H


class Alumno
{
public:
    Alumno();
    void CargarNota(float nota);
    float ObtenerNota(int index);
    int ContarNotas();
    void CargarAsistencia(bool presencia);
    void RemoveAsistencia(bool presencia);
    float ObtenerPromedio();
    unsigned char ObtenerPresentes();
    unsigned char ObtenerAusentes();
    float Asistencia(float clases);
    ~Alumno();
private:
        float nota[20];
        int presente;
        int ausente;
        int i;
};

#endif // ALUMNO_H
