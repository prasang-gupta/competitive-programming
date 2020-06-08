// Enter your code for reversed_binary_value<bool...>()
template <typename = void>
int reversed_binary_value() {
    return 0;
}

template <bool bit, bool...bits>
int reversed_binary_value() {
    return (reversed_binary_value<bits...>() << 1) + bit;
} 