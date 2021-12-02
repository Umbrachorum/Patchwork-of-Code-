//
// Created by umbra on 11/06/2021.
//

#include "../include/trade.hpp"

int check_int(std::string str)
{
    long unsigned int idx = 0;
    int sum = 0;
    while(idx < str.size()) {
        if(!isdigit(str[idx])) {
            return -1;
        }
        if(str.size() > 1) {
            sum = (sum * 10) + (str[idx] - '0');
        }
        else
            sum = str[idx]  - '0';
        idx++;
    }
    return sum;
}

int player_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->name = d.reads[2];
    return OK;
}

int bot_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->bot = d.reads[2];
    return OK;
}

int timebank_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->timebank = check_int(d.reads[2].c_str());
    return OK;
}

int move_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->time_per_move = check_int(d.reads[2].c_str());
    return OK;
}

int interval_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->candle_interval = check_int(d.reads[2].c_str());
    return OK;
}

int candle_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    unsigned long i  = 2;
    while(i < d.reads.size()) {
        d._user->candle_format.push_back(d.reads[i]);
        i++;
    }
    return OK;
}

int total_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->candle_total = check_int(d.reads[2].c_str());
    return OK;
}

int given_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->candle_given = check_int(d.reads[2].c_str());
    return OK;
}

int init_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->initial_stack = check_int(d.reads[2].c_str());
    return OK;
}

int fee_f(data &d)
{
    if(d.reads.empty())
        return FAIL;
    d._user->transaction_fee = std::stof(const_cast<char *>(d.reads[2].c_str()));
    return OK;
}

int btc_f(data& d, std::vector<std::string> vec)
{
    unsigned long tmp = d.vals.size() - 1;
    d.vals[tmp].USDT_BTC.date = check_int(vec[1]);
    d.vals[tmp].USDT_BTC.hight =  std::stod(vec[2]);
    d.vals[tmp].USDT_BTC.low =  std::stod(vec[3]);
    d.vals[tmp].USDT_BTC.open =  std::stod(vec[4]);
    d.vals[tmp].USDT_BTC.close =  std::stod(vec[5]);
    d.vals[tmp].USDT_BTC.volume =  std::stod(vec[6]);
    return 0;
}

int eth_f(data& d, std::vector<std::string> vec)
{
    unsigned long tmp = d.vals.size() - 1;
    d.vals[tmp].USDT_ETH.date =  check_int(vec[1]);
    d.vals[tmp].USDT_ETH.hight =  std::stod(vec[2]);
    d.vals[tmp].USDT_ETH.low =  std::stod(vec[3]);
    d.vals[tmp].USDT_ETH.open =  std::stod(vec[4]);
    d.vals[tmp].USDT_ETH.close =  std::stod(vec[5]);
    d.vals[tmp].USDT_ETH.volume =  std::stod(vec[6]);
    return 0;
}

int btc_eth_f(data& d, std::vector<std::string> vec)
{
    unsigned long tmp = d.vals.size() - 1;
    d.vals[tmp].BTC_ETH.date =  check_int(vec[1]);
    d.vals[tmp].BTC_ETH.hight =  std::stod(vec[2]);
    d.vals[tmp].BTC_ETH.low =  std::stod(vec[3]);
    d.vals[tmp].BTC_ETH.open =  std::stod(vec[4]);
    d.vals[tmp].BTC_ETH.close =  std::stod(vec[5]);
    d.vals[tmp].BTC_ETH.volume =  std::stod(vec[6]);
    return 0;
}

int usdt_w(data& d, std::vector<std::string> vec)
{
    d._user->usdt_q =  std::stold(vec[1]);
    if(d._user->usdt_q > 0)
        d._user->usdt_q =  (std::stold(vec[1]) * (1 - d._user->transaction_fee) * (0.00000001/0.00000001));
    return 0;
}

int eth_w(data& d, std::vector<std::string> vec)
{
    d._user->eth_q = std::stold(vec[1]);
    if(d._user->usdt_q > 0)
        d._user->usdt_q =  (std::stold(vec[1]) * (1 - d._user->transaction_fee));
    return 0;
}

int btc_w(data& d, std::vector<std::string> vec)
{
    d._user->btc_q = std::stold(vec[1]);
    if(d._user->usdt_q > 0)
        d._user->usdt_q =  (std::stold(vec[1]) * (1 - d._user->transaction_fee));
    return 0;
}
