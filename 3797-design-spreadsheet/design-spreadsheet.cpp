#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    explicit Spreadsheet(int rows = 0) {
        spreadsheet.reserve(rows > 0 ? rows * 2 : 16);
    }

    void setCell(const string& cell, int value) {
        spreadsheet[cell] = value;
    }

    void resetCell(const string& cell) {
        spreadsheet.erase(cell);
    }

    int getValue(const string& formula) {
        int result = 0;
        size_t start = 1;
        while (start < formula.size()) {
            size_t pos = formula.find('+', start);
            if (pos == string::npos) pos = formula.size();
            string_view token(formula.data() + start, pos - start);
            result += getToken(token);
            start = pos + 1;
        }
        return result;
    }

private:
    unordered_map<string, int> spreadsheet;

    int getToken(string_view token) const {
        if (isdigit(token[0]) || 
           (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            return stoi(string(token));
        }
        auto it = spreadsheet.find(string(token));
        return (it != spreadsheet.end()) ? it->second : 0;
    }
};
