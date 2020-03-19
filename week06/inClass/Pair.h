template<typename T, typename V>
class Pair {
private:
    T key;
    V value;
public:
    Pair(T key, V value);
    T getKey() const;
    static Pair makePair(T key, V value);
};

template<typename T, typename V>
Pair<T, V>::Pair(T key, V value) {
    this->key = key;
    this->value = value;
}

template<typename T, typename V> 
T Pair<T, V>::getKey() const {
    return this->key;
}

template<typename T, typename V>
Pair<T, V> Pair<T, V>::makePair(T key, V value) {
    return Pair<T, V>(key, value);
}

