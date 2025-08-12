#pragma once

#include <string_view>

namespace LibCLI {

struct FlagObject {
    std::string_view name_;
    std::string_view description_;
    void (*cb)();

    bool is_parsed = false;

    constexpr FlagObject(std::string_view name, std::string_view description, void (*callback)() = nullptr)
        : name_(name),
          description_(description),
          cb(callback) {};
};

class OptionObject {
    bool expected_ = false;

public:
    std::string_view name_;
    std::string *value; // you should assign a variable for receiving the input
    std::string_view description_;
    void (*cb)();

    bool is_parsed = false;

    constexpr OptionObject(
        std::string_view name, std::string_view description, std::string *value = nullptr, void (*callback)() = nullptr)
        : name_(name),
          description_(description),
          cb(callback) {};

    constexpr auto expected(bool state = true) -> void { expected_ = state; }
};

}; // namespace LibCLI
