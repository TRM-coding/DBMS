#ifndef ans_hpp
#define ans_hpp
#include<string>
#include<vector>
class Ans{
    private:
    std::string state;
    std::vector<std::vector<std::string>>data;
    public:
        Ans()=default;
        ~Ans()=default;
        void Loaddata(std::vector<std::vector<std::string>>data)
        {
            this->data=data;
        }
        void Loadstate(std::string state)
        {
            this->state=state;
        }
        std::vector<std::vector<std::string>> getdata()
        {
            return this->data;
        }
        std::string getstate()
        {
            return this->state;
        }
};
#endif