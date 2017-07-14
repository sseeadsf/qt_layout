#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMenuBar>
#include <QGroupBox>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QMessageBox>



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog();

private slots:
    void handle_btn();
private:
    void createMenu();
    void createGroupBox1();
    void createGroupBox2();

    QMenuBar *menu_bar;
    QGroupBox *box1;
    QGroupBox *box2;
    QTextEdit *text_big;
    QTextEdit *text_small;
    QLabel *label[4];
    QLineEdit *line[4];
    QPushButton *btn[3];
    QPushButton *btn_ok;
    QPushButton *btn_cancel;

    QMenu *menu;
    QAction *action;


};

#endif // DIALOG_H
