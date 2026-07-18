#include <array>
#include <iostream>
#include <optional>

std::optional<std::size_t> linear_search(const std::array<int, 5>& values, int target) {
    for (std::size_t index = 0; index < values.size(); ++index) {
        if (values[index] == target) {
            return index;
        }
    }
    return std::nullopt;
}

int main() {
    std::array<int, 5> values{12, 27, 31, 45, 58};

    std::cout << "Traversal: ";
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    const int target = 31;
    const std::optional<std::size_t> result = linear_search(values, target);

    if (result.has_value()) {
        std::cout << "Found " << target << " at index " << result.value() << '\n';
    } else {
        std::cout << target << " was not found\n";
    }

    return 0;
}