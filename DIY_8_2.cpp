#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(const string& msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(const string& msg) override { cout << "[Console] " << msg << "\n"; }
};

class FileLogger : public Logger {
    ofstream out;
public:
    FileLogger(const string& fname) : out(fname) {}
    void write(const string& msg) override { out << "[File] " << msg << endl; }   // endl flushes
};

int main() {
    ConsoleLogger console;
    FileLogger file("log.txt");

    Logger* log = &console;            // start with console
    log->write("App started");

    log = &file;                       // switch at run time
    log->write("Saving data");
    log->write("Done");

    log = &console;                    // switch back
    log->write("Check log.txt for file entries");

    cout << "--- contents of log.txt ---\n";
    ifstream in("log.txt");
    string line;
    while (getline(in, line)) cout << line << "\n";
}