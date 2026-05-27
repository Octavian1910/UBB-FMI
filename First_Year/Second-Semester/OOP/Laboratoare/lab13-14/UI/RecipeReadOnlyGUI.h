#pragma once

#include <QWidget>
#include <QPainter>
#include <cstdlib>

#include "../service/MedService.h"
#include "../service/Observer.h"

class RecipeReadOnlyGUI : public QWidget, public Observer
{
private:
    /*
     * serv: service reference
     */
    MedService& serv;

public:
    /*
     * Creates recipe read-only GUI
     * :param serv: service reference
     */
    RecipeReadOnlyGUI(MedService& serv) : serv(serv)
    {
        serv.addObserver(this);
        setWindowTitle("Recipe ReadOnly");
        resize(500, 400);
    }

    /*
     * Updates window when recipe changes
     */
    void update() override
    {
        repaint();
    }

    /*
     * Paints one circle for each medicine from recipe
     */
    void paintEvent(QPaintEvent* event) override
    {
        QPainter p{this};

        int nr = serv.getRecipeSize();

        for (int i = 0; i < nr; ++i)
        {
            int x = rand() % width();
            int y = rand() % height();

            p.drawEllipse(x, y, 30, 30);
        }
    }

    /*
     * Destructor
     */
    ~RecipeReadOnlyGUI()
    {
        serv.removeObserver(this);
    }
};