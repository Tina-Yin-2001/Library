#ifndef SHOW_STUINFO_H
#define SHOW_STUINFO_H
#include "student.h"
#include <QDialog>
#include <utils.h>

using namespace student;
namespace Ui {
class show_stuinfo;
}

class show_stuinfo : public QDialog {
    Q_OBJECT

  public:
    explicit show_stuinfo(QWidget *parent = nullptr);
    ~show_stuinfo();

    void show(vector<Student*>stuList);


  private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();


  private:
    Ui::show_stuinfo *ui;
};

#endif // SHOW_STUINFO_H
