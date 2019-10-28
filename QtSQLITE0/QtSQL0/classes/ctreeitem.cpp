/******************************************************************************
 Класс: cTreeItem
 Автор: Субботин А.С.
 Дата: 05.08.14
 Описание: описывает элемент иерархического дерева
 ******************************************************************************/
#include "ctreeitem.h"

//=============================================================================
// Конструктор
//=============================================================================
cTreeItem::cTreeItem(int x)
{
    this->Item = x;
    this->ChildrenTreeItem = new QTreeWidgetItem;
}//End of cTreeItem::cTreeItem()

//=============================================================================
// Методы
//=============================================================================

//
// Заполнение списка детей
//
bool cTreeItem::getChildren(cDataBase sdb)
{
    // Начальные значения локальных переменных
    bool x = false;
    this->ChildrenList.clear();
    int y;

    // Получение информации из базы данных
    x = sdb.db.open();
    if(x)
    {
        QString str = "SELECT subject FROM relationships WHERE object = ";
        str += QString::number(this->Item);
        str += " AND relation = 1;";

        QSqlQuery qSelect(str);
        while (qSelect.next())
        {
            y = qSelect.value(0).toInt();
            this->ChildrenList.append(y);// Присвоение элементу значения запроса
            QString Text = QString::number(y);
            QTreeWidgetItem* Item = new QTreeWidgetItem;
            Item->setText(0, Text);
            this->ChildrenTreeItem->addChild(Item);
        }
    }

    return x;
}//End of bool cTreeItem::getChildren()

//
// Чтение значения узла
//
int cTreeItem::getItem()
{
    return this->Item;
}
