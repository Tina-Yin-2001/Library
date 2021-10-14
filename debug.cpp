#include "debug.h"
#include "ui_debug.h"


deBug::deBug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deBug) {
    ui->setupUi(this);

    showinfo = new show_stuinfo(this);
    showinfo->hide();
}

deBug::~deBug() {
    delete ui;
}

void deBug::on_pushButton_clicked() {
    showinfo->open();
}
