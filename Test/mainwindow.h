#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void newFile();
    void open();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString m_strBkName;
};

#endif // MAINWINDOW_H
