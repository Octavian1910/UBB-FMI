#pragma once
#include <QAbstractTableModel>
#include "../domain/Medicine.h"
#include <vector>

using std::vector;

class RecipeTableModel : public QAbstractTableModel
{
private:
    /*
     * meds: recipe medicines
     */
    vector<const Medicine*> meds;

public:
    /*
     * Creates recipe table model
     * :param meds: recipe medicines
     */
    RecipeTableModel(const vector<const Medicine*>& meds) : meds{meds} {}

    /*
     * Gets number of rows
     * :return: number of medicines from recipe
     */
    int rowCount(const QModelIndex& parent) const override
    {
        return static_cast<int>(meds.size());
    }

    /*
     * Gets number of columns
     * :return: number of table columns
     */
    int columnCount(const QModelIndex& parent) const override
    {
        return 4;
    }

    /*
     * Gets data for a table cell
     * :param index: cell position
     * :param role: display role
     * :return: cell value
     */
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (role == Qt::DisplayRole)
        {
            const Medicine* med = meds[index.row()];

            if (index.column() == 0)
                return QString::fromStdString(med->get_name());

            if (index.column() == 1)
                return QString::number(med->get_price());

            if (index.column() == 2)
                return QString::fromStdString(med->get_producer());

            if (index.column() == 3)
                return QString::fromStdString(med->get_active_substance());
        }

        return QVariant();
    }

    /*
     * Gets header data
     * :param section: column index
     * :param orientation: header orientation
     * :param role: display role
     * :return: header text
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override
    {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            if (section == 0) return "Name";
            if (section == 1) return "Price";
            if (section == 2) return "Producer";
            if (section == 3) return "Substance";
        }

        return QVariant();
    }

    /*
     * Sets new medicines and resets model
     * :param newMeds: new recipe medicines
     */
    void setMeds(const vector<const Medicine*>& newMeds)
    {
        beginResetModel();
        meds = newMeds;
        endResetModel();
    }
};