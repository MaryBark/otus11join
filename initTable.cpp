#include "initTable.h"

std::string join_query::result_table::to_string() const
{
    std::string result;
    for (const auto& item : data)
    {
        result += std::to_string(item.first) + ',' +
                item.second.first + ',' +
                item.second.second + '\n';
    }
    return result;
}

join_query::result_table join_query::initTable::intersection(const initTable &left, const initTable &right) noexcept
{
    result_table result;
    auto il = left.data.begin();
    auto ir = right.data.begin();

    while (il != left.data.end() && ir != right.data.end())
    {
        if (il->first < ir->first)
            ++il;
        else if (ir->first < il->first)
            ++ir;
        else
        {
            result.data.insert(make_pair(il->first, make_pair(il->second, ir->second)));
            ++il;
            ++ir;
        }
    }
    return result;
}

join_query::result_table join_query::initTable::symmetric_difference(const initTable &left, const initTable &right) noexcept
{
    result_table result;

    auto il = left.data.begin();
    auto ir = right.data.begin();

    while (il != left.data.end() || ir != right.data.end())
    {
        if (ir == right.data.end() ||
                il != left.data.end() && il->first < ir->first)
        {
            result.data.insert(make_pair(il->first, make_pair(il->second, "")));
            ++il;
        }
        else if (il == left.data.end() ||
                 ir != right.data.end() && ir->first < il->first)
        {
            result.data.insert(make_pair(ir->first, make_pair("", ir->second)));
            ++ir;
        }
        else
        {
            ++il;
            ++ir;
        }
    }
    return result;
}

bool join_query::initTable::insert(int id, const std::string &name) noexcept
{
    return data.insert({ id, name }).second;
}

void join_query::initTable::truncate() noexcept
{
    data.clear();
}
