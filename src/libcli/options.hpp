#pragma once

#include <string_view>

namespace LibCLI {

struct FlagObject {
    std::string_view name_;
    std::string_view description_;
    void (*cb)();

    constexpr FlagObject(std::string_view name, std::string_view description, void (*callback)() = nullptr)
        : name_(name),
          description_(description),
          cb(callback) {};
};

}; // namespace LibCLI
