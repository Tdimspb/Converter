#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     QFileDialog PBFile;
     QString logPath,  logPathcsv, globstr;
    ~MainWindow();

private slots:
    void on_inputButton_clicked();

    void on_outputButton_clicked();
    void signal_logFileSelected(QString Filename);

    void on_ConvertButton_clicked();

    void on_progressBar_valueChanged(int value);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *csvModel;
    QString Filename;
    QString separator=",";



};

#endif // MAINWINDOW_H
