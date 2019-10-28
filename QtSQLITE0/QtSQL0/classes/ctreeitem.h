/******************************************************************************
 �����: cTreeItem
 �����: �������� �.�.
 ����: 05.08.14
 ��������: ��������� ������� �������������� ������
 ******************************************************************************/
#ifndef CTREEITEM_H
#define CTREEITEM_H

#include <QList>
#include <QSqlQuery>
#include <QTreeWidgetItem>
#include "./classes/cDataBase.h"


class cTreeItem
{
    int Item;
public:
    QList<int> ChildrenList;
    QTreeWidgetItem* ChildrenTreeItem;
//=============================================================================
// �����������
//=============================================================================
    cTreeItem(int x);

//=============================================================================
// ������
//=============================================================================
    bool getChildren(cDataBase sdb);
    int getItem();

};//End of class cTreeItem

#endif // CTREEITEM_H
