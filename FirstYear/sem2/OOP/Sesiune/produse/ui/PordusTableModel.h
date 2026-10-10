//produse table
#pragma once

#include <QAbstractTableModel>
#include <QBrush>

#include "../service/Service.h"

class ProdusTableModel : public QAbstractTableModel
{
private:
    Service& serv;
    int pretMaxim = 50;

public:
    ProdusTableModel(Service& serv) : serv{serv} {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        return static_cast<int>(serv.getAllSorted().size());
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override
    {
        return 5;
    }

    QVariant data(const QModelIndex& index,int role = Qt::DisplayRole) const override
    {
        if(!index.isValid())
            return QVariant();

        auto produse = serv.getAllSorted();

        const auto& p = produse[index.row()];

        if(role == Qt::DisplayRole)
        {
            switch(index.column())
            {
                case 0:
                    return p.getId();

                case 1:
                    return QString::fromStdString(p.getNume());

                case 2:
                    return QString::fromStdString(p.getTip());

                case 3:
                    return p.getPret();

                case 4:
                    return serv.nrVocale(p.getNume());
            }
        }

        if(role == Qt::BackgroundRole)
        {
            if(p.getPret() <= pretMaxim)
                return QBrush(Qt::red);
        }

        return QVariant();
    }

    QVariant headerData(int section,Qt::Orientation orientation,int role) const override
    {
        if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0: return "ID";
                case 1: return "Nume";
                case 2: return "Tip";
                case 3: return "Pret";
                case 4: return "Nr vocale";
            }
        }

        return QVariant();
    }

    void setPretMaxim(int pret)
    {
        pretMaxim = pret;
        refresh();
    }

    void refresh()
    {
        beginResetModel();
        endResetModel();
    }
};