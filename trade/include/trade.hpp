//
// Created by gyann on 4/17/21.
//

#ifndef B_CNA_410_BDX_4_1_GROUNDHOG_GEOFFROY_YANN_GROUNDHOG_HPP
#define B_CNA_410_BDX_4_1_GROUNDHOG_GEOFFROY_YANN_GROUNDHOG_HPP

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <string>
#include <string_view>
#include <cmath>


enum pourcent {
    MIN_BUY = 99, MIN_SALE = 111, LOW = 90, CYCLE = 80
};

enum cmd {SET = 0, UP = 1, AC = 2};
enum state {OK = 0, FAIL = 84, EXIT = 200};

struct user {
    std::string name;
    std::string bot;
    int timebank;
    int time_per_move;
    int candle_interval;
    std::vector<std::string>  candle_format;
    int candle_total;
    int candle_given;
    int initial_stack;
    float transaction_fee;
    long double btc_q;
    long double eth_q;
    long double usdt_q;
};

struct val {
     struct UTC_BTC {
        int date;
        double hight;
        double low;
        double open;
        double close;
        double volume;
    }BTC_ETH;

     struct USDT_ETH {
        int date;
        double hight;
        double low;
        double open;
        double close;
        double volume;
    }USDT_BTC;

     struct BSD_ETH {
        int date;
        double hight;
        double low;
        double open;
        double close;
        double volume;
    }USDT_ETH;
};

 struct m {
     struct m_btc {
         int date;
         double hight;
         double low;
         double open;
         double close;
         double volume;
    }m_btc_eth;

     struct m_usd {
         int date;
         double hight;
         double low;
         double open;
         double close;
         double volume;
    }m_usdt_btc;

     struct m_usdt {
         int date;
         double hight;
         double low;
         double open;
         double close;
         double volume;
    }m_usdt_eth;
};

struct data {
    std::vector<val> vals;
    std::vector<m> ms;
    std::vector<std::string> reads;
    std::string cmd;
    std::unique_ptr<user> _user;
};


class trader
{
public:
  trader() = default;
  ~trader() = default;
  int command_handler();
  int core();
  void print_struct();
  void print_user();
  void print_m();
  void average();
private:
    std::unique_ptr<data> d;
};

template<typename T>
std::vector<T> split(std::string str, std::string delim, std::vector<T> vec);

int player_f(data &d);
int bot_f(data &d);
int timebank_f(data &d);
int interval_f(data &d);
int candle_f(data &d);
int total_f(data &d);
int given_f(data &d);
int init_f(data &d);
int move_f(data &d);
int fee_f(data &d);
int btc_eth_f(data& d, std::vector<std::string> vec);
int eth_f(data& d, std::vector<std::string> vec);
int btc_f(data& d, std::vector<std::string> vec);
int usdt_w(data& d, std::vector<std::string> vec);
int eth_w(data& d, std::vector<std::string> vec);
int btc_w(data& d, std::vector<std::string> vec);
int count_best_rate_sale(data &d);
int count_best_rate_buy(data &d);


#endif // B_CNA_410_BDX_4_1_GROUNDHOG_GEOFFROY_YANN_GROUNDHOG_HPP
