#pragma once
//Сделал: Ошлаков Данил, ИВТ-22
#include "ListLegacy.h"
#include <cassert>

template<typename T>
class QueueLegacy {
public:
    //--------------------------------------------------------------------КОНСТРУКТОРЫ И ОПЕРАТОРЫ ИЗ ПРАВИЛА ПЯТИ------------------------------------------------------
    // Конструктор по умолчанию.
    QueueLegacy() : list() {}

    // Конструктор, заполняющий очередь n элементами с значением value.
    QueueLegacy(size_t n, const T& value) : list(n, value) {}

    // Конструктор копирования.
    QueueLegacy(const QueueLegacy& other) : list(other.list) {}

    // Конструктор перемещения.
    QueueLegacy(QueueLegacy&& other) : list(move(other.list)) {}

    // Оператор присваивания копированием.
    QueueLegacy& operator=(const QueueLegacy& other) {
        if (this == &other) {
            return *this;
        }

        list = other.list;

        return *this;
    }

    // Оператор присваивания перемещением.
    QueueLegacy& operator=(QueueLegacy&& other) {
        if (this == &other) {
            return *this;
        }

        list = move(other.list);

        return *this;
    }

    // Конструктор, который создает очередь из инициализатора. (QueueLegacy<size_t> numbers{ 1, 2, 3, 4, 5 };)
    QueueLegacy(initializer_list<T> list) : list(list) {}

    // Деструктор.
    ~QueueLegacy() {}

    //----------------------------------------------------------------ВСТАВКИ И УДАЛЕНИЯ-----------------------------------------------------------------------------------------------------
    // Добавляет элемент в конец очереди.
    void push(const T& data) {
        list.push_back(data);
    }

    // Удаляет первый элемент из очереди.
    T pop() {
        if (!list.is_empty()) {
            list.pop_front();
        }
        return T();
    }

    // Возвращает первый элемент очереди.
    T front() const {
        if (!list.is_empty()) {
            return list.first();
        }
        return T();
    }

    // Возвращает последний элемент очереди.
    T back() const {
        if (!list.is_empty()) {
            return list.last();
        }
        return T();
    }

    // Возвращает true, если очередь пуста, иначе false.
    bool is_empty() const {
        return list.is_empty();
    }

    // Возвращает размер очереди.
    size_t size() const {
        return list.size();
    }

    // Очищает очередь.
    void clear() {
        list.clear();
    }

    //--------------------------------------------------------------------------------------------------Прочее
    // Возвращает строковое представление очереди.
    string to_string() const {
        return list.to_string();
    }

    // Выводит очередь в стандартный вывод.
    void print() const {
        cout << to_string() << endl;
    }

    //--------------------------------------------------------------------------------------------------------------------------------------
    //Проверка на равенство очередей
    bool operator==(const QueueLegacy<T>& other) const {
        return list == other.list;
    }
    //Проверка на неравенство очередей
    bool operator!=(const QueueLegacy<T>& other) const {
        return list != other.list;
    }
private:
    ListLegacy<T> list;
};

void test() {
    // Создаем очередь.
    QueueLegacy<int> q;

    // Проверяем, что очередь пуста.
    assert(q.is_empty());
    // Удаляем элементы из очереди.
    assert(q.pop() == 0);

    // Добавляем элементы в очередь.
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Проверяем, что очередь не пуста.
    assert(!q.is_empty());

    // Проверяем размер очереди.
    assert(q.size() == 5);

    // Проверяем первый элемент очереди.
    assert(q.front() == 1);

    // Проверяем последний элемент очереди.
    assert(q.back() == 5);

    // Удаляем элементы из очереди.
    q.pop();
    q.pop();

    // Проверяем, что размер очереди уменьшился.
    assert(q.size() == 3);

    // Проверяем первый элемент очереди.
    assert(q.front() == 3);

    // Проверяем последний элемент очереди.
    assert(q.back() == 5);

    // Вставляем элемент в очередь.
    q.push(6);

    // Проверяем, что размер очереди увеличился.
    assert(q.size() == 4);

    // Проверяем первый элемент очереди.
    assert(q.front() == 3);

    // Проверяем последний элемент очереди.
    assert(q.back() == 6);

    // Очищаем очередь.
    q.clear();

    // Проверяем, что очередь пуста.
    assert(q.is_empty());

    // Проверяем размер очереди.
    assert(q.size() == 0);

    // Проверяем первый элемент очереди.
    assert(q.front() == 0);

    // Проверяем последний элемент очереди.
    assert(q.back() == 0);


    // Создаем очередь из инициализатора.
    QueueLegacy<int> q2 = { 1, 2, 3, 4, 5 };

    // Проверяем, что очередь не пуста.
    assert(!q2.is_empty());

    // Проверяем размер очереди.
    assert(q2.size() == 5);

    // Проверяем первый элемент очереди.
    assert(q2.front() == 1);

    // Проверяем последний элемент очереди.
    assert(q2.back() == 5);

    // Копируем очередь.
    QueueLegacy<int> q3 = q2;

    // Проверяем, что скопированная очередь не пуста.
    assert(!q3.is_empty());

    // Проверяем размер скопированной очереди.
    assert(q3.size() == 5);

    // Проверяем первый элемент скопированной очереди.
    assert(q3.front() == 1);

    // Проверяем последний элемент скопированной очереди.
    assert(q3.back() == 5);

    // Перемещаем очередь.
    QueueLegacy<int> q4 = move(q2);

    // Проверяем, что перемещенная очередь не пуста.
    assert(!q4.is_empty());

    // Проверяем размер перемещенной очереди.
    assert(q4.size() == 5);

    // Проверяем первый элемент перемещенной очереди.
    assert(q4.front() == 1);

    // Проверяем последний элемент перемещенной очереди.
    assert(q4.back() == 5);

    // Проверяем, что исходная очередь пуста после перемещения.
    assert(q2.is_empty());

    // Проверяем, что перемещенная очередь равна скопированной очереди.
    assert(q4 == q3);

    // Проверяем, что перемещенная очередь не равна исходной очереди.
    assert(q4 != q2);
}