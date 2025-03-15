#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

template<typename T1, typename T2>
void print_map(const map<T1, T2>& m) {
    std::stringstream ss;
    ss << "{";
    for (auto& it : m) {
        ss << it.first << ":" << it.second << ",";
    }
    ss << "}" << endl;
    cout << ss.str();
}

template<typename T1>
void print_vector2(const vector<vector<T1>>& ve2) {
    std::stringstream ss;
    for (const vector<T1>& ve: ve2) {
        for (auto& n: ve) {
            ss << n << ",";
        }
        ss << endl;
    }
    cout << ss.str();
}

void print_vector(const vector<int>& ve) {
    std::stringstream ss;
    for (int n : ve) {
        ss << n << ",";
    }
    ss << endl;
    cout << ss.str();
}

void print_vector(const std::string& pre, const vector<int>& ve) {
    std::stringstream ss;
    for (int n : ve) {
        ss << n << ",";
    }
    ss << endl;
    cout << pre << ss.str();
}

std::string vector2str(const vector<int>& ve) {
    std::stringstream ss;
    ss << "[";
    for (int n : ve) {
        ss << n << ",";
    }
    ss << "]";
    return ss.str();
}

bool isDigit(string& str) {
    try {
        size_t pos;
        stoi(str, &pos);
        return pos == str.size();
    }
    catch (const std::invalid_argument& e) {  
        return false;  
    } catch (const std::out_of_range& e) {  
        return false;  
    }  
    catch (const std::exception e) {
        return false;
    }
}