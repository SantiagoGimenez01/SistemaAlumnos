#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alumno.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_name_clicked()
{
    QString alumno;

    alumno = ui -> input_name -> text();

    if(alumno != NULL) 
        ui -> alumnos -> addItem(alumno);

    ui -> input_name -> setText("");

}

void MainWindow::on_send_clicked()
{
    QString item;
    float notas;

    if( ui -> alumnos -> currentText() != NULL)
    {
        notas = ui -> input_notas -> value();
        alumno[index].CargarNota(notas);
        alumno[index].ContarNotas();
        item = item.number(notas);
        ui -> lista_notas -> addItem(item);
    }

    ui -> input_notas -> setValue(0);

}


void MainWindow::on_button_clases_clicked()
{
    int clases = 0;
    if( ui -> alumnos -> currentText() != NULL)
        clases = ui -> clases_totales -> value();

    ui -> display_clases -> display(clases);

}

void MainWindow::on_add_presentes_clicked()
{
    if( ui -> alumnos -> currentText() != NULL)
    {
        if( ( ui -> display_presentes -> value() + ui -> display_ausentes -> value() ) < ui -> display_clases -> value())
            alumno[index].CargarAsistencia(1);
    }

    ui -> display_presentes -> display(alumno[index].ObtenerPresentes());
}


void MainWindow::on_add_ausentes_clicked()
{

    if( ui -> alumnos -> currentText() != NULL)
    {
        if( ( ui -> display_presentes -> value() + ui -> display_ausentes -> value() ) < ui -> display_clases -> value())
            alumno[index].CargarAsistencia(0);
    }

    ui -> display_ausentes -> display(alumno[index].ObtenerAusentes());
}




void MainWindow::on_remove_presentes_clicked()
{
    if(ui -> display_presentes -> value() > 0)
        alumno[index].RemoveAsistencia(1);

    ui -> display_presentes -> display(alumno[index].ObtenerPresentes());
}


void MainWindow::on_remove_ausentes_clicked()
{
    if(ui -> display_ausentes -> value() > 0)
        alumno[index].RemoveAsistencia(0);
    ui -> display_ausentes -> display(alumno[index].ObtenerAusentes());
}


void MainWindow::on_alumnos_currentIndexChanged(int index_list)
{

    index = index_list;
    ui -> display_ausentes -> display(alumno[index].ObtenerAusentes());
    ui -> display_presentes -> display(alumno[index].ObtenerPresentes());
    ui -> display_promedio -> display(0);
    ui -> lista_notas -> clear();
    for(int i = 0; i < alumno[index].ContarNotas(); i++)
        ui -> lista_notas -> addItem(QString::number(alumno[index_list].ObtenerNota(i)));
}


void MainWindow::on_button_promedio_clicked()
{
    ui -> display_promedio -> display(alumno[index].ObtenerPromedio());
}

