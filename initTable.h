#ifndef INITTABLE_H
#define INITTABLE_H

#pragma once
#include <iostream>
#include <string>
#include <map>


namespace join_query
{
    struct result_table
    {
        std::string to_string() const;

        std::map<int, std::pair<std::string, std::string>> data;
    };

    class initTable
    {
    public:
        static result_table intersection(const initTable&left, const initTable& right) noexcept;

        static result_table symmetric_difference(const initTable&left, const initTable& right) noexcept;

        bool insert(int id, const std::string& name) noexcept;

        void truncate() noexcept;
    private:
        std::map<int, std::string> data;
    };
}


#endif // INITTABLE_H
