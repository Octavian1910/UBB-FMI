//
// Created by octav on 17.04.2026.
//

#ifndef LAB4_TEMPLATE_MEDICINE_H
#define LAB4_TEMPLATE_MEDICINE_H

#include <string>
#include <utility>
using std::string;


class Medicine
{
private:
    string name;
    int price{};
    string producer;
    string active_substance;
public:
    Medicine() = default;
    Medicine(string name,int price,string producer,string active_substance):name{std::move(name)},price{price},producer{std::move(producer)},active_substance{std::move(active_substance)}{}; //el oricum face copie atunci cand il primeste ca si parametru , si s ar face copie si cand zici move
    [[nodiscard]] const string& get_name() const;
    [[nodiscard]] int get_price() const;
    [[nodiscard]] const string& get_producer() const;
    [[nodiscard]] const string& get_active_substance() const;
    [[nodiscard]] string get_ID() const;

    void set_name(const string& new_name);
    void set_price(int new_price);
    void set_producer(const string& new_producer);
    void set_active_substance(const string& new_active_substance);
};


#endif //LAB4_TEMPLATE_MEDICINE_H