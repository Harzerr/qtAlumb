
#ifndef PRELISTWID_H
#define PRELISTWID_H

#include <QListWidget>
#include <QTreeWidgetItem>


class PreListwid : public QListWidget
{
Q_OBJECT
private:
    QMap<QString, QListWidgetItem*> _set_items;
    void AddListItem(const QString &path);
    int _global;
    QPoint _pos_origin;
    int _last_index;
public:
    PreListwid(QWidget *parent = nullptr);
    virtual ~PreListwid();
public slots:
    void SlotUpdatePreList(QTreeWidgetItem* tree_item);
    void SlotUpdateSlect(QTreeWidgetItem* tree_item);
    void SlotItemPressed(QListWidgetItem * item);
signals:
    void SigUpdateSelectShow(QString path);
};

#endif // PRELISTWID_H
