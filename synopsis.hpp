namespace std {

template<typename BidirectionalIterator, typename T>
constexpr BidirectionalIterator find_backward(BidirectionalIterator first,
                                              BidirectionalIterator last,
                                              const T & value);

template<typename BidirectionalIterator, typename T>
constexpr BidirectionalIterator find_not_backward(BidirectionalIterator first,
                                                  BidirectionalIterator last,
                                                  const T & value);

template<typename BidirectionalIterator, typename Pred>
constexpr BidirectionalIterator find_if_backward(BidirectionalIterator first,
                                                 BidirectionalIterator last,
                                                 Pred p);

template<typename BidirectionalIterator, typename Pred>
constexpr BidirectionalIterator find_if_not_backward(BidirectionalIterator first,
                                                     BidirectionalIterator last,
                                                     Pred p);

template<typename InputIterator, typename T>        
constexpr InputIterator find_not(InputIterator first, InputIterator last, const T & value);

namespace ranges {

    template<BidirectionalRange Rng, class T, class Proj = identity>
    constexpr requires IndirectRelation<ranges::equal_to<>, projected<iterator_t<Rng>, Proj>, const T *>
    safe_iterator_t<Rng>
      find_backward(Rng && rng, const T & value, Proj proj = Proj{});

    template<BidirectionalRange Rng, class T, class Proj = identity>
    constexpr requires IndirectRelation<ranges::equal_to<>, projected<iterator_t<Rng>, Proj>, const T *>
    safe_iterator_t<Rng>
      find_not_backward(Rng && rng, const T & value, Proj proj = Proj{});

    template <InputRange Rng, class Proj = identity,
              IndirectUnaryPredicate<projected<iterator_t<Rng>, Proj>> Pred>
    constexpr safe_iterator_t<Rng>
      find_if_backward(Rng&& rng, Pred pred, Proj proj = Proj{});

    template <InputRange Rng, class Proj = identity,
              IndirectUnaryPredicate<projected<iterator_t<Rng>, Proj>> Pred>
    constexpr safe_iterator_t<Rng>
      find_if_not_backward(Rng&& rng, Pred pred, Proj proj = Proj{});

    template<InputIterator I, Sentinel<I> S, class T, class Proj = identity>
    constexpr requires IndirectRelation<ranges::equal_to<>, projected<I, Proj>, const T *>
    I find_not(I first, S last, const T & value, Proj proj = Proj{});

    template<InputRange Rng, class T, class Proj = identity>
    constexpr requires IndirectRelation<ranges::equal_to<>, projected<iterator_t<Rng>, Proj>, const T *>
    safe_iterator_t<Rng>
      find(Rng && rng, const T & value, Proj proj = Proj{});

}

}
