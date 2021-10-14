#ifndef DEBUG_H
#define DEBUG_H

#include <QDialog>
#include "show_stuinfo.h"

namespace Ui {
class deBug;
}

class deBug : public QDialog {
    Q_OBJECT

  public:
    explicit deBug(QWidget *parent = 0);
    ~deBug();

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::deBug *ui;
    show_stuinfo *showinfo;
};

#endif // DEBUG_H
