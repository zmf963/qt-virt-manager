#ifndef VIRT_ENTITY_CONTROL_H
#define VIRT_ENTITY_CONTROL_H

#include <QMainWindow>
#include <QTreeView>
#include <QSettings>
#include <QTime>
#include <QUrl>
#include <QDesktopServices>
#include <QDebug>
#include "virt_objects/virt_entity_config.h"

class VirtEntityControl : public QMainWindow
{
    Q_OBJECT
public:
    explicit VirtEntityControl(QWidget *parent = 0);
    virtual ~VirtEntityControl();
    QString                  currConnName;
    QSettings                settings;
    QTreeView               *entityList = NULL;
    virConnect              *currWorkConnection = NULL;

    virtual void             reloadState();
    virtual void             changeDockVisibility();
    virtual void             entityClicked(const QPoint&);
    virtual void             entityDoubleClicked(const QModelIndex&);
    virtual void             execAction(const QStringList&);
    virtual void             newVirtEntityFromXML(const QStringList&);
    virtual void             doneEntityCreationDialog();

signals:
    void                     entityMsg(QString&);
    void                     addNewTask(TASK);

public slots:
    void                     msgRepeater(QString&);
    virtual bool             getThreadState() const;
    virtual void             stopProcessing();
    virtual bool             setCurrentWorkConnect(virConnect*);
    virtual void             setListHeader(QString&);
    virtual void             resultReceiver(Result);
};

#endif // VIRT_ENTITY_CONTROL_H
