#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(){
    createMenu();
    createGroupBox1();
    createGroupBox2();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setMenuBar(menu_bar);
    mainLayout->addWidget(box2);
    setLayout(mainLayout);
    setWindowTitle(tr("This window"));
}

void Dialog::createMenu(){
    menu_bar = new QMenuBar;

    menu = new QMenu(tr("&File"), this);
    action = menu->addAction(tr("&Exit"));
    menu_bar->addMenu(menu);

    connect(action, SIGNAL(triggered()), this, SLOT(accept()));
}
void Dialog::createGroupBox1(){
    box1 = new QGroupBox(tr("&Box 1"));

    QHBoxLayout *boxx = new QHBoxLayout();
    for(int i=0;i<3;i++){
        btn[i] = new QPushButton(tr("&Button %1").arg(i+1));
        //btn[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        boxx->addWidget(btn[i]);
    }
    boxx->addStretch(1);
    box1->setFixedHeight(50);
    box1->setLayout(boxx);

}

void Dialog::createGroupBox2(){
    box2 = new QGroupBox(tr("Form box"));

    QGridLayout *layout = new QGridLayout;

    text_small = new QTextEdit;
    QPushButton *btn = new QPushButton(tr("&Btn"));
    layout->addWidget(text_small, 0, 0, 3, 3);
    layout->addWidget(btn, 0, 4);

    box2->setLayout(layout);

    connect(btn, SIGNAL(clicked()), this, SLOT(handle_btn()));
}

void Dialog::handle_btn(){
    QMessageBox *mess = new QMessageBox();

    mess->setWindowTitle(tr("&Pop-up"));
    QString value = text_small->toPlainText();
    mess->setText(value);
    mess->addButton(QMessageBox::Yes);

    mess->exec();
}

