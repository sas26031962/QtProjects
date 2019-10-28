/******************************************************************************
 �����: cTreeItem
 �����: �������� �.�.
 ����: 05.08.14
 ��������: ��������� ������� �������������� ������
 ******************************************************************************/
#include "ctreeitem.h"

//=============================================================================
// �����������
//=============================================================================
cTreeItem::cTreeItem(int x)
{
    this->Item = x;
    this->ChildrenTreeItem = new QTreeWidgetItem;
}//End of cTreeItem::cTreeItem()

//=============================================================================
// ������
//=============================================================================

//
// ���������� ������ �����
//
bool cTreeItem::getChildren(cDataBase sdb)
{
    // ��������� �������� ��������� ����������
    bool x = false;
    this->ChildrenList.clear();
    int y;

    // ��������� ���������� �� ���� ������
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
            this->ChildrenList.append(y);// ���������� �������� �������� �������
            QString Text = QString::number(y);
            QTreeWidgetItem* Item = new QTreeWidgetItem;
            Item->setText(0, Text);
            this->ChildrenTreeItem->addChild(Item);
        }
    }

    return x;
}//End of bool cTreeItem::getChildren()

//
// ������ �������� ����
//
int cTreeItem::getItem()
{
    return this->Item;
}
