#include "fourth.hpp"
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [console | file | none]" << std::endl;
        return 1;
    }

    std::string arg = argv[1];
    SinkType type; 

    if (arg == "console") {
        type = SinkType::Console;
    } else if (arg == "file") {
        type = SinkType::File;
    } else if (arg == "none") {
        type = SinkType::Null;
    } else {
        std::cerr << "Unknown sink type: " << arg << std::endl;
        return 1;
    }

    Logger::instance().set_sink(type);
    Logger::instance().log("Test message 1");
    Logger::instance().log("Test message 2");
    Logger::instance().log("Test message 3");

    return 0;
}
