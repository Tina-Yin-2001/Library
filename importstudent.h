#ifndef IMPORTSTUDENT_H
#define IMPORTSTUDENT_H

#include <QDialog>

namespace Ui {
class importStudent;
}

class importStudent : public QDialog {
    Q_OBJECT

  public:
    explicit importStudent(QWidget *parent = 0);
    ~importStudent();

  private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

  private:
    Ui::importStudent *ui;
};

#endif // IMPORTSTUDENT_H
