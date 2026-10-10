//melodii2
#pragma once

#include <QAbstractTableModel>
#include "../service/Service.h"

class MyTableModel : public QAbstractTableModel
{
private:
    Service& srv;
    vector<Melodie> melodii;

public:
    MyTableModel(Service& srv,QObject* parent=nullptr):QAbstractTableModel(parent),srv{srv}
    {
        refresh();
    }

    void refresh()
    {
        beginResetModel();
        melodii=srv.sortArtist();
        endResetModel();
    }

    int rowCount(const QModelIndex& parent=QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return (int)melodii.size();
    }

    int columnCount(const QModelIndex& parent=QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return 6;
    }

    QVariant data(const QModelIndex& index,int role=Qt::DisplayRole) const override
    {
        if(!index.isValid())
            return {};

        if(role!=Qt::DisplayRole)
            return {};

        const Melodie& m=melodii[index.row()];

        switch(index.column())
        {
            case 0:return m.getId();
            case 1:return QString::fromStdString(m.getTitlu());
            case 2:return QString::fromStdString(m.getArtist());
            case 3:return QString::fromStdString(m.getGen());
            case 4:return srv.getNrArtist(m.getArtist());
            case 5:return srv.getNrGen(m.getGen());
            default:return {};
        }
    }

    Melodie getMelodie(int row)
    {
        return melodii[row];
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
                case 3:return "Gen";
                case 4:return "Nr Artist";
                case 5:return "Nr Gen";
                default:return {};
            }
        }

        return {};
    }
};