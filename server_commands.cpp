#include "server_commands.h"


template<size_t INDEX>
std::string join_query::insert_command<INDEX>::perform(handler_t &server) const
{
    return server.insert<INDEX>(key, value);
}

//--------------------------------------------------------------------------------------
template<size_t INDEX>
std::string join_query::truncate_command<INDEX>::perform(handler_t &server) const
{
    return server.truncate<INDEX>();
}

//--------------------------------------------------------------------------------------
template<size_t I1, size_t I2>
std::string join_query::symmetric_difference_command<I1, I2>::perform(handler_t &server) const
{
    return server.symmetric_difference<I1, I2>();
}

//--------------------------------------------------------------------------------------
template<size_t I1, size_t I2>
std::string join_query::intersection_command<I1, I2>::perform(handler_t &server) const
{
    return server.intersection<I1, I2>();
}

//--------------------------------------------------------------------------------------
//std::unique_ptr<join_query::abstract_command> join_query::abstract_command::CreateCommand(const std::string &strCmd)
//{
//    auto pos_cmd_end = strCmd.find(' ');
//    std::string cmd = strCmd.substr(0, pos_cmd_end);
//    if (std::string::npos == pos_cmd_end)
//    {
//        if ("INTERSECTION" == cmd)
//        {
//            return std::unique_ptr<abstract_command>(new intersection_command<0, 1>());
//        }
//        if ("SYMMETRIC_DIFFERENCE" == cmd)
//        {
//            return std::unique_ptr<abstract_command>(new symmetric_difference_command<0, 1>());
//        }
//    }
//    else
//    {
//        auto pos_table_end = strCmd.find(' ', pos_cmd_end + 1);
//        std::string table = strCmd.substr(pos_cmd_end + 1, pos_table_end - pos_cmd_end - 1);
//        if (std::string::npos == pos_table_end)
//        {
//            if ("TRUNCATE" == cmd)
//            {
//                if ("A" == table)
//                {
//                    return std::unique_ptr<abstract_command>(new truncate_command<0>());
//                }
//                if ("B" == table)
//                {
//                    return std::unique_ptr<abstract_command>(new truncate_command<1>());
//                }
//            }
//        }
//        else
//        {
//            if ("INSERT" == cmd)
//            {
//                auto pos_key_end = strCmd.find(' ', pos_table_end + 1);
//                if (std::string::npos != pos_key_end)
//                {
//                    int key = std::stoi(strCmd.substr(pos_table_end + 1, pos_key_end - pos_table_end - 1));
//                    std::string val = strCmd.substr(pos_key_end + 1);
//                    if ("A" == table)
//                    {
//                        return std::unique_ptr<abstract_command>(new insert_command<0>(key, val));
//                    }
//                    if ("B" == table)
//                    {
//                        return std::unique_ptr<abstract_command>(new insert_command<1>(key, val));
//                    }
//                }
//            }
//        }
//    }

//    return nullptr;
//}
