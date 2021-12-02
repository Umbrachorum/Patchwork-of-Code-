//
// Created by umbra on 10/06/2021.
//

#include "trade.hpp"

#include <memory>


int action(data &d) {
    if(strcmp(d.reads[1].c_str(), "order") == 0) {

        unsigned long atm = d.vals.size() - 2;
        int buy = count_best_rate_buy(d);
        int sale = count_best_rate_sale(d);
        std::cerr << "buy = "<< buy << std::endl;
        std::cerr << "sale = "<< sale << std::endl;
        int state = 0;
        if((buy == 1 && d._user->btc_q > 0.01 && sale == 0 ) || ((d.vals[atm].BTC_ETH.hight * 0.95) < d.ms[atm].m_btc_eth.hight && d.ms.size() >= 9 && d._user->btc_q > 0.01)) {
            long double tmp =  ((d._user->eth_q) / d.vals[atm].BTC_ETH.hight);
            if(tmp > 0){
                state = 1;
                std::cout << "buy BTC_ETH " << std::setprecision(12) << tmp  << std::endl;
            }
        }
        if((buy == 2 && d._user->usdt_q > 0.01 && sale == 0) || ((d.vals[atm].USDT_BTC.hight * 0.95) < d.ms[atm].m_usdt_btc.hight && d.ms.size() >= 9 && d._user->usdt_q > 0.01)) {
            long double tmp =  ((d._user->usdt_q) / d.vals[atm].USDT_BTC.hight);
            if(tmp > 0) {
                state = 1;
                std::cout << "buy USDT_BTC " << std::setprecision(12) << tmp << std::endl;
            }
        }
        if((buy == 3 && d._user->usdt_q > 0.01 && sale == 0 ) || ((d.vals[atm].USDT_ETH.hight * 0.95) < d.ms[atm].m_usdt_eth.hight && d.ms.size() >= 9 && d._user->usdt_q > 0.01))  {
            long double tmp =  ((d._user->usdt_q) / d.vals[atm].USDT_ETH.hight);
            if(tmp > 0){
                state = 1;
                std::cout << "buy USDT_ETH " << std::setprecision(12) << ((d._user->usdt_q) / d.vals[atm].USDT_ETH.hight) << std::endl;
            }
        }
        if(sale == 1 && d._user->eth_q > 0.01 && buy == 0) {
            state = 1;
            std::cout << "sell BTC_ETH "<< std::setprecision(12)  << d._user->eth_q  << std::endl;
        }
        if(sale == 2 && d._user->eth_q > 0.01 && buy == 0) {
            state = 1;
            std::cout << "sell USDT_ETH "<< std::setprecision(12)  << d._user->eth_q << std::endl;
        }
        if(sale == 3 && d._user->btc_q > 0.01 && buy == 0) {
            state = 1;
            std::cout << "sell USDT_BTC "<< std::setprecision(12)  << d._user->btc_q << std::endl;
        }
        if(state == 0)
            std::cout << "pass" << std::endl;
    }
    return OK;
}

int count_best_rate_sale(data &d)
{
    unsigned long tmp = d.vals.size() - 2;
    double tmp_1 = d.vals[tmp].BTC_ETH.hight / d.ms[tmp].m_btc_eth.hight;
    double tmp_2 = d.vals[tmp].USDT_BTC.hight / d.ms[tmp].m_usdt_btc.hight;
    double tmp_3 = d.vals[tmp].USDT_ETH.hight / d.ms[tmp].m_usdt_eth.hight;

    if(tmp_1 > 1.20 && tmp_1 > tmp_2 && tmp_1 > tmp_3)
        return 1;
    if(tmp_2 > 1.20 && tmp_2 > tmp_1 && tmp_2 > tmp_3)
        return 2;
    if(tmp_3 > 1.20 && tmp_3 > tmp_1 && tmp_3 > tmp_2)
        return 3;
    return 0;
}

