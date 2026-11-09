
template <typename T>
void Span::addRange( T begin, T end)
{
    std::size_t distance = std::distance(begin, end);

    if (_vec.size() + distance > _limit)
        throw FullException();
    _vec.insert(_vec.end(), begin, end);
}
