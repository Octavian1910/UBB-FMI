#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;

class Widget
{
public:
    virtual void tipareste() = 0; //TE OBLIGA SA IMPLEMENTEZI TU
};

class List:public Widget
{
public:
    void tipareste()override
    {
        cout << "List\n";
    }
};

class Button:public Widget
{
protected:
    string text;
public:
    Button(string t):text{t}{};
    virtual void tipareste()
    {
        cout << "Button(" << text << ")\n";
    }
};

class Window
{
    vector<Widget*> btns;

public:
    Window():public Widget{}
    void addButton(Button* btn)
    {
        btns.push_back(btn);
    }

    void tipareste()override
    {
        ceContine();
    }

    void ceContine()
    {
        for (Button* b : btns)
        {
            b->tipareste();
        }
    }
};

class ToggleButton:public Button
{
    bool selected;
public:
    ToggleButton(string t, bool s):Button{t},selected{s}{};
    void tipareste() override
    {
        cout << "ToggleButton(" << text << "," << selected << ")\n";
    }
};


int main()
{
    Button btn1{"1"};
    ToggleButton btn2{"3",false};
    Button btn3 = btn2; // slicing
    List * lst = new List{};
    btn1.tipareste();
    btn2.tipareste();

    Window wnd;


    wnd.addButton(btn1);
    wnd.addButton(btn2); // slicing aici
    wnd.addButton(lst); // slicing aici

    cout << "\nContinut Window:\n";
    wnd.ceContine();

    Window wnd2;
    wnd.addButton(new List);
    wnd.addButton(new List);
    wnd.addButton(wnd2);

    wnd.ceContine();
}


/*PT POLIMORFIM NE TREBUIE:
 *1)MOSTENIRE
 *2)SUPRASCRIERE METODA
 *3)POINTER SAU REFERINTA(FARA SLICING)
 *4)DECLARAM VIRTUAL
 **/