int count_best_rate_buy(data &d)
{
    unsigned long tmp = d.vals.size() - 2;
    double tmp_1 = d.vals[tmp].BTC_ETH.hight / d.ms[tmp].m_btc_eth.hight;
    double tmp_2 = d.vals[tmp].USDT_BTC.hight / d.ms[tmp].m_usdt_btc.hight;
    double tmp_3 = d.vals[tmp].USDT_ETH.hight / d.ms[tmp].m_usdt_eth.hight;

    if(tmp_1 < 0.92 && tmp_1 < tmp_2 && tmp_1 < tmp_3)
        return 1;
    if(tmp_2 < 0.92 && tmp_2 < tmp_1 && tmp_2 < tmp_3)
        return 2;
    if(tmp_3 < 0.92 && tmp_3 < tmp_1 && tmp_3 < tmp_2)
        return 3;
    return 0;
}




int set(data &d) {
    char arr[10][30] = {"player_names", "your_bot", "timebank", "time_per_move", "candle_interval", "candle_format", "candles_total", "candles_given", "initial_stack", "transaction_fee_percent"};
    int i = 0;
    int (*ptr_func[10])(data&) = {&player_f, &bot_f, &timebank_f, &move_f, &interval_f, &candle_f, &total_f, &given_f, &init_f, &fee_f};
    if(!d.reads.empty()) {
        while(i < 10) {
            if(strcmp(d.reads[1].c_str(), arr[i]) == OK) {
                if(ptr_func[i](d) == FAIL)
                    return FAIL;
                else
                    return OK;
            }
            i++;
        }
    }
    return 84;
}

int stacks(data &d) {
    char arr[3][5] = {"BTC", "ETH", "USDT"};
    int (*ptr_func[3])(data&, std::vector<std::string>) = {&btc_w, &eth_w, &usdt_w};
    if(strcmp(d.reads[2].c_str(), "stacks") == 0) {
        int x = 0;
        int i = 0;
        std::vector<std::string> tmp;
        std::vector<std::string> line;
        tmp = split(d.reads[3], ",", tmp);
        while(i < 3) {
            line = split(tmp[i], ":", line);
            while (x < 3) {
                if(strcmp(line[0].c_str(), arr[x]) == 0){
                    ptr_func[x](d, line);
                }
                x++;
            }
            line.clear();
            i++;
            x = 0;
        }
        tmp.clear();
    }
    return OK;
}

int upgrade(data &d) {
    int i = 0;
    int x = 0;
    char arr[3][10] = { "BTC_ETH", "USDT_BTC" ,"USDT_ETH"};
    std::vector<std::string> tmp;
    std::vector<std::string> line;
    int (*ptr_func[3])(data&, std::vector<std::string>) = {&btc_eth_f, &btc_f, &eth_f};
    val v{{}, {}, {}};
    d.vals.push_back(v);
   if(strcmp(d.reads[2].c_str(), "next_candles") == 0) {
       line = split(d.reads[3], ";", line);
       while(i < 3) {
           tmp = split(line[i], ",", tmp);
           while(x < 3) {
               if(strcmp(tmp[0].c_str(), arr[x]) == 0) {
                   ptr_func[x](d, tmp);
               }
               x++;
           }
           tmp.clear();
           x = 0;
           i++;
       }
       line.clear();
   }
    stacks(d);
    return OK;
}

int trader::core() {
    std::string line;
    this->d = std::make_unique<data> ();
    this->d->_user = std::make_unique<user> ();
    int status = -1;
    int (*func_ptr[4])(data&) = {&set, &upgrade, &action, nullptr};
    while(std::getline(std::cin, line)) {
        if(line.data() != nullptr) {
            this->d->reads = split(line, " ", this->d->reads);
            status = command_handler();
        }
        if(status == EXIT) {
            return OK;
        }
        if(status != FAIL) {
            if(func_ptr[status](*(this->d)) == FAIL)
                return FAIL;
            if(!this->d->reads.empty()) {
                this->d->reads.clear();
                this->d->cmd.clear();
            }
            if(this->d->vals.size() >= 30) {
                this->d->vals.erase(this->d->vals.begin());
            }
            if(this->d->ms.size() >= 30) {
                average();
                this->d->ms.erase(this->d->ms.begin());
            }
            line.clear();
            status = -1;
        }
        average();
    }
    return OK;
}

int trader::command_handler() {
    if(strcmp(this->d->reads[0].c_str(), "settings") == OK)
        return SET;
    if(strcmp(this->d->reads[0].c_str(), "update") == OK)
        return UP;
    if(strcmp(this->d->reads[0].c_str(), "action") == OK)
        return AC;
    if(strcmp(this->d->reads[0].c_str(), "EXIT") == OK)
        return EXIT;
    return FAIL;
}

