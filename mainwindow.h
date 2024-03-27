#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <alumno.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_name_clicked();

    void on_send_clicked();

    void on_button_clases_clicked();

    void on_add_presentes_clicked();

    void on_add_ausentes_clicked();

    void on_remove_presentes_clicked();

    void on_remove_ausentes_clicked();

    void on_alumnos_currentIndexChanged(int index);

    void on_button_promedio_clicked();

private:
    Ui::MainWindow *ui;
    Alumno alumno [20];
    int index = 0;
};
#endif // MAINWINDOW_H
