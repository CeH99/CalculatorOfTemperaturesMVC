#include <iostream>
#include <fstream>
#include <memory>
#include <string>

enum class SinkType { Console, File, Null };

struct LogSink {
    virtual void write(const std::string& msg) = 0;
    virtual ~LogSink() = default;
};

class ConsoleSink : public LogSink {
public:
    void write(const std::string& msg) override {
        std::cout << "Console " << msg << std::endl;
    }
};

class FileSink : public LogSink {
public:
    void write(const std::string& msg) override {
        std::ofstream file("app.log", std::ios::app);
        if (file) {
            file << "File " << msg << std::endl;
        }
    }
};

class NullSink : public LogSink {
public:
    void write(const std::string&) override {}
};

class Logger {
public:
    static Logger& instance() {
        static Logger logger;
        return logger;
    }

    void set_sink(SinkType type) {
        switch (type) {
            case SinkType::Console:
                sink_ = std::make_unique<ConsoleSink>();
                break;
            case SinkType::File:
                sink_ = std::make_unique<FileSink>();
                break;
            case SinkType::Null:
                sink_ = std::make_unique<NullSink>();
                break;
        }
    }

    void log(const std::string& msg) {
        if (sink_) sink_->write(msg);
    }

private:
    std::unique_ptr<LogSink> sink_;

    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
