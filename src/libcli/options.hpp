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

struct OptionObject {
    std::string_view name_;
    std::string_view description_;
    void (*cb)();

    bool is_parsed = false;
    bool expected_ = false;

    constexpr OptionObject(std::string_view name, std::string_view description, void (*callback)() = nullptr)
        : name_(name),
          description_(description),
          cb(callback) {};

    constexpr auto expected(bool state = true) -> void { expected_ = state; }
};

}; // namespace LibCLI
