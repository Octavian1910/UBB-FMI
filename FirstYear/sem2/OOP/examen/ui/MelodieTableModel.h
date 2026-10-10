#pragma once

#include <QAbstractTableModel>

#include "../service/MelodieService.h"

class MelodieTableModel : public QAbstractTableModel
{
private:
    MelodieService& serv;

public:
    MelodieTableModel(MelodieService& serv,QObject* parent=nullptr):QAbstractTableModel(parent),serv(serv){}

    int rowCount(const QModelIndex& parent=QModelIndex()) const override
    {
        return (int)serv.getAllSorted().size();
    }

    int columnCount(const QModelIndex& parent=QModelIndex()) const override
    {
        return 5;
    }

    QVariant data(const QModelIndex& index,int role=Qt::DisplayRole) const override
    {
        if(!index.isValid())
            return {};

        if(role!=Qt::DisplayRole)
            return {};

        const auto& m=serv.getAllSorted().at(index.row());

        switch(index.column())
        {
            case 0:return QString::number(m.get_ID());
            case 1:return QString::fromStdString(m.get_title());
            case 2:return QString::fromStdString(m.get_artist());
            case 3:return QString::number(m.get_rank());
            case 4:return QString::number(serv.countRank(m.get_rank()));
            default:return {};
        }
    }

    QVariant headerData(int section,Qt::Orientation orientation,int role=Qt::DisplayRole) const override
    {
        if(role!=Qt::DisplayRole)
            return {};

        if(orientation==Qt::Horizontal)
        {
            switch(section)
            {
                case 0:return "Id";
                case 1:return "Titlu";
                case 2:return "Artist";
                case 3:return "Rank";
                case 4:return "Nr Rank";
                default:return {};
            }
        }

        return {};
    }

    void refresh()
    {
        beginResetModel();
        endResetModel();
    }


};