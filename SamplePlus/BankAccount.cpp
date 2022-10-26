#include <vector>
#include <algorithm>
#include <format>
#include <sstream>


using namespace std;

class BankAccount
{
public:
	typedef void(*AccountStateHandler)(string message);

	BankAccount(int sum = 0) {
		this->sum = sum;
	}

	void registerHandler(AccountStateHandler handler) {
		handlers.push_back(handler);
	}

	void unregisterHandler(AccountStateHandler handler) {
        /*auto i = handlers.begin();

        while(i != handlers.end()) {        
			if (handler == *i) {
				handlers.erase(i);
                break;
			}  
            i++;
		}*/
        handlers.erase(remove_if(handlers.begin(), handlers.end(), [handler](auto i) {
            return handler == *i;
        }), handlers.end());
	}

    int currentSum()
    {
       return sum;
    }

    void put(int sum)
    {
        this->sum += sum;
    }

    void withdraw(int sum)
    {
        if (sum <= this->sum)
        {
            this->sum -= sum;

            ostringstream stream;
            stream << "Сумма " << sum << " снята со счета";
            string str = stream.str();

            if (!handlers.empty())
                for_each(handlers.begin(), handlers.end(), [str](auto i) { i(str); });
        }
        else
        {
            if (!handlers.empty())
                for_each(handlers.begin(), handlers.end(), [](auto i) { i("Недостаточно денег на счете"); });
        }
    }


private:
	vector<AccountStateHandler> handlers;
	int sum;

};

