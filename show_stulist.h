#ifndef SHOW_STULIST_H
#define SHOW_STULIST_H

#include <QDialog>

namespace Ui {
class show_stulist;
}

class show_stulist : public QDialog {
    Q_OBJECT

  public:
    explicit show_stulist(QWidget *parent = 0);
    ~show_stulist();
    void loadStuList();

  private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

  private:
    Ui::show_stulist *ui;
};

#endif // SHOW_STULIST_H
