#include "cdatabase.h"

//=============================================================================
// �����������
//=============================================================================
cDataBase::cDataBase()
{
    //...
}

//=============================================================================
// ������������� ���� ������
//=============================================================================
void cDataBase::installDataBase(QString path)
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(path);
}

//=============================================================================
// ��������� ��������� ������������ ������
//=============================================================================
void cDataBase::Codec()
{
    QTextCodec* codec = QTextCodec::codecForName("cp1251");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
}

//=============================================================================
// ������ ������ ������
//=============================================================================
void cDataBase::getTableList()
{
    if(this->db.open())
    {
        //
        // ���������� ��������� ������ �������
        //
        QString table = "sqlite_master";
        this->Status.clear();

        //
        // ������������ �������
        //
        QString str = "";
        str += "SELECT ";
        str += "name";
        str += " FROM ";
        str += table;
        str += " WHERE ";
        str += "type = 'table'";
        str += "ORDER BY name";
        str += ";";

        //
        // ���������� �������
        //
        QSqlQuery qSelect(str);
        this->Tables.clear();
        while (qSelect.next())
        {
            this->Tables.append(qSelect.value(0).toString());
        }

        this->Status.append("table list is extracted");
        this->db.close();
    }
    else
    {
        this->Status.append("database not open");
    }

}//End of void cDataBase::getTableList()

//=============================================================================
// ������ ������ ����� �������
//=============================================================================
void cDataBase::getFieldList(QString table)
{
    if(this->db.open())
    {
        //
        // ������������ �������
        //
        QString str = "";
        str += "SELECT ";
        str += "*";
        str += " FROM ";
        str += table;
        str += ";";

        //
        // ���������� �������
        //
        QSqlQuery q(str);
        QSqlRecord rec = q.record();

        //Get fields list
        this->Fields.clear();
        for(int i=0; i < rec.count(); i++)
        {
            this->Fields.append(rec.fieldName(i));
        }

        //
        // �������� ����� ���������� �������
        //
        str = "field list from ";
        str += table;
        str += " is extracted";

        this->Status.append(str);
        this->db.close();
    }
    else
    {
        this->Status.append("database not open");
    }

}//End of void cDataBase::getFieldList()

//=============================================================================
// ������ ����� ������� � �������
//=============================================================================
int cDataBase::getRecordsCount(QString table)
{
    int Count = -1;//��������� �������� ����� �������

    if(this->db.open())
    {
        //
        // ������������ �������
        //
        QString str = "";
        str += "SELECT COUNT(*) AS ROWS FROM ";
        str += table;
        str += ";";

        QSqlQuery qSelect(str);
        bool ret = qSelect.next();
        if(ret)
        {
            Count = qSelect.value(0).toInt();
        }
        //
        // �������� ����� ���������� �������
        //
        QString msg = "Number or rows in = ";
        msg += table;
        msg += " is ";
        msg += QString::number(Count);

        this->Status.append(msg);
        this->db.close();
    }
    else
    {
        this->Status.append("database not open");
    }

    return Count;// ������� ����� �������

}//End of int cDataBase::getRecordsCount(QString table)

//=============================================================================
// ���������� ������ � ������� ���� ������
//=============================================================================
void cDataBase::updateTable(QString table)
{
    if(this->db.open())
    {

        //
        // ������������ �������
        //
        QString str = "";
        str += "UPDATE ";
        str += table;
        str += " SET ";

        for(int i = 1; i < this->Fields.count() - 1; i++)
        {
            str += this->Fields.at(i);
            str += " = '";
            str += this->Values.at(i);
            str += "', ";
        }
        str += this->Fields.at(this->Fields.count() - 1);
        str += " = '";
        str += this->Values.at(this->Fields.count() - 1);

        str += "' WHERE ";
        str += this->Fields.at(0);//"Id"
        str += " = ";
        str += this->Values.at(0);
         str += ";";

        //this->RequestLabel->setText(str);

        //
        // ���������� �������
        //
        QSqlQuery query;
        bool ret = query.exec(str);
        if(ret)
        {
            this->Status.append("record updated at Id = " + this->Values.at(0));
        }
        else
        {
            this->Status.append("request not executed");
        }
       this->db.close();
    }
    else
    {
        //Status set
        this->Status.append("database not open");
    }

}//End of void cDataBase::updateTable(QString name)



//=============================================================================
// ���������� ������ � ������� ���� ������
//=============================================================================
void cDataBase::insertRecordToTable(QString table)
{

    QString fields = "";
    for(int i = 0; i < this->Fields.count() - 1; i++)
    {
        fields += this->Fields.at(i);
        fields += ", ";
    }
    fields += this->Fields.at(this->Fields.count() - 1);

    QString values = "";
    values += "NULL, '";
    for(int i = 1; i < this->Fields.count() - 1; i++)
    {
        values += this->Values.at(i);
        values += "', '";
    }
    values += this->Values.at(this->Fields.count() - 1);
    values += "'";

    //
    // ������������ �������
    //
    QString str = "";
    str += "INSERT INTO ";
    str += table;
    str += "(";
    str += fields;
    str += ") ";
    str += "VALUES (";
    str += values;
    str += ");";

    //this->RequestLabel->setText(str);

    //
    // ���������� �������
    //
    if(this->db.open())
    {
        QSqlQuery query;
        bool ret = query.exec(str);
        if(ret)
        {
            int newId = query.lastInsertId().toInt();
            QString msg = "";
            msg += "record inserted last Id = ";
            msg += QString::number(newId);
            this->Status.append(msg);

            this->db.close();// ������� ���� ������

        }
        else
        {
            this->Status.append("record not inserted");
        }
    }
    else
    {
        this->Status.append("database not open");
    }
}//End of void cDataBase::insertRecordToTable(QString table)

