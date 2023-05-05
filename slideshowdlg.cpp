#include "slideshowdlg.h"
#include "protreewidget.h"
#include "prelistwid.h"
#include "ui_slideshowdlg.h"

#include <QDebug>
SlideShowDlg::SlideShowDlg(QWidget *parent, QTreeWidgetItem *first_item, QTreeWidgetItem *last_item) :
    QDialog(parent),_first_item(first_item), _last_item(last_item),
    ui(new Ui::SlideShowDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    ui->slidepreBtn->SetIcons(":/icon/picture.png", ":/icon/computer.ico", ":/icon/picture.png");

    ui->slidenextBtn->SetIcons(":/icon/picture.png", ":/icon/computer.ico", ":/icon/picture.png");
    ui->closeBtn->SetIcons(":/icon/picture.png", ":/icon/computer.ico", ":/icon/picture.png");
    ui->playBtn->SetIcons(":/icon/picture.png", ":/icon/computer.ico", ":/icon/picture.png",
                          ":/icon/picture.png", ":/icon/computer.ico", ":/icon/picture.png");

    connect(ui->closeBtn, &QPushButton::clicked, this, &SlideShowDlg::close);
    connect(ui->slidenextBtn, &QPushButton::clicked,this, &SlideShowDlg::SlotSlideNext);
     connect(ui->slidepreBtn, &QPushButton::clicked,this, &SlideShowDlg::SlotSlidePre);
    auto * prelistWid = dynamic_cast<PreListwid*>(ui->preListWidget);
    connect(ui->picAnimation, &PicAnimationWid::SigUpdatePreList,prelistWid, &PreListwid::SlotUpdatePreList);
    connect(ui->picAnimation, &PicAnimationWid::SigSelectItem,prelistWid, &PreListwid::SlotUpdateSlect);
    connect(prelistWid, &PreListwid::SigUpdateSelectShow, ui->picAnimation, &PicAnimationWid::SlotUpdateSelectShow);

    connect(ui->playBtn, & PicStateBtn::clicked, ui->picAnimation, &PicAnimationWid::SlotUpdateStartOrStop);
    connect(ui->picAnimation, &PicAnimationWid::SigStart,ui->playBtn, &PicStateBtn::SlotStart );
    connect(ui->picAnimation, &PicAnimationWid::SigStop,ui->playBtn, &PicStateBtn::SlotStop);

    auto * _protree_widget = dynamic_cast<ProTreeWidget*>(parent);

    connect(ui->picAnimation,&PicAnimationWid::SigStartMusic, _protree_widget, &ProTreeWidget::SlotStartMusic);
    connect(ui->picAnimation,&PicAnimationWid::SigStopMusic, _protree_widget, &ProTreeWidget::SlotStopMusic);

    qDebug()<<"firt_item"<< _first_item;
    ui->picAnimation->SetPixmap(_first_item);

     ui->picAnimation->Start();
}

SlideShowDlg::~SlideShowDlg()
{
     delete ui;
}

void SlideShowDlg::SlotSlideNext()
{
     ui->picAnimation->SlideNext();

}

void SlideShowDlg::SlotSlidePre()
{
      ui->picAnimation->SlidePre();
}
