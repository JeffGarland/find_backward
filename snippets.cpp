void raw_loop()
{
    while (it-- != first) {
        if (*it == x) {
            // Use it here...
        }
    }
}

void existing_algorithms_1()
{
    auto rfirst = std::make_reverse_iterator(it);
    auto rlast = std::make_reverse_iterator(first);
    auto it = std::find(rfirst, rlast, x);
    // Use it here...
}

void typical_find()
{
    auto it = std::find(it, last, x); // Includes examination of *it.
}

void typical_find_backward()
{
    auto it = std::find( // Skips *it entirely.
        std::make_reverse_iterator(first),
        std::make_reverse_iterator(it),
        x);
}

void existing_algorithms_2()
{
    auto it = std::find( // Includes *it again!
        std::make_reverse_iterator(first),
        std::make_reverse_iterator(std::next(it)),
        x);
}

void new_backward_algorithm_1()
{
    auto it = std::find_backward(first, it, x);
    // Use it here...
}

void new_backward_algorithm_2()
{
    // Search, but don't include *it.
    auto it_1 = std::find_backward(first, it, x);

    // Search, and include *it.
    auto it_2 = std::find_backward(first, stds::next(it), x);
}


void basic_find()
{
    std::vector<int> vec = {1, 1, 2};
    auto it = std::find(vec.begin(), vec.end(), 1);
}

void without_find_not()
{
    std::vector<int> vec = { 1, 1, 2 };
    auto it = std::find_if(vec.begin(), vec.end(), [](int i) { return i != 1; });
}

void find_not()
{
    std::vector<int> vec = { 1, 1, 2 };
    auto it = std::find_not(vec.begin(), vec.end(), 1);
}
