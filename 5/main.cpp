#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <functional>
#include <stdexcept>

// ---------------- Interfaces ----------------

class INumberReader {
public:
    virtual ~INumberReader() = default;
    virtual std::vector<int> read() = 0;
};

class INumberFilter {
public:
    virtual ~INumberFilter() = default;
    virtual bool keep(int number) const = 0;
};

class INumberObserver {
public:
    virtual ~INumberObserver() = default;
    virtual void on_number(int number) = 0;
    virtual void on_finished() = 0;
};


// ---------------- Implementations ----------------

class FileNumberReader : public INumberReader {
    std::string filename_;
public:
    FileNumberReader(const std::string& filename) : filename_(filename) {}

    std::vector<int> read() override {
        std::ifstream ifs(filename_);
        if (!ifs.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename_);
        }

        std::vector<int> numbers;
        int num;
        while (ifs >> num) {
            numbers.push_back(num);
        }
        return numbers;
    }
};

class EvenFilter : public INumberFilter {
public:
    bool keep(int number) const override {
        return number % 2 == 0;
    }
};

class OddFilter : public INumberFilter {
public:
    bool keep(int number) const override {
        return number % 2 != 0;
    }
};

class GtFilter : public INumberFilter {
    int threshold_;
public:
    GtFilter(int threshold)
        : threshold_(threshold)
    {}
    bool keep(int number) const override {
        return number > threshold_;
    }
};

class PrintObserver : public INumberObserver {
public:
    void on_number(int number) override {
        std::cout << number << '\n';
    }
    void on_finished() override {
        // ¯\_(ツ)_/¯
    }
};

class CountObserver : public INumberObserver {
    int count_ = 0;
public:
    void on_number(int) override {
        ++count_;
    }
    void on_finished() override {
        std::cout << "Total numbers: " << count_ << '\n';
    }
};


// ---------------- Factory ----------------

class FilterFactoryRegistry {
    public:
        using Factory = std::function<std::unique_ptr<INumberFilter>(const std::string& arg)>;
    
        // Singleton access
        static FilterFactoryRegistry& instance() {
            static FilterFactoryRegistry reg;
            return reg;
        }
    
        // no copying
        FilterFactoryRegistry(const FilterFactoryRegistry&) = delete;
        FilterFactoryRegistry& operator=(const FilterFactoryRegistry&) = delete;
    
        // Register a factory under a key (e.g. "EVEN", "ODD", "GT")
        void register_factory(const std::string& key, Factory f) {
            registry_[key] = std::move(f);
        }
    
        // Create a filter by name, e.g. "EVEN", "ODD", or "GT5"
        std::unique_ptr<INumberFilter> create(const std::string& filterName) const {
            // exact match
            auto it = registry_.find(filterName);
            if (it != registry_.end()) {
                return it->second(filterName);
            }
            // prefix match (for GT<n>)
            for (auto& [key, factory] : registry_) {
                if (filterName.rfind(key, 0) == 0) {
                    return factory(filterName);
                }
            }
            throw std::invalid_argument("Unknown filter: " + filterName);
        }
    
    private:
        FilterFactoryRegistry() = default;
        std::map<std::string, Factory> registry_;
    };

// --------------- Processor ----------------

class NumberProcessor{
private:
    INumberReader& reader_;
    INumberFilter& filter_;
    std::vector<INumberObserver*> observers_;
public:
    NumberProcessor(INumberReader& reader, INumberFilter& filter, std::vector<INumberObserver*>& observers)
    : reader_(reader), filter_(filter), observers_(observers) {}

    void run()
    {
        std::vector<int> numbers = reader_.read();

        for(auto num : numbers){
            if (filter_.keep(num)) {
                for (auto* obs : observers_) 
                    obs->on_number(num);
            }
        }

        for (auto obs : observers_) {
            obs->on_finished();
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filter> <file>\n";
        return -1;
    }

    auto& registry = FilterFactoryRegistry::instance();
    registry.register_factory("EVEN",
        [](const std::string&) {
            return std::make_unique<EvenFilter>();
        });
    registry.register_factory("ODD",
        [](const std::string&) {
            return std::make_unique<OddFilter>();
        });
    registry.register_factory("GT",
        [](const std::string& arg) {
            int threshold = std::stoi(arg.substr(2));
            return std::make_unique<GtFilter>(threshold);
        });

    std::string filterArg = argv[1];
    std::string filename  = argv[2];

    FileNumberReader reader(filename);
    std::unique_ptr<INumberFilter> filter;
    try {
        filter = registry.create(filterArg);
    } catch (std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return -1;
    }

    PrintObserver printObs;
    CountObserver countObs;
    
    std::vector<INumberObserver*> observers = { &printObs, &countObs };
    try {
        NumberProcessor processor(reader, *filter, observers);
        processor.run();
    } catch (std::exception& ex) {
        std::cerr << "Processing error: " << ex.what() << "\n";
        return -1;
    }

    return 0;
}