//=============================================================================
// ������ ������� �� ������� ���� ������ � ������ �����
//-----------------------------------------------------------------------------
// ������� ���������:
// str - ������ SQL �������
// this->Fields - ������ ����� �������
// �������� ���������:
// this->Records - ������ �������
// this->Status - ������ ����������� �������
//=============================================================================
void cDataBase::selectRecordsToStringList(QString str)
{
    this->Status.clear();
    this->Records.clear();

    QString msg = "";
    if(this->db.open())
    {
        QSqlQuery qSelect(str);
        this->lRecords.clear();
        while (qSelect.next())
        {
            QSqlRecord rec = qSelect.record();
            this->Records.append(rec);
            QString str = "";
            this->Values.clear();
            this->Fields.clear();

            for(int i = 0; i < rec.count(); i++)
            {
                str += rec.fieldName(i);
                str += ": ";
                str += qSelect.value(i).toString();
                str += " ";

                this->Values.append(qSelect.value(i).toString());
                this->Fields.append(rec.fieldName(i));
            }

             this->lRecords.append(str);
        }
        this->db.close();// ������� ���� ������
        msg += "select ";
        msg += QString::number(this->Records.count());
        msg += " records";

        this->Status.append(msg);
    }
    else
    {
        msg += "database not open";
        this->Status.append(msg);
    }

}//End of void cDataBase::selectRecordsToStringList(QString str)

//=============================================================================
// �������� ��������� ��� ������� �� ������ ��� �����
//=============================================================================
void cDataBase::createHeaderFromFields()
{
    this->TableHeaderValue = "";
    for(int i = 0; i < this->Fields.count() - 1; i++)
    {
        this->TableHeaderValue += this->Fields.at(i);
        this->TableHeaderValue += ";";
    }
    this->TableHeaderValue += this->Fields.at(this->Fields.count() - 1);

}//End of void cDataBase::createHeaderFromFields()

//=============================================================================
// �������� ��������� ��� ������� �� ������ �������
//=============================================================================
void cDataBase::createHeaderFromRecords()
{
    this->TableHeaderValue = "";
    for(int i = 0; i < this->Records.at(0).count() - 1; i++)
    {
        this->TableHeaderValue += this->Records.at(0).fieldName(i);
        this->TableHeaderValue += ";";
    }
    this->TableHeaderValue += this->Records.at(0).fieldName(this->Records.at(0).count() - 1);

}//End of void cDataBase::createHeaderFromRecords()

//=============================================================================
// ��������� �������� ����� ����� ������ �� �������
//=============================================================================
void cDataBase::getCurrentRecord(QString table, int CurrentRow)
{
    //
    // ������������ �������
    //
    QString str = "";
    str += "SELECT ";
    str += "*";
    str += " FROM ";
    str += table;
    str += " WHERE ";
    str += "Id = ";
    str += QString::number(CurrentRow);
    str += ";";

    //
    // ���������� �������
    //
    this->Status.clear();// ������� ������ �������
    this->Values.clear();// ������� �������� �������
    this->Fields.clear();// ������� ����� �������

    if(this->db.open())
    {
        QSqlQuery qSelect(str);
        bool ret = qSelect.next();
        QSqlRecord rec = qSelect.record();
        QString msg = "row ";
        msg += QString::number(CurrentRow);

        if(ret)
        {
            for (int i = 0; i < rec.count(); i++)
            {
               this->Values.append(rec.value(i).toString());
               this->Fields.append(rec.fieldName(i));
            }
            msg += " is selected";
        }
        else
        {
            msg += " not selected";
        }
        // ����� ��������� � ������ �������
        this->Status.append(msg);
        // �������� ���� ������
        this->db.close();
    }
    else
    {
        this->Status.append("database not open");
    }

}//End of void cDataBase::getCurrentRecrod(int CurrentRow)

//=============================================================================
// �������������� ������ � ������ ��� ������������ ����������� � ������
//=============================================================================
void cDataBase::convertRecordToString(int row)
{
    for(int i = 1; i < this->Records.at(row).count() - 1; i++)
    {
        this->msg += this->Records.at(row).fieldName(i);
        this->msg += "=";
        this->msg += this->Records.at(row).value(i).toString();
        this->msg += ", ";
    }
    this->msg += this->Records.at(row).fieldName(this->Records.at(row).count() - 1);
    this->msg += "=";
    this->msg += this->Records.at(row).value(this->Records.at(row).count() - 1).toString();

}//End of void cDataBase::convertRecordToString(int row)



