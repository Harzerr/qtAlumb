
#ifndef PICANIMATIONWID_H
#define PICANIMATIONWID_H
#include <QWidget>
#include <QTreeWidgetItem>


class PicAnimationWid : public QWidget
{
    Q_OBJECT
public:
    explicit PicAnimationWid(QWidget *parent = nullptr);
    ~PicAnimationWid();
    void SetPixmap(QTreeWidgetItem* item);
    void Start();
    void Stop();
    void SlideNext();
    void SlidePre();
private:

    float _factor;
    QTimer* _timer;
    QPixmap _pixmap1;
    QPixmap _pixmap2;
    QTreeWidgetItem* _cur_item;
    QMap<QString, QTreeWidgetItem*> _map_items;
    bool _b_start;
    void UpSelectPixmap(QTreeWidgetItem* item);
public slots:
    void SlotUpdateSelectShow(QString path);
    void SlotUpdateStartOrStop();
private slots:
    void TimeOunt();
signals:
    void SigUpdatePreList(QTreeWidgetItem*);
    void SigSelectItem(QTreeWidgetItem*);
    void SigStart();
    void SigStop();
    void SigStartMusic();
    void SigStopMusic();
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // PICANIMATIONWID_H
