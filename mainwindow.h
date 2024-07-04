#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QChar>
//#include <QGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_SHcomboBox_activated(int index);

    void on_OKpushButton_clicked();


private:
    Ui::MainWindow *ui;
    QString base64_encode(const QString& input);
    QString caesar_cipher(const QString& input, int shift);
};
#endif // MAINWINDOW_H
