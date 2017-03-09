#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"
#include <QDebug>

#include <QtGui>
//2017 02 25/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputButton_clicked()
{
    PBFile.setDirectory(logPath);
    QString namefile;
    namefile = PBFile.getOpenFileName(this, QString(), QString(), "CSV files (*.csv)\n ALLFILES(*.*)");

       if ( ! namefile.isEmpty() )
         {
           logPath = namefile;
           ui->lineEdit->setText(logPath);
           QFileInfo fi;
           fi.setFile( namefile );
           Filename=namefile;
       //    emit signal_logFileSelected( namefile ); // сигнал о том что выбран новый файл
        }
}


void MainWindow::on_outputButton_clicked()
{


}

void MainWindow::signal_logFileSelected(QString Filename)
{

}

void MainWindow::on_ConvertButton_clicked()
{
    int i=0;
    QFile fi(Filename);
    csvModel = new QStandardItemModel(this);
    QStringList header;
    ui->tableView->setModel(csvModel); // Устанавливаем модель в таблицу

    if (fi.open(QIODevice::ReadOnly) )
    {
        QTextStream in(&fi);
        while(!in.atEnd())
        {
         i++;
         ui->progressBar->setValue(i);

         QList<QStandardItem *> standardItemsList;
         QString line = in.readLine();
        if (i==6) {

         for (QString item : line.split(",")) {
                  header << item;
             }
            }
        csvModel->setHorizontalHeaderLabels(header);
         if(line[0].isDigit())
         {
             for (QString item : line.split(",")) {
                 //can be replaced by foreach( , ) or CONFIG += C++11 in profile
                 standardItemsList.append(new QStandardItem(item));
             }
             csvModel->insertRow(csvModel->rowCount(), standardItemsList);

         }
        }
        ui->progressBar->setValue(100);
    }
    fi.close();

    QString textData;
    int rows = csvModel->rowCount();
    int columns = csvModel->columnCount();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

                textData += csvModel->data(csvModel->index(i,j)).toString();
                textData += separator;     // for .csv file format
        }
        textData += "\n";             // (optional: for new line segmentation)
    }

QString outstring;
outstring = ui->lineEdit_2->text();
outstring.chop(4);
if(!(ui->lineEdit_2->text().isEmpty()))
    {
         QFile csvFile(outstring+"_2.csv");
         if(csvFile.open( QIODevice::WriteOnly ))
         {
                QTextStream savestream(&csvFile);
                savestream << textData;
             }
             // Закрываем файл - готово
             csvFile.close();
    }
}

void MainWindow::on_progressBar_valueChanged(int value)
{

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(ui->lineEdit_2->text().isEmpty())
    {
        ui->lineEdit_2->setText(arg1);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0: separator = ",";
        qDebug()<< "0 ,";
        break;
    case 1: separator = ".";
         qDebug()<< "1 .";
        break;
    case 2: separator = ";";
         qDebug()<< "2 ;";
        break;
    }
}
