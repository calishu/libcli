#pragma once

#include <format>
#include <stdexcept>
#include <string>
#include <vector>

#include "libcli/options.hpp"

namespace LibCLI {

class App {
    std::string_view app_desc;

    std::vector<LibCLI::FlagObject> flags;
    std::vector<LibCLI::OptionObject> options;

    // only allowed if the classes/structs contains a public `name_` variable
    template <typename T>
    [[nodiscard]] auto has_unique_name(const std::string_view name, const std::vector<T> &list) const -> bool {
        for (const auto &item : list)
            if (item.name_ == name) return false;
        return true;
    }

public:
    App(std::string_view description)
        : app_desc(description) {};

    auto create_flag(std::string_view name, std::string_view description, void (*callback)() = nullptr)
        -> LibCLI::FlagObject {
        const auto object = LibCLI::FlagObject{name, description, callback};

        if (!has_unique_name(name, flags)) throw std::runtime_error{std::format("The flag `{}` already exists.", name)};

        flags.emplace_back(object);
        return object;
    }
};

}; // namespace LibCLI