void trader::print_struct() {
    unsigned long idx = 0;
    if(this->d->vals.size() != 0) {
        while(idx < this->d->vals.size()) {
            std::cerr << "value from line " << idx <<  " idx: " << idx << std::endl;
            std::cerr << "BTC_ETH :" << std::endl;
            std::cerr << this->d->vals[idx].BTC_ETH.date << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].BTC_ETH.hight << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].BTC_ETH.low << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].BTC_ETH.open << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].BTC_ETH.close << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].BTC_ETH.volume << std::endl;
            std::cerr << "USDT_ETH :" << std::endl;
            std::cerr << this->d->vals[idx].USDT_ETH.date << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_ETH.hight << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_ETH.low << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_ETH.open << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_ETH.close << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_ETH.volume << std::endl;
            std::cerr << "USDT_BTC :" << std::endl;
            std::cerr << this->d->vals[idx].BTC_ETH.date << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_BTC.hight << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_BTC.low << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_BTC.open << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_BTC.close << std::endl;
            std::cerr << std::setprecision(16) << this->d->vals[idx].USDT_BTC.volume << std::endl;
            idx++;
        }
    }
}

void trader::print_user()
{
    if(this->d->_user != nullptr)
    {
        unsigned long idx = 0;
        if(!this->d->_user->candle_format.empty()){
            while(idx < this->d->_user->candle_format.size()){
                std::cout << this->d->_user->candle_format[idx] << std::endl;
                idx++;
            }
        }
        std::cout<< this->d->_user->transaction_fee << std::endl;
        std::cout<< this->d->_user->initial_stack << std::endl;
        std::cout<< this->d->_user->candle_given << std::endl;
        std::cout<< this->d->_user->candle_total << std::endl;
        std::cout<< this->d->_user->candle_interval << std::endl;
        std::cout<< this->d->_user->time_per_move << std::endl;
        std::cout<< this->d->_user->timebank << std::endl;
        std::cout<< this->d->_user->bot << std::endl;

    }
}

