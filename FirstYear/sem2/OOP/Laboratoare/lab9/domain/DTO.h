//
// Created by octav on 08.05.2026.
//

#pragma once

#include <string>
#include <utility>

using std::string;

class ProducerDTO
{
private:
    /*
     * producer: producer name
     * count: number of medicines
     */
    string producer;
    int count;

public:
    /*
     * Creates a report DTO
     * :param producer: producer name
     * :param count: number of medicines
     */
    ProducerDTO(string  producer, int count): producer{std::move(producer)}, count{count} {}

    ProducerDTO() = default; // pt map

    /*
     * Gets the producer
     * :return: producer name
     */
    [[nodiscard]] const string& getProducer() const
    {
        return producer;
    }

    /*
     * Gets the number of medicines
     * :return: count
     */
    [[nodiscard]] int getCount() const
    {
        return count;
    }
};