namespace std { namespace ranges {

    template<InputIterator I, class T, class Proj = identity>
    requires IndirectRelation<
        ranges::equal_to<>,
        projected<I, Proj>,
        const T*>
    constexpr I
    find_backward(I first, I last, const T& value, Proj proj = {});

    template<InputRange R, class T, class Proj = identity>
    requires IndirectRelation<
        ranges::equal_to<>,
        projected<iterator_t<R>, Proj>,
        const T*>
    constexpr safe_iterator_t<R>
    find_backward(R&& r, const T& value, Proj proj = {});

    template<
        InputIterator I,
        class Proj = identity,
        IndirectUnaryPredicate<projected<I, Proj>> Pred>
    constexpr I find_if_backward(I first, I last, Pred pred, Proj proj = {});

    template<
        InputRange R,
        class Proj = identity,
        IndirectUnaryPredicate<projected<iterator_t<R>, Proj>> Pred>
    constexpr safe_iterator_t<R>
    find_if_backward(R&& r, Pred pred, Proj proj = {});

    template<
        InputIterator I,
        class Proj = identity,
        IndirectUnaryPredicate<projected<I, Proj>> Pred>
    constexpr I
    find_if_not_backward(I first, I last, Pred pred, Proj proj = {});

    template<
        InputRange R,
        class Proj = identity,
        IndirectUnaryPredicate<projected<iterator_t<R>, Proj>> Pred>
    constexpr safe_iterator_t<R>
    find_if_not_backward(R&& r, Pred pred, Proj proj = {});

}}
