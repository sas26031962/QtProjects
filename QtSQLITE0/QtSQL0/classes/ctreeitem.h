/******************************************************************************
 Класс: cTreeItem
 Автор: Субботин А.С.
 Дата: 05.08.14
 Описание: описывает элемент иерархического дерева
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
// Конструктор
//=============================================================================
    cTreeItem(int x);

//=============================================================================
// Методы
//=============================================================================
    bool getChildren(cDataBase sdb);
    int getItem();

};//End of class cTreeItem

#endif // CTREEITEM_H