void trader::average() {
    unsigned long idx = 0;
    double sum  = 0.00000000000000;
    if(!this->d->vals.empty()) {

        this->d->ms.push_back(m{{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0}});
        int atm_idx = this->d->ms.size() - 1;
        while (idx < this->d->vals.size()) {
            this->d->ms[atm_idx].m_btc_eth.volume = this->d->ms[atm_idx].m_btc_eth.volume + this->d->vals[idx].BTC_ETH.volume;
            this->d->ms[atm_idx].m_btc_eth.open = this->d->ms[atm_idx].m_btc_eth.open + this->d->vals[idx].BTC_ETH.open;
            this->d->ms[atm_idx].m_btc_eth.close = this->d->ms[atm_idx].m_btc_eth.close + this->d->vals[idx].BTC_ETH.close;
            this->d->ms[atm_idx].m_btc_eth.hight = this->d->ms[atm_idx].m_btc_eth.hight + this->d->vals[idx].BTC_ETH.hight;
            this->d->ms[atm_idx].m_btc_eth.low = this->d->ms[atm_idx].m_btc_eth.low + this->d->vals[idx].BTC_ETH.low;

            this->d->ms[atm_idx].m_usdt_btc.volume = this->d->ms[atm_idx].m_usdt_btc.volume + this->d->vals[idx].USDT_BTC.volume;
            this->d->ms[atm_idx].m_usdt_btc.open = this->d->ms[atm_idx].m_usdt_btc.open + this->d->vals[idx].USDT_BTC.open;
            this->d->ms[atm_idx].m_usdt_btc.close = this->d->ms[atm_idx].m_usdt_btc.close + this->d->vals[idx].USDT_BTC.close;
            this->d->ms[atm_idx].m_usdt_btc.hight = this->d->ms[atm_idx].m_usdt_btc.hight + this->d->vals[idx].USDT_BTC.hight;
            this->d->ms[atm_idx].m_usdt_btc.low = this->d->ms[atm_idx].m_usdt_btc.low + this->d->vals[idx].USDT_BTC.low;

            this->d->ms[atm_idx].m_usdt_eth.volume = this->d->ms[atm_idx].m_usdt_eth.volume + this->d->vals[idx].USDT_ETH.volume;
            this->d->ms[atm_idx].m_usdt_eth.open = this->d->ms[atm_idx].m_usdt_eth.open + this->d->vals[idx].USDT_ETH.open;
            this->d->ms[atm_idx].m_usdt_eth.close = this->d->ms[atm_idx].m_usdt_eth.close + this->d->vals[idx].USDT_ETH.close;
            this->d->ms[atm_idx].m_usdt_eth.hight = this->d->ms[atm_idx].m_usdt_eth.hight + this->d->vals[idx].USDT_ETH.hight;
            this->d->ms[atm_idx].m_usdt_eth.low = this->d->ms[atm_idx].m_usdt_eth.low + this->d->vals[idx].USDT_ETH.low;
            if(idx == this->d->vals.size() - 1) {
                this->d->ms[atm_idx].m_usdt_eth.date = this->d->vals[idx].USDT_ETH.date;
                this->d->ms[atm_idx].m_btc_eth.low =  this->d->vals[idx].BTC_ETH.date;
                this->d->ms[atm_idx].m_usdt_btc.volume =  this->d->vals[idx].USDT_BTC.date;
            }
            idx++;
            sum = sum + 1.00000000000000;
        }
        this->d->ms[atm_idx].m_btc_eth.volume = this->d->ms[atm_idx].m_btc_eth.volume / sum;
        this->d->ms[atm_idx].m_btc_eth.open = this->d->ms[atm_idx].m_btc_eth.open / sum;
        this->d->ms[atm_idx].m_btc_eth.close = this->d->ms[atm_idx].m_btc_eth.close / sum;
        this->d->ms[atm_idx].m_btc_eth.hight = this->d->ms[atm_idx].m_btc_eth.hight / sum;
        this->d->ms[atm_idx].m_btc_eth.low = this->d->ms[atm_idx].m_btc_eth.low / sum;

        this->d->ms[atm_idx].m_usdt_btc.volume = this->d->ms[atm_idx].m_usdt_btc.volume / sum;
        this->d->ms[atm_idx].m_usdt_btc.open = this->d->ms[atm_idx].m_usdt_btc.open / sum ;
        this->d->ms[atm_idx].m_usdt_btc.close = this->d->ms[atm_idx].m_usdt_btc.close / sum;
        this->d->ms[atm_idx].m_usdt_btc.hight = this->d->ms[atm_idx].m_usdt_btc.hight / sum;
        this->d->ms[atm_idx].m_usdt_btc.low = this->d->ms[atm_idx].m_usdt_btc.low / sum;

        this->d->ms[atm_idx].m_usdt_eth.volume = this->d->ms[atm_idx].m_usdt_eth.volume / sum;
        this->d->ms[atm_idx].m_usdt_eth.open = this->d->ms[atm_idx].m_usdt_eth.open / sum;
        this->d->ms[atm_idx].m_usdt_eth.close = this->d->ms[atm_idx].m_usdt_eth.close / sum;
        this->d->ms[atm_idx].m_usdt_eth.hight = this->d->ms[atm_idx].m_usdt_eth.hight / sum;
        this->d->ms[atm_idx].m_usdt_eth.low = this->d->ms[atm_idx].m_usdt_eth.low / sum;
    }

}

void trader::print_m() {
    if(!this->d->vals.empty() && this->d->vals.size() >= 2) {
        int atm_idx = this->d->ms.size() - 1;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_btc_eth.volume << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_btc_eth.open << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_btc_eth.close << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_btc_eth.hight << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_btc_eth.low << std::endl;

        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_btc.volume << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_btc.open << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_btc.close << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_btc.hight << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_btc.low << std::endl;

        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_eth.volume << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_eth.open << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_eth.close << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_eth.hight << std::endl;
        std::cout << std::setprecision(16) << this->d->ms[atm_idx].m_usdt_eth.low << std::endl;
    }
}

template<typename T>
std::vector<T> split(std::string str, std::string delim, std::vector<T> vec) {
    char *cpy;
    char *dup = strdup(str.c_str());
    cpy = strtok(dup, delim.c_str());
    while(cpy) {
        vec.push_back(cpy);
        cpy = strtok(nullptr, delim.c_str());
    }
    free(cpy);
    free(dup);
    return vec;
}

