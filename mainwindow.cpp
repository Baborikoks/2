#include "mainwindow.h"
#include "ui_mainwindow.h"

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

QString MainWindow::base64_encode(const QString& input) {
    static const QString base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    QString output;
    int val = 0, valb = -6;
    for (QChar c : input) {
        val = (val << 8) + c.toLatin1();
        valb += 8;
        while (valb >= 0) {
            output.append(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) output.append(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    while (output.size() % 4) output.append('=');
    return output;
}

QString MainWindow::caesar_cipher(const QString& input, int shift) {
    QString output;
    for (QChar c : input) {
        if (c.isLetter()) {
            QChar base = c.isUpper() ? 'A' : 'a';
            output.append(QChar(((c.toLatin1() - base.toLatin1() + shift) % 26) + base.toLatin1()));
        } else {
            output.append(c);
        }
    }
    return output;
}

void MainWindow::on_SHcomboBox_activated(int index)
{
    if (index == 0) {
        ui->spinBox->setEnabled(false);
    } else {
        ui->spinBox->setEnabled(true);
    }
}



void MainWindow::on_OKpushButton_clicked()
{
    QString input = ui->TEXTVVODlineEdit->text();
    int shift = ui->spinBox->value();

    if (ui->SHcomboBox->currentIndex() == 0) {
        ui->VVODlabel->setText(base64_encode(input));
    } else {
        ui->VVODlabel->setText(caesar_cipher(input, shift));
    }

    for (int value = 1; value <= 100; value++){
        ui->progressBar->setValue(value);
    }
}


