#include <string>
#include "option.h"
#define NMAX 10

class TabOption{
    private:
        Option tab[NMAX];
        int nb_options;
        int getOptionIndex(const std::string &opt) const;

    public:
        TabOption();
        void addOption(const Option &opt);
        void print() const;
        void setNbOptions(int nb);
        int getOptionId(const std::string &opt) const;
        bool optionHasArgument(const std::string &opt) const;
        Option::Type optionArgumentType(const std::string &opt) const;
};